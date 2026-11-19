/*
 *  scsi_mdh10.cpp - Sony MDH-10 / MDM-110 MD-DATA drive emulation
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  Behaviour reconstructed from:
 *   - Bus Hound captures of a real MDH-10 used by the Windows 95 driver
 *   - raw responses of a real MDM-110 to its vendor commands (sg_raw)
 *   - the Macintosh "MD Driver" 1.81 (DRVR .SonyMD), the DOS/Win95 MDMGR
 *     command templates, and Aaru dumps of MD-DATA discs.
 *
 *  Medium model
 *   - 70464 logical blocks of 2048 bytes (LBA = (cluster - 50) * 32 + sector).
 *     LBA 0..1023 is the system track, 1024.. the data track.  The image file
 *     is raw: LBA n lives at offset n * 2048 (same layout as an Aaru .img dump).
 *   - The U-TOC (vendor D1/D2, 2336-byte sectors) is kept in "<image>.utoc".
 *     When missing it is synthesised: the real MD-DATA U-TOC if the image holds
 *     an MDFS volume descriptor ("MD001" at LBA 0x420), else a cleared U-TOC.
 *   - The P-TOC (vendor D4) is the fixed "MINX" MD-DATA P-TOC of a real disc.
 *   - A read-only image file behaves as a write-protected disc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>

#include "scsi_mdh10.h"
#include "scsi_mdh10_tables.h"

#ifdef _WIN32
#define mdh10_fseek _fseeki64
#define mdh10_ftell _ftelli64
typedef long long mdh10_off;
#else
#define mdh10_fseek fseeko
#define mdh10_ftell ftello
typedef off_t mdh10_off;
#endif

/* Constants */
static const uint32_t MD_BLOCK_SIZE = 2048;
static const uint32_t MD_DATA_BLOCKS = 70464;		// 2202 clusters * 32
static const uint32_t TOC_SECTOR_SIZE = 2336;		// 0x920
static const int UTOC_SECTORS = 8;
static const uint32_t VD_LBA = 0x420;				// MDFS volume descriptor
static const uint64_t FORMAT_DURATION_MS = 3000;	// simulated FORMAT UNIT (IMMED) time

/* Status */
static const uint8_t ST_GOOD = 0x00;
static const uint8_t ST_CHECK = 0x02;

/* Sense keys */
enum {
	SK_NO_SENSE = 0x0, SK_NOT_READY = 0x2, SK_MEDIUM_ERROR = 0x3, SK_HARDWARE_ERROR = 0x4,
	SK_ILLEGAL_REQUEST = 0x5, SK_UNIT_ATTENTION = 0x6, SK_DATA_PROTECT = 0x7
};

