# Generated automatically from Makefile.in by configure.
# Unix makefile for Cockatrice III

## System specific configuration

SHELL = /bin/sh

prefix = /usr/local
exec_prefix = ${prefix}
bindir = ${exec_prefix}/bin
datadir = ${prefix}/share
mandir = ${prefix}/man
man1dir = $(mandir)/man1

CC = gcc
CXX = c++
CFLAGS = -g -Os -ISDL -Ipcap
CXXFLAGS = -g -Os -ISDL -Ipcap
CPPFLAGS =  -I../include -I. -I../uae_cpu
#DEFS = -DHAVE_CONFIG_H -DENABLE_MON=0 -DREGPARAM="__attribute__((regparm(3)))" -DX86_ASSEMBLY -D_REENTRANT -DDATADIR=\"$(datadir)/$(APP)\"
#DEFS = -DHAVE_CONFIG_H -DENABLE_MON=0 -DX86_ASSEMBLY -D_REENTRANT -DFPU_IEEE  #-DFPU_X86 -DFPU_UAE 
DEFS = -DHAVE_CONFIG_H -DENABLE_MON=0 -D_REENTRANT -DFPU_IEEE -D_FILE_OFFSET_BITS=64
LDFLAGS = 
LIBS = ..\slirp\libslirp.a -Llibs -lSDL -lws2_32  -liphlpapi  ..\drmingw-0.7.7-win32\lib\libexchndl.a -static-libgcc -static-libstdc++
SYSSRCS = ../pcap/sdl_pcap.cpp ../dummy/scsi_dummy.cpp audio_sdl.cpp  ../dummy/prefs_editor_dummy.cpp 
CPUSRCS = ../uae_cpu/basilisk_glue.cpp ../uae_cpu/memory.cpp ../uae_cpu/newcpu.cpp ../uae_cpu/readcpu.cpp cpustbl.cpp cpudefs.cpp cpuemu.cpp
#FPUSRCS = ../uae_cpu/fpu/fpu_uae.cpp
#FPUSRCS = ../uae_cpu/fpu/fpu_x86.cpp
FPUSRCS = ../uae_cpu/fpu/fpu_ieee.cpp
INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL} -s
INSTALL_DATA = ${INSTALL} -m 644

## Files
SRCS = ../main.cpp main_sdl.cpp ../prefs.cpp ../dummy/prefs_dummy.cpp ../SDL/sys_unix_sdl.cpp \
    ../rom_patches.cpp ../slot_rom.cpp ../rsrc_patches.cpp ../emul_op.cpp \
    ../macos_util.cpp ../xpram.cpp ../dummy/xpram_dummy.cpp ../timer.cpp ../SDL/timer_common.cpp \
    ../dummy/clip_dummy.cpp ../adb.cpp ../serial.cpp ../dummy/serial_dummy.cpp ../ether.cpp ../sony.cpp \
    ../disk.cpp ../cdrom.cpp ../scsi.cpp ../video.cpp video_sdl.cpp ../audio.cpp \
    ../extfs.cpp ../user_strings.cpp user_strings_unix.cpp  \
    $(SYSSRCS) $(CPUSRCS) $(FPUSRCS)
APP = CockatriceIII.exe

## Rules
.PHONY: modules install uninstall clean distclean depend dep
.SUFFIXES:
.SUFFIXES: .c .cpp .s .o .h

all: $(APP)

OBJ_DIR = obj
#$(OBJ_DIR)::
#	@[ -d $(OBJ_DIR) ] || mkdir $(OBJ_DIR) > /dev/null 2>&1

define SRCS_LIST_TO_OBJS
	$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(foreach file, $(SRCS), \
	$(basename $(notdir $(file))))))
endef
OBJS = $(SRCS_LIST_TO_OBJS)

SRC_PATHS += $(sort $(foreach file, $(SRCS), $(dir $(file))))
VPATH :=
VPATH += $(addprefix :, $(subst  ,:, $(filter-out $($(subst, :, ,$(VPATH))), $(SRC_PATHS))))

$(APP): $(OBJ_DIR) $(OBJS) cockatricerc.o
	$(CXX) -o $(APP) $(LDFLAGS) $(OBJS) cockatricerc.o $(LIBS)

