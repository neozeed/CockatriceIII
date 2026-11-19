/*
 *  test_mdh10.cpp - host unit test for the Sony MDH-10 emulation (scsi_mdh10.cpp)
 *
 *  Not part of the emulator build. Build and run:
 *    g++ -O2 -o test_mdh10 test_mdh10.cpp ../scsi_mdh10.cpp
 *    ./test_mdh10 <copy-of-formatted-image.img> <workdir> <mddata_d1.bin> <mddata_d4_00.bin>
 *    ./test_mdh10 --replay <image> [model]     (see test_mdh10_replay.py)
 *  The image is modified (a write round trip at the end of the disc) and its
 *  .utoc sidecar may be created; always pass a scratch copy.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

#include "../scsi_mdh10.h"

static int failures = 0, checks = 0;

#define CHECK(cond, ...) do { checks++; if (!(cond)) { failures++; printf("FAIL %s:%d: ", __FILE__, __LINE__); printf(__VA_ARGS__); printf("\n"); } } while (0)

struct Result {
	uint8_t status;
	std::vector<uint8_t> data;
};

static Result cmd(MDH10Device *d, std::vector<uint8_t> cdb, const std::vector<uint8_t> &out = std::vector<uint8_t>())
{
	const uint8_t *in;
	uint32_t in_len;
	Result r;
	r.status = mdh10_command(d, cdb.data(), (int)cdb.size(), out.empty() ? NULL : out.data(), (uint32_t)out.size(), &in, &in_len);
	r.data.assign(in, in + in_len);
	return r;
}

static std::vector<uint8_t> sense(MDH10Device *d)
{
	return cmd(d, {0x03, 0, 0, 0, 18, 0}).data;
}

static bool sense_is(MDH10Device *d, int key, int asc, int ascq)
{
	std::vector<uint8_t> s = sense(d);
	return s.size() == 18 && s[2] == key && s[12] == asc && s[13] == ascq;
}

static std::vector<uint8_t> hex(const char *h)
{
	std::vector<uint8_t> v;
	unsigned x;
	while (sscanf(h, "%2x", &x) == 1) {
		v.push_back((uint8_t)x);
		h += 2;
		while (*h == ' ')
			h++;
	}
	return v;
}

static std::vector<uint8_t> load(const char *p)
{
	std::vector<uint8_t> v;
	FILE *f = fopen(p, "rb");
	if (!f)
		return v;
	int c;
	while ((c = fgetc(f)) != EOF)
		v.push_back((uint8_t)c);
	fclose(f);
	return v;
}

static uint64_t fake_now = 0;
static uint64_t fake_clock(void) { return fake_now; }

static std::vector<uint8_t> cdb10(uint8_t op, uint32_t lba, uint16_t len, uint8_t b1 = 0, uint8_t ctl = 0)
{
	return {op, b1, (uint8_t)(lba >> 24), (uint8_t)(lba >> 16), (uint8_t)(lba >> 8), (uint8_t)lba, 0, (uint8_t)(len >> 8), (uint8_t)len, ctl};
}

/*
 * Replay mode, driven by test_mdh10_replay.py:
 *   stdin  : one command per line  "<cdb hex>|<data-out hex or empty>"
 *   stdout : one result per line   "<status>|<data-in hex>|<autosense hex>"
 * The fake clock advances 10 ms per command so FORMAT UNIT (IMMED) completes.
 */
static int replay(const char *image, const char *model)
{
	mdh10_set_clock(fake_clock);
	MDH10Device *d = mdh10_open(image, model);
	if (!d)
		return 1;
	char line[65536];
	while (fgets(line, sizeof(line), stdin)) {
		char *bar = strchr(line, '|');
		if (!bar)
			continue;
		*bar = 0;
		std::vector<uint8_t> c = hex(line), o = hex(bar + 1);
		fake_now += 10;
		Result r = cmd(d, c, o);
		printf("%02x|", r.status);
		for (uint8_t b : r.data)
			printf("%02x", b);
		printf("|");
		if (r.status == 2)
			for (uint8_t b : sense(d))
				printf("%02x", b);
		printf("\n");
		fflush(stdout);
	}
	mdh10_close(d);
	return 0;
}