/* Mode pages: captured defaults from the real drive (page code, length, params) */
static const uint8_t page01_default[12] = { 0x01, 0x0a, 0x80, 0x05, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00 };
static const uint8_t page08_default[12] = { 0x08, 0x0a, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
static const uint8_t page20_default[16] = { 0x20, 0x0e, 0x00, 0x00, 0x00, 0x20, 0x09, 0x20, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
static const uint8_t page21_default[16] = { 0x21, 0x0e, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x02, 0x10, 0x00, 0x00, 0x00, 0x00 };

enum { NUM_PAGES = 4 };

struct ModePage {
	const uint8_t *def;
	uint8_t cur[16];
	int len;
};

struct MDH10Device {
	char *path;
	char *utoc_path;
	FILE *f;
	bool present;
	bool write_protect;
	uint32_t blocks;

	uint8_t inquiry[36];
	uint8_t utoc[UTOC_SECTORS][TOC_SECTOR_SIZE];

	uint8_t sense[18];
	bool sense_valid;
	bool unit_attention;
	bool prevent;

	ModePage pages[NUM_PAGES];

	bool formatting;
	uint64_t format_start;

	unsigned insert_gen;

	uint8_t *resp;
	uint32_t resp_cap;
	uint32_t resp_len;
};

/* Command trace on stderr when the MDH10_DEBUG environment variable is set */
static int debug_trace = -1;

static void trace(MDH10Device *dev, const uint8_t *cdb, int cdb_len, uint32_t out_len, uint8_t st)
{
	if (debug_trace < 0)
		debug_trace = getenv("MDH10_DEBUG") != NULL;
	if (!debug_trace)
		return;
	fprintf(stderr, "MDH-10:");
	for (int i = 0; i < cdb_len; i++)
		fprintf(stderr, " %02x", cdb[i]);
	fprintf(stderr, " out=%u in=%u st=%02x", out_len, dev->resp_len, st);
	if (st == ST_CHECK)
		fprintf(stderr, " sense=%x/%02x/%02x", dev->sense[2], dev->sense[12], dev->sense[13]);
	fprintf(stderr, "\n");
}

/* Insert request from the UI thread */
static volatile unsigned insert_request_gen = 0;

void mdh10_request_insert(void)
{
	insert_request_gen = insert_request_gen + 1;
}

/* Clock */
static uint64_t default_clock(void)
{
	using namespace std::chrono;
	return (uint64_t)duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

static uint64_t (*clock_ms)(void) = default_clock;

void mdh10_set_clock(uint64_t (*now_ms)(void))
{
	clock_ms = now_ms ? now_ms : default_clock;
}

/* Helpers */
static inline uint32_t be16(const uint8_t *p) { return ((uint32_t)p[0] << 8) | p[1]; }
static inline uint32_t be32(const uint8_t *p) { return ((uint32_t)p[0] << 24) | ((uint32_t)p[1] << 16) | ((uint32_t)p[2] << 8) | p[3]; }
static inline void put_be32(uint8_t *p, uint32_t v) { p[0] = v >> 24; p[1] = v >> 16; p[2] = v >> 8; p[3] = v; }

static char *dup_str(const char *s)
{
	size_t n = strlen(s) + 1;
	char *d = (char *)malloc(n);
	if (d)
		memcpy(d, s, n);
	return d;
}

static uint8_t *resp_alloc(MDH10Device *dev, uint32_t len)
{
	if (len > dev->resp_cap) {
		uint8_t *n = (uint8_t *)realloc(dev->resp, len);
		if (n == NULL)
			return NULL;
		dev->resp = n;
		dev->resp_cap = len;
	}
	memset(dev->resp, 0, len);
	dev->resp_len = len;
	return dev->resp;
}

static void resp_truncate(MDH10Device *dev, uint32_t alloc)
{
	if (dev->resp_len > alloc)
		dev->resp_len = alloc;
}

// Build fixed-format sense data (18 bytes) as the real drive does.
static uint8_t set_sense(MDH10Device *dev, uint8_t key, uint8_t asc, uint8_t ascq,
                         uint8_t fru = 0, bool info_valid = false, uint32_t info = 0,
                         const uint8_t *sks = NULL)
{
	uint8_t *s = dev->sense;
	memset(s, 0, sizeof(dev->sense));
	s[0] = info_valid ? 0xf0 : 0x70;
	s[2] = key;			// bare sense key; the Mac driver compares the whole byte
	if (info_valid)
		put_be32(s + 3, info);
	s[7] = 0x0a;
	s[12] = asc;
	s[13] = ascq;
	s[14] = fru;
	if (sks) {
		s[15] = sks[0];
		s[16] = sks[1];
		s[17] = sks[2];
	}
	dev->sense_valid = true;
	return ST_CHECK;
}

static uint8_t invalid_field_in_cdb(MDH10Device *dev, int byte)
{
	uint8_t sks[3] = { 0xc0, (uint8_t)(byte >> 8), (uint8_t)byte };
	return set_sense(dev, SK_ILLEGAL_REQUEST, 0x24, 0x00, 0xc7, false, 0, sks);
}

static uint8_t lba_out_of_range(MDH10Device *dev, uint32_t lba)
{
	return set_sense(dev, SK_ILLEGAL_REQUEST, 0x21, 0x00, 0, true, lba);
}

static uint8_t write_protected(MDH10Device *dev)
{
	return set_sense(dev, SK_DATA_PROTECT, 0x27, 0x00);
}

static uint8_t medium_error(MDH10Device *dev, uint32_t lba)
{
	return set_sense(dev, SK_MEDIUM_ERROR, 0x11, 0x00, 0, true, lba);
}

/* U-TOC handling */
static bool image_has_mdfs(MDH10Device *dev)
{
	uint8_t vd[8];
	if (dev->f == NULL || dev->blocks <= VD_LBA)
		return false;
	if (mdh10_fseek(dev->f, (mdh10_off)VD_LBA * MD_BLOCK_SIZE, SEEK_SET) != 0)
		return false;
	if (fread(vd, 1, sizeof(vd), dev->f) != sizeof(vd))
		return false;
	return memcmp(vd + 1, "MD001", 5) == 0;
}

static void load_utoc(MDH10Device *dev)
{
	memset(dev->utoc, 0, sizeof(dev->utoc));
	FILE *u = fopen(dev->utoc_path, "rb");
	if (u) {
		size_t n = fread(dev->utoc, 1, sizeof(dev->utoc), u);
		fclose(u);
		if (n >= TOC_SECTOR_SIZE)
			return;
		memset(dev->utoc, 0, sizeof(dev->utoc));
	}
	if (image_has_mdfs(dev))
		memcpy(dev->utoc[0], mdh10_mddata_utoc0, TOC_SECTOR_SIZE);
	else
		dev->utoc[0][0x13] = 0x01;		// cleared U-TOC (sector-used bitmap = sector 0)
}

static void save_utoc(MDH10Device *dev)
{
	FILE *u = fopen(dev->utoc_path, "wb");
	if (u == NULL) {
		fprintf(stderr, "MDH-10: cannot write U-TOC file %s\n", dev->utoc_path);
		return;
	}
	fwrite(dev->utoc, 1, sizeof(dev->utoc), u);
	fclose(u);
}

// LBA of the start of the MD-DATA data track according to the U-TOC, or -1.
static long data_track_lba(MDH10Device *dev)
{
	const uint8_t *t = dev->utoc[0];
	int first = t[0x0e], last = t[0x0f];
	if (first == 0 || last < first)
		return -1;
	for (int trk = first; trk <= last && trk < 256; trk++) {
		int part = t[0x20 + trk];
		if (part == 0)
			continue;
		const uint8_t *e = t + 0x120 + 8 * part;
		if (e + 8 > t + TOC_SECTOR_SIZE)
			continue;
		if (e[3] != 0xd0)			// track mode of an MD-DATA data track
			continue;
		uint32_t addr = ((uint32_t)e[0] << 16) | ((uint32_t)e[1] << 8) | e[2];
		uint32_t cluster = addr >> 10;
		uint32_t sector = (addr >> 4) & 0x3f;
		if (cluster < 50 || sector >= 32)
			continue;
		return (long)((cluster - 50) * 32 + sector);
	}
	return -1;
}

/* Medium */
static bool open_image(MDH10Device *dev)
{
	dev->write_protect = false;
	dev->f = fopen(dev->path, "rb+");
	if (dev->f == NULL) {
		dev->f = fopen(dev->path, "rb");
		if (dev->f != NULL)
			dev->write_protect = true;
	}
	if (dev->f == NULL) {
		// Create a blank, unformatted disc
		dev->f = fopen(dev->path, "wb+");
		if (dev->f == NULL)
			return false;
		static const uint8_t zero = 0;
		mdh10_fseek(dev->f, (mdh10_off)MD_DATA_BLOCKS * MD_BLOCK_SIZE - 1, SEEK_SET);
		fwrite(&zero, 1, 1, dev->f);
		fflush(dev->f);
		remove(dev->utoc_path);
		printf("MDH-10: created blank MD-DATA image %s\n", dev->path);
	}
	mdh10_fseek(dev->f, 0, SEEK_END);
	mdh10_off size = mdh10_ftell(dev->f);
	dev->blocks = (uint32_t)(size / MD_BLOCK_SIZE);
	if (dev->blocks == 0) {
		fclose(dev->f);
		dev->f = NULL;
		return false;
	}
	if (dev->blocks != MD_DATA_BLOCKS)
		fprintf(stderr, "MDH-10: warning: %s has %u blocks (a real MD-DATA disc has %u)\n",
		        dev->path, dev->blocks, MD_DATA_BLOCKS);
	load_utoc(dev);
	return true;
}

bool mdh10_insert(MDH10Device *dev)
{
	if (dev->present)
		return true;
	if (!open_image(dev))
		return false;
	dev->present = true;
	dev->unit_attention = true;
	dev->prevent = false;
	dev->formatting = false;
	return true;
}

bool mdh10_eject(MDH10Device *dev)
{
	if (!dev->present)
		return true;
	if (dev->f) {
		fflush(dev->f);
		fclose(dev->f);
		dev->f = NULL;
	}
	dev->present = false;
	dev->unit_attention = false;
	dev->prevent = false;
	dev->formatting = false;
	return true;
}

bool mdh10_medium_present(MDH10Device *dev)
{
	return dev->present;
}

/* Open / close */
MDH10Device *mdh10_open(const char *image_path, const char *model)
{
	if (image_path == NULL || *image_path == 0)
		return NULL;
	MDH10Device *dev = (MDH10Device *)calloc(1, sizeof(MDH10Device));
	if (dev == NULL)
		return NULL;
	dev->path = dup_str(image_path);
	dev->utoc_path = (char *)malloc(strlen(image_path) + 6);
	if (dev->path == NULL || dev->utoc_path == NULL) {
		mdh10_close(dev);
		return NULL;
	}
	sprintf(dev->utoc_path, "%s.utoc", image_path);

	// INQUIRY: peripheral type 0x10 as reported by the real MDM-110, removable
	const char *product = "MDH-10          ";
	const char *revision = "1.11";
	if (model && (strcmp(model, "MDM110") == 0 || strcmp(model, "MDM-110") == 0 || strcmp(model, "mdm110") == 0)) {
		product = "MDM110          ";
		revision = "1.01";
	}
	static const uint8_t inq_hdr[8] = { 0x10, 0x80, 0x02, 0x02, 0x1f, 0x00, 0x00, 0x00 };
	memcpy(dev->inquiry, inq_hdr, 8);
	memcpy(dev->inquiry + 8, "SONY    ", 8);
	memcpy(dev->inquiry + 16, product, 16);
	memcpy(dev->inquiry + 32, revision, 4);

	static const uint8_t *defs[NUM_PAGES] = { page01_default, page08_default, page20_default, page21_default };
	static const int lens[NUM_PAGES] = { 12, 12, 16, 16 };
	for (int i = 0; i < NUM_PAGES; i++) {
		dev->pages[i].def = defs[i];
		dev->pages[i].len = lens[i];
		memcpy(dev->pages[i].cur, defs[i], lens[i]);
	}

	dev->insert_gen = insert_request_gen;
	if (!mdh10_insert(dev)) {
		fprintf(stderr, "MDH-10: cannot open or create image %s\n", image_path);
		mdh10_close(dev);
		return NULL;
	}
	return dev;
}

void mdh10_close(MDH10Device *dev)
{
	if (dev == NULL)
		return;
	if (dev->f) {
		fflush(dev->f);
		fclose(dev->f);
	}
	free(dev->path);
	free(dev->utoc_path);
	free(dev->resp);
	free(dev);
}

/* Commands */
static uint8_t cmd_inquiry(MDH10Device *dev, const uint8_t *cdb)
{
	if (cdb[1] & 0x01)			// EVPD not supported
		return invalid_field_in_cdb(dev, 1);
	uint8_t *r = resp_alloc(dev, sizeof(dev->inquiry));
	memcpy(r, dev->inquiry, sizeof(dev->inquiry));
	resp_truncate(dev, cdb[4]);
	return ST_GOOD;
}

static uint32_t format_progress(MDH10Device *dev)
{
	uint64_t elapsed = clock_ms() - dev->format_start;
	uint32_t p = (uint32_t)(elapsed * 0x10000 / FORMAT_DURATION_MS);
	return p > 0xfffe ? 0xfffe : p;
}

static void update_format(MDH10Device *dev)
{
	if (dev->formatting && clock_ms() - dev->format_start >= FORMAT_DURATION_MS)
		dev->formatting = false;
}

static uint8_t format_in_progress(MDH10Device *dev)
{
	uint32_t p = format_progress(dev);
	uint8_t sks[3] = { 0x80, (uint8_t)(p >> 8), (uint8_t)p };
	return set_sense(dev, SK_NOT_READY, 0x04, 0x04, 0xc2, false, 0, sks);
}

static uint8_t cmd_request_sense(MDH10Device *dev, const uint8_t *cdb)
{
	uint8_t *r = resp_alloc(dev, 18);
	if (dev->sense_valid) {
		memcpy(r, dev->sense, 18);
	} else {
		update_format(dev);
		if (dev->formatting) {
			format_in_progress(dev);
			memcpy(r, dev->sense, 18);
		} else {
			r[0] = 0x70;
			r[7] = 0x0a;
		}
	}
	dev->sense_valid = false;
	uint32_t alloc = cdb[4] ? cdb[4] : 4;	// SCSI-2: 0 means 4 bytes
	resp_truncate(dev, alloc);
	return ST_GOOD;
}

static uint8_t read_blocks(MDH10Device *dev, uint32_t lba, uint32_t count)
{
	if ((uint64_t)lba + count > dev->blocks)
		return lba_out_of_range(dev, lba);
	uint8_t *r = resp_alloc(dev, count * MD_BLOCK_SIZE);
	if (r == NULL)
		return set_sense(dev, SK_HARDWARE_ERROR, 0x44, 0x00);
	if (count == 0)
		return ST_GOOD;
	if (mdh10_fseek(dev->f, (mdh10_off)lba * MD_BLOCK_SIZE, SEEK_SET) != 0)
		return medium_error(dev, lba);
	size_t n = fread(r, 1, (size_t)count * MD_BLOCK_SIZE, dev->f);
	(void)n;	// short reads (truncated image) return zeros, like unwritten MD-DATA sectors
	return ST_GOOD;
}

static uint8_t write_blocks(MDH10Device *dev, uint32_t lba, uint32_t count, const uint8_t *data, uint32_t len)
{
	if (dev->write_protect)
		return write_protected(dev);
	if ((uint64_t)lba + count > dev->blocks)
		return lba_out_of_range(dev, lba);
	if (count == 0)
		return ST_GOOD;
	uint32_t bytes = count * MD_BLOCK_SIZE;
	if (mdh10_fseek(dev->f, (mdh10_off)lba * MD_BLOCK_SIZE, SEEK_SET) != 0)
		return medium_error(dev, lba);
	uint32_t have = len < bytes ? len : bytes;
	if (have && fwrite(data, 1, have, dev->f) != have)
		return set_sense(dev, SK_MEDIUM_ERROR, 0x0c, 0x00, 0, true, lba);
	if (have < bytes) {		// initiator sent less than requested: pad with zeros
		static const uint8_t zeros[MD_BLOCK_SIZE] = { 0 };
		for (uint32_t left = bytes - have; left; ) {
			uint32_t n = left < MD_BLOCK_SIZE ? left : MD_BLOCK_SIZE;
			fwrite(zeros, 1, n, dev->f);
			left -= n;
		}
	}
	fflush(dev->f);
	return ST_GOOD;
}

static uint8_t cmd_read_capacity(MDH10Device *dev)
{
	uint8_t *r = resp_alloc(dev, 8);
	put_be32(r, dev->blocks - 1);
	put_be32(r + 4, MD_BLOCK_SIZE);
	return ST_GOOD;
}

static uint8_t cmd_start_stop(MDH10Device *dev, const uint8_t *cdb)
{
	bool start = cdb[4] & 0x01;
	bool loej = cdb[4] & 0x02;
	if (!loej)
		return ST_GOOD;
	if (start) {
		if (!dev->present && !mdh10_insert(dev))
			return set_sense(dev, SK_NOT_READY, 0x3a, 0x00);
		return ST_GOOD;
	}
	if (dev->prevent)
		return set_sense(dev, SK_ILLEGAL_REQUEST, 0x53, 0x02);	// medium removal prevented
	mdh10_eject(dev);
	return ST_GOOD;
}

static ModePage *find_page(MDH10Device *dev, int code)
{
	for (int i = 0; i < NUM_PAGES; i++)
		if ((dev->pages[i].def[0] & 0x3f) == code)
			return &dev->pages[i];
	return NULL;
}

static uint8_t cmd_mode_sense6(MDH10Device *dev, const uint8_t *cdb)
{
	bool dbd = cdb[1] & 0x08;
	int pc = cdb[2] >> 6;
	int code = cdb[2] & 0x3f;
	if (pc == 3)
		return set_sense(dev, SK_ILLEGAL_REQUEST, 0x39, 0x00);	// saving parameters not supported

	uint8_t tmp[4 + 8 + 12 + 12 + 16 + 16];
	memset(tmp, 0, sizeof(tmp));
	uint32_t n = 4;
	tmp[1] = dev->present ? 0x03 : 0x00;					// medium type: MD-DATA
	tmp[2] = (dev->present && dev->write_protect) ? 0x80 : 0x00;
	if (!dbd) {
		tmp[3] = 8;
		tmp[4 + 6] = MD_BLOCK_SIZE >> 8;	// density 0, block count 0, block length 2048
		n += 8;
	}
	bool found = false;
	for (int i = 0; i < NUM_PAGES; i++) {
		ModePage *p = &dev->pages[i];
		if (code != 0x3f && (p->def[0] & 0x3f) != code)
			continue;
		found = true;
		switch (pc) {
			case 0: memcpy(tmp + n, p->cur, p->len); break;
			case 1: tmp[n] = p->def[0]; tmp[n + 1] = p->def[1]; memset(tmp + n + 2, 0xff, p->len - 2); break;
			case 2: memcpy(tmp + n, p->def, p->len); break;
		}
		n += p->len;
	}
	if (!found)
		return invalid_field_in_cdb(dev, 2);
	tmp[0] = (uint8_t)(n - 1);
	uint8_t *r = resp_alloc(dev, n);
	memcpy(r, tmp, n);
	resp_truncate(dev, cdb[4]);
	return ST_GOOD;
}

static uint8_t invalid_param_list(MDH10Device *dev)
{
	return set_sense(dev, SK_ILLEGAL_REQUEST, 0x26, 0x00);
}

static uint8_t cmd_mode_select6(MDH10Device *dev, const uint8_t *cdb, const uint8_t *d, uint32_t len)
{
	uint32_t plen = cdb[4];
	if (len < plen)
		plen = len;
	if (plen == 0)
		return ST_GOOD;
	if (plen < 4)
		return invalid_param_list(dev);
	uint32_t bdlen = d[3];
	if (4 + bdlen > plen)
		return invalid_param_list(dev);
	if (bdlen >= 8) {
		uint32_t blen = ((uint32_t)d[4 + 5] << 16) | ((uint32_t)d[4 + 6] << 8) | d[4 + 7];
		if (blen != 0 && blen != MD_BLOCK_SIZE)
			return invalid_param_list(dev);
	}
	uint32_t i = 4 + bdlen;
	while (i + 2 <= plen) {
		int code = d[i] & 0x3f;		// PS bit tolerated (the Mac driver echoes it)
		uint32_t pl = d[i + 1];
		ModePage *p = find_page(dev, code);
		if (p == NULL || i + 2 + pl > plen)
			return invalid_param_list(dev);
		uint32_t copy = pl < (uint32_t)(p->len - 2) ? pl : (uint32_t)(p->len - 2);
		memcpy(p->cur + 2, d + i + 2, copy);
		i += 2 + pl;
	}
	return ST_GOOD;
}

static uint8_t cmd_format_unit(MDH10Device *dev, const uint8_t *cdb, const uint8_t *d, uint32_t len)
{
	if (dev->write_protect)
		return write_protected(dev);
	bool immed = false;
	if (cdb[1] & 0x10) {		// FmtData: parameter list header follows
		if (len < 4)
			return invalid_param_list(dev);
		immed = d[1] & 0x02;
	}
	// Erase the user area
	static const uint8_t zeros[64 * 1024] = { 0 };
	uint64_t total = (uint64_t)dev->blocks * MD_BLOCK_SIZE;
	if (mdh10_fseek(dev->f, 0, SEEK_SET) != 0)
		return set_sense(dev, SK_MEDIUM_ERROR, 0x31, 0x00);
	for (uint64_t done = 0; done < total; ) {
		size_t n = (size_t)((total - done) < sizeof(zeros) ? (total - done) : sizeof(zeros));
		if (fwrite(zeros, 1, n, dev->f) != n)
			return set_sense(dev, SK_MEDIUM_ERROR, 0x31, 0x00);
		done += n;
	}
	fflush(dev->f);
	// The drive lays down the MD-DATA system/data track U-TOC itself: the Mac
	// driver checks D8 right after FORMAT UNIT without ever sending D2.
	memset(dev->utoc, 0, sizeof(dev->utoc));
	memcpy(dev->utoc[0], mdh10_mddata_utoc0, TOC_SECTOR_SIZE);
	save_utoc(dev);
	if (immed) {
		dev->formatting = true;
		dev->format_start = clock_ms();
	}
	return ST_GOOD;
}

static uint8_t cmd_read_utoc(MDH10Device *dev, const uint8_t *cdb)
{
	uint32_t sector = cdb[5];
	uint32_t alloc = be16(cdb + 7);
	if (sector >= UTOC_SECTORS)
		return invalid_field_in_cdb(dev, 5);
	uint32_t avail = (UTOC_SECTORS - sector) * TOC_SECTOR_SIZE;
	uint32_t n = alloc < avail ? alloc : avail;
	uint8_t *r = resp_alloc(dev, n);
	memcpy(r, dev->utoc[sector], n);
	return ST_GOOD;
}

static uint8_t cmd_write_utoc(MDH10Device *dev, const uint8_t *cdb, const uint8_t *d, uint32_t len)
{
	uint32_t sector = cdb[5];
	uint32_t plen = be16(cdb + 7);
	if (dev->write_protect)
		return write_protected(dev);
	if (sector >= UTOC_SECTORS)
		return invalid_field_in_cdb(dev, 5);
	if (len < plen)
		plen = len;
	uint32_t avail = (UTOC_SECTORS - sector) * TOC_SECTOR_SIZE;
	if (plen > avail)
		plen = avail;
	memcpy(dev->utoc[sector], d, plen);
	save_utoc(dev);
	return ST_GOOD;
}

static uint8_t cmd_read_ptoc(MDH10Device *dev, const uint8_t *cdb)
{
	if (cdb[5] != 0)		// recordable discs only have P-TOC sector 0
		return invalid_field_in_cdb(dev, 5);
	uint8_t *r = resp_alloc(dev, TOC_SECTOR_SIZE);
	memcpy(r, mdh10_mddata_ptoc0, TOC_SECTOR_SIZE);
	resp_truncate(dev, be16(cdb + 7));
	return ST_GOOD;
}

static uint8_t cmd_data_track_info(MDH10Device *dev, const uint8_t *cdb)
{
	uint8_t *r = resp_alloc(dev, 8);
	long lba = data_track_lba(dev);
	if (lba < 0) {
		r[0] = 0xff;
	} else {
		r[0] = 0x01;
		put_be32(r + 4, (uint32_t)lba);
	}
	resp_truncate(dev, be16(cdb + 7));
	return ST_GOOD;
}

static uint8_t cmd_zero_data(MDH10Device *dev, uint32_t len)
{
	resp_alloc(dev, len);
	return ST_GOOD;
}

static bool needs_medium(uint8_t op)
{
	switch (op) {
		case 0x00: case 0x01: case 0x04: case 0x08: case 0x0a: case 0x0b:
		case 0x25: case 0x28: case 0x2a: case 0x2b: case 0x2e: case 0x2f:
		case 0x34: case 0x35: case 0x36:
		case 0x45: case 0x48: case 0x4b:
		case 0xd1: case 0xd2: case 0xd4: case 0xd8:
			return true;
		default:
			return false;
	}
}

uint8_t mdh10_command(MDH10Device *dev, const uint8_t *cdb, int cdb_len,
                      const uint8_t *data_out, uint32_t out_len,
                      const uint8_t **data_in, uint32_t *in_len)
{
	static const uint8_t empty = 0;
	dev->resp_len = 0;
	if (data_out == NULL) {
		data_out = &empty;
		out_len = 0;
	}

	// Re-insert request from the UI
	unsigned gen = insert_request_gen;
	if (gen != dev->insert_gen) {
		dev->insert_gen = gen;
		if (!dev->present && mdh10_insert(dev))
			printf("MDH-10: disc inserted (%s)\n", dev->path);
	}

	uint8_t st = ST_GOOD;
	uint8_t op = cdb[0];

	if (op == 0x03) {
		st = cmd_request_sense(dev, cdb);
		goto done;
	}
	dev->sense_valid = false;		// sense only survives until the next command

	if (op == 0x12) {
		st = cmd_inquiry(dev, cdb);
		goto done;
	}

	update_format(dev);
	if (dev->formatting) {
		st = format_in_progress(dev);
		goto done;
	}
	if (dev->present && dev->unit_attention) {
		dev->unit_attention = false;
		st = set_sense(dev, SK_UNIT_ATTENTION, 0x28, 0x00, 0xcc);	// medium may have changed
		goto done;
	}
	if (needs_medium(op) && !dev->present) {
		st = set_sense(dev, SK_NOT_READY, 0x3a, 0x00);
		goto done;
	}

	switch (op) {
		case 0x00:	// TEST UNIT READY
		case 0x01:	// REZERO UNIT
		case 0x16:	// RESERVE
		case 0x17:	// RELEASE
		case 0x1d:	// SEND DIAGNOSTIC
		case 0x34:	// PRE-FETCH
		case 0x36:	// LOCK/UNLOCK CACHE
		case 0x45:	// PLAY AUDIO(10)        (audio: accepted, no-op)
		case 0x48:	// PLAY AUDIO TRACK/INDEX
		case 0x4b:	// PAUSE/RESUME
		case 0xd6:	// vendor: stop audio play
			break;

		case 0x04:	// FORMAT UNIT
			st = cmd_format_unit(dev, cdb, data_out, out_len);
			break;

		case 0x08: {	// READ(6)
			uint32_t lba = ((uint32_t)(cdb[1] & 0x1f) << 16) | ((uint32_t)cdb[2] << 8) | cdb[3];
			st = read_blocks(dev, lba, cdb[4] ? cdb[4] : 256);
			break;
		}
		case 0x0a: {	// WRITE(6)
			uint32_t lba = ((uint32_t)(cdb[1] & 0x1f) << 16) | ((uint32_t)cdb[2] << 8) | cdb[3];
			st = write_blocks(dev, lba, cdb[4] ? cdb[4] : 256, data_out, out_len);
			break;
		}
		case 0x0b: {	// SEEK(6)
			uint32_t lba = ((uint32_t)(cdb[1] & 0x1f) << 16) | ((uint32_t)cdb[2] << 8) | cdb[3];
			if (lba >= dev->blocks)
				st = lba_out_of_range(dev, lba);
			break;
		}
		case 0x2b:	// SEEK(10)
			if (be32(cdb + 2) >= dev->blocks)
				st = lba_out_of_range(dev, be32(cdb + 2));
			break;

		case 0x15:	// MODE SELECT(6)
			st = cmd_mode_select6(dev, cdb, data_out, out_len);
			break;
		case 0x1a:	// MODE SENSE(6)
			st = cmd_mode_sense6(dev, cdb);
			break;

		case 0x1b:	// START STOP UNIT
			st = cmd_start_stop(dev, cdb);
			break;
		case 0x1e:	// PREVENT/ALLOW MEDIUM REMOVAL
			dev->prevent = cdb[4] & 0x01;
			if (dev->f)
				fflush(dev->f);
			break;

		case 0x25:	// READ CAPACITY
			st = cmd_read_capacity(dev);
			break;
		case 0x28:	// READ(10)
			st = read_blocks(dev, be32(cdb + 2), be16(cdb + 7));
			break;
		case 0x2a:	// WRITE(10); control bit 0x80 (new cluster hint) is ignored
		case 0x2e:	// WRITE AND VERIFY(10)
			st = write_blocks(dev, be32(cdb + 2), be16(cdb + 7), data_out, out_len);
			break;
		case 0x2f: {	// VERIFY(10)
			uint32_t lba = be32(cdb + 2), count = be16(cdb + 7);
			if ((uint64_t)lba + count > dev->blocks)
				st = lba_out_of_range(dev, lba);
			break;
		}
		case 0x35:	// SYNCHRONIZE CACHE
			fflush(dev->f);
			break;

		case 0xd1:	// vendor: read U-TOC sector(s)
			st = cmd_read_utoc(dev, cdb);
			break;
		case 0xd2:	// vendor: write U-TOC sector(s)
			st = cmd_write_utoc(dev, cdb, data_out, out_len);
			break;
		case 0xd4:	// vendor: read P-TOC sector
			st = cmd_read_ptoc(dev, cdb);
			break;
		case 0xd5: {	// vendor: format result (no defects)
			uint32_t alloc = be16(cdb + 7);
			st = cmd_zero_data(dev, alloc > 4096 ? 4096 : alloc);
			break;
		}
		case 0xd7: {	// vendor: audio play position (idle -> zero)
			uint32_t alloc = be16(cdb + 7);
			st = cmd_zero_data(dev, alloc < 4 ? alloc : 4);
			break;
		}
		case 0xd8:	// vendor: data track information
			st = cmd_data_track_info(dev, cdb);
			break;

		default:
			st = set_sense(dev, SK_ILLEGAL_REQUEST, 0x20, 0x00);	// invalid command operation code
			break;
	}

done:
	if (st != ST_GOOD)
		dev->resp_len = 0;
	trace(dev, cdb, cdb_len, out_len, st);
	*data_in = dev->resp;
	*in_len = dev->resp_len;
	return st;
}