modules:
	cd Linux/NetDriver; make

install: $(APP) installdirs
	$(INSTALL_PROGRAM) $(APP) $(bindir)/$(APP)
	-$(INSTALL_DATA) $(APP).1 $(man1dir)/$(APP).1
	$(INSTALL_DATA) keycodes $(datadir)/$(APP)/keycodes
	$(INSTALL_DATA) fbdevices $(datadir)/$(APP)/fbdevices

installdirs:
	$(SHELL) mkinstalldirs $(bindir) $(man1dir) $(datadir)/$(APP)

uninstall:
	rm -f $(bindir)/$(APP)
	rm -f $(man1dir)/$(APP).1
	rm -f $(datadir)/$(APP)/keycodes
	rm -f $(datadir)/$(APP)/fbdevices
	rmdir $(datadir)/$(APP)

mostlyclean:
	rm -f $(APP) $(OBJ_DIR)/*.o $(OBJ_DIR)/*.exe core* *.core *~ *.bak
	rm -f *.o

clean: mostlyclean
	rm -f cpuemu.cpp cpudefs.cpp cputmp*.s cpufast*.s cpustbl.cpp cputbl.h

distclean: clean
	rm -rf $(OBJ_DIR)
	rm -f Makefile
	rm -f config.cache config.log config.status config.h

depend dep:
	makedepend $(CPPFLAGS) -Y. $(SRCS) 2>/dev/null

cockatricerc.o:
	windres cockatrice.rc -O coff -o cockatricerc.o

$(OBJ_DIR)/%.o : %.c
	$(CC) $(CPPFLAGS) $(DEFS) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(DEFS) $(CXXFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o : %.s
	$(CC) $(CPPFLAGS) $(DEFS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/cpuopti: $(OBJ_DIR)/cpuopti.o
	$(CC) $(LDFLAGS) -o $(OBJ_DIR)/cpuopti $(OBJ_DIR)/cpuopti.o
$(OBJ_DIR)/build68k.exe: $(OBJ_DIR)/build68k.o
	$(CC) $(LDFLAGS) -o $(OBJ_DIR)/build68k.exe $(OBJ_DIR)/build68k.o
$(OBJ_DIR)/gencpu.exe: $(OBJ_DIR)/gencpu.o $(OBJ_DIR)/readcpu.o $(OBJ_DIR)/cpudefs.o
	$(CC) $(LDFLAGS) -o $(OBJ_DIR)/gencpu.exe $(OBJ_DIR)/gencpu.o $(OBJ_DIR)/readcpu.o $(OBJ_DIR)/cpudefs.o
cpudefs.cpp: $(OBJ_DIR)/build68k.exe ../uae_cpu/table68k
#depends on where your slashes go...
	$(OBJ_DIR)\build68k.exe < ..\uae_cpu\table68k > cpudefs.cpp
#	$(OBJ_DIR)/build68k.exe <../uae_cpu/table68k >cpudefs.cpp
cpustbl.cpp: cpuemu.cpp
cputbl.h: cpuemu.cpp

#In the future, 2016, we don't need to break this into multiple programs.
cpuemu.cpp: $(OBJ_DIR)/gencpu.exe
	$(OBJ_DIR)/gencpu.exe

$(OBJ_DIR)/cpuemu1.o: cpuemu.cpp
	$(CXX) $(CPPFLAGS) $(DEFS) -DPART_1 $(CXXFLAGS) -c $< -o $@
$(OBJ_DIR)/cpuemu2.o: cpuemu.cpp
	$(CXX) $(CPPFLAGS) $(DEFS) -DPART_2 $(CXXFLAGS) -c $< -o $@
$(OBJ_DIR)/cpuemu3.o: cpuemu.cpp
	$(CXX) $(CPPFLAGS) $(DEFS) -DPART_3 $(CXXFLAGS) -c $< -o $@
$(OBJ_DIR)/cpuemu4.o: cpuemu.cpp
	$(CXX) $(CPPFLAGS) $(DEFS) -DPART_4 $(CXXFLAGS) -c $< -o $@
$(OBJ_DIR)/cpuemu5.o: cpuemu.cpp
	$(CXX) $(CPPFLAGS) $(DEFS) -DPART_5 $(CXXFLAGS) -c $< -o $@
$(OBJ_DIR)/cpuemu6.o: cpuemu.cpp
	$(CXX) $(CPPFLAGS) $(DEFS) -DPART_6 $(CXXFLAGS) -c $< -o $@
$(OBJ_DIR)/cpuemu7.o: cpuemu.cpp
	$(CXX) $(CPPFLAGS) $(DEFS) -DPART_7 $(CXXFLAGS) -c $< -o $@
$(OBJ_DIR)/cpuemu8.o: cpuemu.cpp
	$(CXX) $(CPPFLAGS) $(DEFS) -DPART_8 $(CXXFLAGS) -c $< -o $@

cpufast.s: cpuemu.cpp $(OBJ_DIR)/cpuopti
	$(CXX) $(CPPFLAGS) $(DEFS) -S $(CXXFLAGS) $< -o cputmp.s
	$(OBJ_DIR)/cpuopti <cputmp.s >$@ || mv cputmp.s $@
	rm -f cputmp.s
cpufast1.s: cpuemu.cpp $(OBJ_DIR)/cpuopti
	$(CXX) $(CPPFLAGS) $(DEFS) -DPART_1 -S $(CXXFLAGS) $< -o cputmp1.s
	$(OBJ_DIR)/cpuopti <cputmp1.s >$@ || mv cputmp1.s $@
	rm -f cputmp1.s
cpufast2.s: cpuemu.cpp $(OBJ_DIR)/cpuopti
	$(CXX) $(CPPFLAGS) $(DEFS) -DPART_2 -S $(CXXFLAGS) $< -o cputmp2.s
	$(OBJ_DIR)/cpuopti <cputmp2.s >$@ || mv cputmp2.s $@
	rm -f cputmp2.s
cpufast3.s: cpuemu.cpp $(OBJ_DIR)/cpuopti
	$(CXX) $(CPPFLAGS) $(DEFS) -DPART_3 -S $(CXXFLAGS) $< -o cputmp3.s
	$(OBJ_DIR)/cpuopti <cputmp3.s >$@ || mv cputmp3.s $@
	rm -f cputmp3.s
cpufast4.s: cpuemu.cpp $(OBJ_DIR)/cpuopti
	$(CXX) $(CPPFLAGS) $(DEFS) -DPART_4 -S $(CXXFLAGS) $< -o cputmp4.s
	$(OBJ_DIR)/cpuopti <cputmp4.s >$@ || mv cputmp4.s $@
	rm -f cputmp4.s
cpufast5.s: cpuemu.cpp $(OBJ_DIR)/cpuopti
	$(CXX) $(CPPFLAGS) $(DEFS) -DPART_5 -S $(CXXFLAGS) $< -o cputmp5.s
	$(OBJ_DIR)/cpuopti <cputmp5.s >$@ || mv cputmp5.s $@
	rm -f cputmp5.s
cpufast6.s: cpuemu.cpp $(OBJ_DIR)/cpuopti
	$(CXX) $(CPPFLAGS) $(DEFS) -DPART_6 -S $(CXXFLAGS) $< -o cputmp6.s
	$(OBJ_DIR)/cpuopti <cputmp6.s >$@ || mv cputmp6.s $@
	rm -f cputmp6.s
cpufast7.s: cpuemu.cpp $(OBJ_DIR)/cpuopti
	$(CXX) $(CPPFLAGS) $(DEFS) -DPART_7 -S $(CXXFLAGS) $< -o cputmp7.s
	$(OBJ_DIR)/cpuopti <cputmp7.s >$@ || mv cputmp7.s $@
	rm -f cputmp7.s
cpufast8.s: cpuemu.cpp $(OBJ_DIR)/cpuopti
	$(CXX) $(CPPFLAGS) $(DEFS) -DPART_8 -S $(CXXFLAGS) $< -o cputmp8.s
	$(OBJ_DIR)/cpuopti <cputmp8.s >$@ || mv cputmp8.s $@
	rm -f cputmp8.s

#-------------------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend depends on it.
