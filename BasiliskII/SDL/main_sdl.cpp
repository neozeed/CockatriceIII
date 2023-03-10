#include "sysdeps.h"
#ifdef WIN32
#include <SDL\SDL.h>
#include <SDL\SDL_main.h>
#include <SDL\SDL_thread.h>
#include <io.h>
#include <direct.h>		//for _chdir
#include "..\drmingw-0.7.7-win32\include\exchndl.h"
#else
#include <SDL/SDL.h>
#include <SDL/SDL_main.h>
#include <SDL/SDL_thread.h>
#endif

#undef main

#include <stdio.h>
#include <stdlib.h>
#ifndef __APPLE__
#else
#include <fcntl.h>
#include <sys/fcntl.h>
#endif


#include "cpu_emulation.h"
#include "sys.h"
#include "rom_patches.h"
#include "xpram.h"
#include "timer.h"
#include "video.h"
#include "prefs.h"
#include "prefs_editor.h"
#include "macos_util.h"
#include "user_strings.h"
#include "version.h"
#include "main.h"

#define DEBUG 0
#include "debug.h"

#if defined __APPLE__ || __linux
#define _O_BINARY 0
#define _O_RDONLY O_RDONLY
#define _lseek  lseek
#define _open   open
#define _read   read
typedef unsigned int DWORD;
#endif

const char ROM_FILE_NAME[] = "ROM";


// CPU and FPU type, addressing mode
int CPUType;
bool CPUIs68060;
int FPUType;
bool TwentyFourBitAddressing;

//Threads...
SDL_Thread *xpram_thread = NULL;
SDL_Thread *tick_funcxxx_thread = NULL;

static volatile bool tick_thread_cancel = false;	// Flag: Cancel 60Hz thread
static volatile bool xpram_thread_cancel = false;
/*
 *  Interrupt flags (must be handled atomically!)
 */
uint32 InterruptFlags = 0;

// Prototypes
int xpram_func(void *arg);
int tick_funcxxx(void *arg);		//from unix
static void one_tickbbb(...);	//from unix
void fixstdio(void);
//else where
//void usleep(long waitTime);
extern void slirp_tic(void);	//to keep slirp happy


#ifdef __APPLE__
int SDL_main(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{

	//	_chdir("c:\\test\\");
	// Initialize variables
#ifdef WIN32
	//Setup DrMinGW
	ExcHndlInit();
#endif
	RAMBaseHost = NULL;
	ROMBaseHost = NULL;
	srand(time(NULL));
	tzset();

	//fixstdio();

	// Print some info
	printf("Cockatrice III version %d.%d based on:\n",VERSION_MAJOR, VERSION_MINOR);
	printf(GetString(STR_ABOUT_TEXT1), 0, 8);
	printf(" %s\n", GetString(STR_ABOUT_TEXT2));
	#ifdef __GNUC__
		printf("compiled by GCC %s at %s\n",__VERSION__,__TIMESTAMP__);
	#endif
	fflush(stdout);
	
	// Parse arguments
	for (int i=1; i<argc; i++) {
		if (strcmp(argv[i], "-break") == 0 && ++i < argc)
			ROMBreakpoint = strtol(argv[i], NULL, 0);
		else if (strcmp(argv[i], "-rominfo") == 0)
			PrintROMInfo = true;
	}

	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_CDROM) < 0)
	printf("VID: Couldn't load SDL: %s", SDL_GetError());
	fflush(stdout);

	
	// Read preferences
	PrefsInit();

	// Init system routines
	SysInit();

		// Show preferences editor
	if (!PrefsFindBool("nogui"))
		if (!PrefsEditor())
			QuitEmulator();

	// Read RAM size
	RAMSize = PrefsFindInt32("ramsize") & 0xfff00000;	// Round down to 1MB boundary
	if (RAMSize < 1024*1024) {
		WarningAlert(GetString(STR_SMALL_RAM_WARN));
		RAMSize = 1024*1024;
	}

	// Create areas for Mac RAM and ROM
	RAMBaseHost = new uint8[RAMSize];
	ROMBaseHost = new uint8[0x100000];

	memset(ROMBaseHost,0xAA,0x100000);

	// Get rom file path from preferences
	const char *rom_path = PrefsFindString("rom");

	// Load Mac ROM
	int rom_fd = _open(rom_path ? rom_path : ROM_FILE_NAME, _O_RDONLY|_O_BINARY);
	//int rom_fd = _open("c:\\test\\ROM",_O_RDONLY|_O_BINARY );
	if (rom_fd < 0) {
		ErrorAlert(GetString(STR_NO_ROM_FILE_ERR));
		QuitEmulator();
	}

	printf(GetString(STR_READING_ROM_FILE));
	fflush(stdout);
	ROMSize = _lseek(rom_fd, 0L, SEEK_END);
	if (ROMSize != 64*1024 && ROMSize != 128*1024 && ROMSize != 256*1024 && ROMSize != 512*1024 && ROMSize != 1024*1024) {
		ErrorAlert(GetString(STR_ROM_SIZE_ERR));
		close(rom_fd);
		QuitEmulator();
	}

	int dontcare=_lseek(rom_fd, 0L, SEEK_SET);
	D(bug("don't care rewind %d\n",dontcare));
	int x= _read(rom_fd, ROMBaseHost, ROMSize);	//if (_read(rom_fd, &ROMBaseHost, ROMSize) != (ssize_t)ROMSize) {
	if(x!=ROMSize)
	{
		ErrorAlert(GetString(STR_ROM_FILE_READ_ERR));
		close(rom_fd);
		QuitEmulator();
	}

	// Initialize everything
	if (!InitAll())
		{
		printf("failed to initalized. Exiting!\n");
		fflush(stdout);
		QuitEmulator();
		}
	
	// Start XPRAM watchdog thread
	//right now dont need it
	xpram_thread=SDL_CreateThread(xpram_func,NULL);
	tick_funcxxx_thread=SDL_CreateThread(tick_funcxxx,NULL);
	
	// Start 68k and jump to ROM boot routine
	Start680x0();

	QuitEmulator();
	return 0;
}