int main(int argc, char **argv)
{
	if (argc >= 3 && strcmp(argv[1], "--replay") == 0)
		return replay(argv[2], argc > 3 ? argv[3] : NULL);
	if (argc != 5) {
		fprintf(stderr, "usage: %s image workdir mddata_d1.bin mddata_d4_00.bin\n", argv[0]);
		return 2;
	}
	const char *image = argv[1];
	std::string work = argv[2];
	std::vector<uint8_t> real_utoc = load(argv[3]);
	std::vector<uint8_t> real_ptoc = load(argv[4]);
	CHECK(real_utoc.size() == 2336 && real_ptoc.size() == 2336, "capture files missing");
	mdh10_set_clock(fake_clock);

	remove((std::string(image) + ".utoc").c_str());

	/* ---------- Formatted disc ---------- */
	MDH10Device *d = mdh10_open(image, NULL);
	CHECK(d != NULL, "open formatted image");
	if (!d)
		return 1;

	// INQUIRY: no unit attention, exactly 36 bytes, SONY / MDH-10
	Result r = cmd(d, {0x12, 0, 0, 0, 0x24, 0});
	CHECK(r.status == 0 && r.data.size() == 36, "inquiry status %d len %zu", r.status, r.data.size());
	CHECK(memcmp(r.data.data() + 8, "SONY    MDH-10          1.11", 28) == 0, "inquiry strings");
	CHECK(r.data[0] == 0x10 && r.data[1] == 0x80, "inquiry type/RMB");

	// First TUR: UNIT ATTENTION 28/00 (FRU CC), as on the real drive; then GOOD
	r = cmd(d, {0, 0, 0, 0, 0, 0});
	CHECK(r.status == 2, "first TUR must be CHECK CONDITION");
	std::vector<uint8_t> s = sense(d);
	CHECK(s == hex("70 00 06 00 00 00 00 0a 00 00 00 00 28 00 cc 00 00 00"), "UA sense bytes");
	r = cmd(d, {0, 0, 0, 0, 0, 0});
	CHECK(r.status == 0, "second TUR GOOD");
	CHECK(sense(d)[2] == 0, "sense cleared");

	// D8 as captured (Windows: byte2=01) and as sent by the Mac driver (byte2=FF)
	r = cmd(d, hex("d8 00 01 00 00 00 00 00 08 00"));
	CHECK(r.status == 0 && r.data == hex("01 00 00 00 00 00 04 00"), "D8 formatted");
	r = cmd(d, hex("d8 00 ff 00 00 00 00 00 08 00"));
	CHECK(r.status == 0 && r.data == hex("01 00 00 00 00 00 04 00"), "D8 (Mac form)");

	// D1 / D4 identical to the real drive's responses
	r = cmd(d, hex("d1 00 00 00 00 00 00 09 20 00"));
	CHECK(r.status == 0 && r.data == real_utoc, "D1 matches mddata_d1.bin");
	r = cmd(d, hex("d4 00 00 00 00 00 00 09 20 00"));
	CHECK(r.status == 0 && r.data == real_ptoc, "D4 matches mddata_d4_00.bin");
	CHECK(memcmp(r.data.data() + 8, "MINX", 4) == 0, "P-TOC MINX");
	r = cmd(d, hex("d4 00 00 00 00 01 00 09 20 00"));
	CHECK(r.status == 2, "D4 sector 1 fails");
	CHECK(sense(d) == hex("70 00 05 00 00 00 00 0a 00 00 00 00 24 00 c7 c0 00 05"), "D4 sector 1 sense as captured");

	// READ CAPACITY
	r = cmd(d, hex("25 00 00 00 00 00 00 00 00 00"));
	CHECK(r.status == 0 && r.data == hex("00 01 13 3f 00 00 08 00"), "read capacity");

	// Volume descriptor
	r = cmd(d, cdb10(0x28, 0x420, 1));
	CHECK(r.status == 0 && r.data.size() == 2048 && memcmp(r.data.data(), "\0MD001", 6) == 0, "READ(10) 0x420 = MD001");
	r = cmd(d, cdb10(0x28, 0x420, 64));
	CHECK(r.status == 0 && r.data.size() == 64 * 2048, "64 block read");
	r = cmd(d, cdb10(0x28, 70464 - 1, 2));
	CHECK(r.status == 2 && sense(d)[12] == 0x21, "read past end");

	// READ(6) of block 0 (ROM boot scan): zeros
	r = cmd(d, {0x08, 0, 0, 0, 1, 0});
	CHECK(r.status == 0 && r.data.size() == 2048, "READ(6)");

	// MODE SENSE pages, captured bytes
	r = cmd(d, hex("1a 00 01 00 18 00"));
	CHECK(r.data == hex("17 03 00 08 00 00 00 00 00 00 08 00 01 0a 80 05 00 00 00 00 05 00 00 00"), "page 01");
	r = cmd(d, hex("1a 08 01 00 04 00"));
	CHECK(r.data == hex("0f 03 00 00"), "page 01 DBD header");
	r = cmd(d, hex("1a 00 08 00 18 00"));
	CHECK(r.data == hex("17 03 00 08 00 00 00 00 00 00 08 00 08 0a 04 00 00 00 00 00 00 00 00 00"), "page 08");
	r = cmd(d, hex("1a 08 20 00 04 00"));
	CHECK(r.data == hex("13 03 00 00"), "page 20 DBD header");
	r = cmd(d, hex("1a 00 20 00 1c 00"));
	CHECK(r.data == hex("1b 03 00 08 00 00 00 00 00 00 08 00 20 0e 00 00 00 20 09 20 25 00 00 00 00 00 00 00"), "page 20");
	r = cmd(d, hex("1a 00 3f 00 ff 00"));
	CHECK(r.status == 0 && r.data.size() == 4 + 8 + 12 + 12 + 16 + 16, "page 3F");

	// MODE SELECT as sent by Windows (retries 3/3) persists
	r = cmd(d, hex("15 10 00 00 18 00"), hex("00 03 00 08 00 00 00 00 00 00 08 00 01 0a 80 03 00 00 00 00 03 00 00 00"));
	CHECK(r.status == 0, "mode select page 1");
	r = cmd(d, hex("1a 00 01 00 18 00"));
	CHECK(r.data == hex("17 03 00 08 00 00 00 00 00 00 08 00 01 0a 80 03 00 00 00 00 03 00 00 00"), "page 01 persisted");
	// Mac style: PF=0, PS bit echoed
	r = cmd(d, hex("15 00 00 00 18 00"), hex("00 00 00 08 00 00 00 00 00 00 08 00 88 0a 04 00 00 00 00 00 00 00 00 00"));
	CHECK(r.status == 0, "mode select PS=1 tolerated");

	// WRITE(10) with the 0x80 control bit, read back
	std::vector<uint8_t> pattern(4 * 2048);
	for (size_t i = 0; i < pattern.size(); i++)
		pattern[i] = (uint8_t)(i * 7 + 3);
	uint32_t tl = 70464 - 32;
	r = cmd(d, cdb10(0x2a, tl, 4, 0, 0x80), pattern);
	CHECK(r.status == 0, "write");
	r = cmd(d, cdb10(0x28, tl, 4));
	CHECK(r.status == 0 && r.data == pattern, "read back");
	r = cmd(d, cdb10(0x2e, tl, 4), std::vector<uint8_t>(4 * 2048, 0));
	CHECK(r.status == 0, "write and verify (restore zeros)");
	r = cmd(d, hex("2f 00 00 00 00 00 00 00 20 00"));
	CHECK(r.status == 0, "verify");

	// Lock cache / prevent / audio no-ops
	CHECK(cmd(d, hex("36 02 00 00 04 20 00 00 20 00")).status == 0, "lock cache");
	CHECK(cmd(d, hex("d7 00 00 00 00 00 00 00 04 00")).data == hex("00 00 00 00"), "D7");
	CHECK(cmd(d, hex("d5 00 00 00 00 00 00 00 04 00")).data == hex("00 00 00 00"), "D5");
	CHECK(cmd(d, hex("d6 00 00 00 00 00 00 00 00 00")).status == 0, "D6");
	CHECK(cmd(d, {0xff, 0, 0, 0, 0, 0}).status == 2 && sense_is(d, 5, 0x20, 0), "invalid opcode");

	// Eject: prevented, then allowed
	CHECK(cmd(d, {0x1e, 0, 0, 0, 1, 0}).status == 0, "prevent");
	CHECK(cmd(d, {0x1b, 0, 0, 0, 2, 0}).status == 2 && sense_is(d, 5, 0x53, 2), "eject while prevented");
	CHECK(cmd(d, {0x1e, 0, 0, 0, 0, 0}).status == 0, "allow");
	CHECK(cmd(d, {0x1b, 0, 0, 0, 2, 0}).status == 0, "eject");
	CHECK(cmd(d, {0, 0, 0, 0, 0, 0}).status == 2 && sense_is(d, 2, 0x3a, 0), "no medium after eject");
	CHECK(cmd(d, {0x12, 0, 0, 0, 0x24, 0}).status == 0, "inquiry without medium");

	// Hotkey insert -> UNIT ATTENTION -> ready
	mdh10_request_insert();
	CHECK(cmd(d, {0, 0, 0, 0, 0, 0}).status == 2 && sense_is(d, 6, 0x28, 0), "UA after insert");
	CHECK(cmd(d, {0, 0, 0, 0, 0, 0}).status == 0, "ready after insert");
	mdh10_close(d);

	/* ---------- Blank disc created on demand ---------- */
	std::string blank = work + "/blank_test.img";
	remove(blank.c_str());
	remove((blank + ".utoc").c_str());
	d = mdh10_open(blank.c_str(), "MDM110");
	CHECK(d != NULL, "create blank");
	if (!d)
		return 1;
	r = cmd(d, {0x12, 0, 0, 0, 0x24, 0});
	CHECK(memcmp(r.data.data() + 8, "SONY    MDM110          1.01", 28) == 0, "MDM110 inquiry");
	cmd(d, {0, 0, 0, 0, 0, 0});
	CHECK(cmd(d, hex("25 00 00 00 00 00 00 00 00 00")).data == hex("00 01 13 3f 00 00 08 00"), "blank capacity");
	CHECK(cmd(d, hex("d8 00 01 00 00 00 00 00 08 00")).data == hex("ff 00 00 00 00 00 00 00"), "blank D8 = FF");
	r = cmd(d, cdb10(0x28, 0x20, 1));
	CHECK(r.status == 0 && r.data == std::vector<uint8_t>(2048, 0), "blank read returns zeros");

	// Full format as Windows does it: FORMAT UNIT FmtData + IMMED, poll TUR
	fake_now = 1000;
	CHECK(cmd(d, hex("04 10 00 00 00 00"), hex("00 02 00 00")).status == 0, "format unit immed");
	fake_now = 2500;
	CHECK(cmd(d, {0, 0, 0, 0, 0, 0}).status == 2, "TUR during format");
	s = sense(d);
	CHECK(s[2] == 2 && s[12] == 4 && s[13] == 4 && s[14] == 0xc2 && s[15] == 0x80, "format progress sense");
	unsigned prog = (s[16] << 8) | s[17];
	CHECK(prog > 0x7000 && prog < 0x9000, "progress ~50%% (%04x)", prog);
	fake_now = 4100;
	CHECK(cmd(d, {0, 0, 0, 0, 0, 0}).status == 0, "TUR after format");
	CHECK(cmd(d, hex("d5 00 00 00 00 00 00 00 04 00")).data == hex("00 00 00 00"), "D5 after format");
	CHECK(cmd(d, hex("d8 00 ff 00 00 00 00 00 08 00")).data == hex("01 00 00 00 00 00 04 00"), "FORMAT UNIT lays down the MD-DATA U-TOC (Mac never sends D2)");
	CHECK(cmd(d, hex("d1 00 00 00 00 00 00 09 20 00")).data == real_utoc, "U-TOC after format matches real disc");

	// Windows-style clear + rewrite: D2 with a cleared U-TOC hides the data track again
	std::vector<uint8_t> cleared(2336, 0);
	cleared[0x13] = 1;
	CHECK(cmd(d, hex("d2 00 00 00 00 00 00 09 20 00"), cleared).status == 0, "D2 clear");
	CHECK(cmd(d, hex("d8 00 01 00 00 00 00 00 08 00")).data == hex("ff 00 00 00 00 00 00 00"), "D8 after clear");

	// Host writes the U-TOC and the D8 data track appears
	CHECK(cmd(d, hex("d2 00 00 00 00 00 00 09 20 00"), real_utoc).status == 0, "D2");
	CHECK(cmd(d, hex("d8 00 01 00 00 00 00 00 08 00")).data == hex("01 00 00 00 00 00 04 00"), "D8 after D2");
	mdh10_close(d);

	// U-TOC persisted in the sidecar
	d = mdh10_open(blank.c_str(), NULL);
	cmd(d, {0, 0, 0, 0, 0, 0});
	CHECK(cmd(d, hex("d1 00 00 00 00 00 00 09 20 00")).data == real_utoc, "U-TOC sidecar persisted");
	// Mac non-immediate format completes synchronously
	CHECK(cmd(d, {0x04, 0, 0, 0, 0, 0}).status == 0, "mac format");
	CHECK(cmd(d, {0, 0, 0, 0, 0, 0}).status == 0, "ready after mac format");
	mdh10_close(d);
	remove(blank.c_str());
	remove((blank + ".utoc").c_str());

	printf("%d/%d checks passed\n", checks - failures, checks);
	return failures ? 1 : 0;
}