void ClearInterruptFlag(uint32 flag)
{
//	pthread_mutex_lock(&intflag_lock);
	InterruptFlags &= ~flag;
//	pthread_mutex_unlock(&intflag_lock);
}

void SetInterruptFlag(uint32 flag)
{
//	pthread_mutex_lock(&intflag_lock);
	InterruptFlags |= flag;
//	pthread_mutex_unlock(&intflag_lock);
}


void ErrorAlert(const char *p)
{
	printf("%s",p);
	fflush(stdout);
}

#if EMULATED_68K
void FlushCodeCache(void *start, uint32 size)
{
}
#endif


/*
 *  Display warning alert
 */

void WarningAlert(const char *text)
{
#if ENABLE_GTK
	if (PrefsFindBool("nogui") || x_display == NULL) {
		printf(GetString(STR_SHELL_WARNING_PREFIX), text);
		return;
	}
	display_alert(STR_WARNING_ALERT_TITLE, STR_GUI_WARNING_PREFIX, STR_OK_BUTTON, text);
#else
	printf(GetString(STR_SHELL_WARNING_PREFIX), text);
	fflush(stdout);
#endif
}


/*
 *  Display choice alert
 */

bool ChoiceAlert(const char *text, const char *pos, const char *neg)
{
	printf(GetString(STR_SHELL_WARNING_PREFIX), text);
	fflush(stdout);
	return false;	//!!
}


void fixstdio(void)
{

}




/*
 *  60Hz thread (really 60.15Hz)
 */

static void one_tickbbbb(...)
{
	static int tick_counter = 0;

	// Pseudo Mac 1Hz interrupt, update local time
	if (++tick_counter > 60) {
		tick_counter = 0;
		WriteMacInt32(0x20c, TimerDateTime());
	}

	// Trigger 60Hz interrupt
	if (ROMVersion != ROM_VERSION_CLASSIC || HasMacStarted()) {
		SetInterruptFlag(INTFLAG_60HZ);
		TriggerInterrupt();
		slirp_tic();
	}
}

int tick_funcxxx(void *arg)
{
	while (!tick_thread_cancel) {

		// Wait
#ifdef HAVE_NANOSLEEP
		struct timespec req = {0, 16625000};
		nanosleep(&req, NULL);
#else
		//usleep(16625);
		Sleep(16);
#endif

		// Action
		one_tickbbbb();
	}
	return NULL;
}


/*
 *  XPRAM watchdog thread (saves XPRAM every minute)
 */

int xpram_func(void *arg)
{
	uint8 last_xpram[256];
	memcpy(last_xpram, XPRAM, 256);

	while (!xpram_thread_cancel) {
		for (int i=0; i<60 && !xpram_thread_cancel; i++) {
#ifdef HAVE_NANOSLEEP
			struct timespec req = {1, 0};
			nanosleep(&req, NULL);
#else
			usleep(1000000);
#endif
		}
		if (memcmp(last_xpram, XPRAM, 256)) {
			memcpy(last_xpram, XPRAM, 256);
			SaveXPRAM();
		}
	}
	return 0;
}
