# Generated automatically from Makefile.in by configure.
# Unix makefile for Basilisk II

## System specific configuration

SHELL = /bin/sh

prefix = /usr/local
exec_prefix = ${prefix}
bindir = ${exec_prefix}/bin
datadir = ${prefix}/share
mandir = ${prefix}/man
man1dir = $(mandir)/man1

#CC = clang -arch i386
#CXX = clang -arch i386
CC = gcc -arch i386
CXX = g++ -arch i386
CFLAGS =  -O2 
CXXFLAGS =  -O2
CPPFLAGS =  -I../include -I. -I../uae_cpu -I../Unix
#DEFS = -DHAVE_CONFIG_H  -DENABLE_MON=0 -DENABLE_XF86_DGA=0 -DENABLE_FBDEV_DGA=1 -DENABLE_XF86_VIDMODE=0 -DENABLE_GTK=0 -DENABLE_ESD=0 -DREGPARAM="__attribute__((regparm(3)))" -DX86_ASSEMBLY -D_REENTRANT -DDATADIR=\"$(datadir)/$(APP)\"
DEFS = -DHAVE_CONFIG_H  -DX86_ASSEMBLY -D_REENTRANT -DREGPARAM="__attribute__((regparm(3)))" -DFPU_IEEE
LDFLAGS = 
LIBS = ../slirp/slirp106i386.a -lpthread -framework SDL -framework cocoa 
SYSSRCS = sdlmain.m ../SDL/sdl_pcap.cpp ../sdl/audio_sdl.cpp ../dummy/scsi_dummy.cpp  ../dummy/prefs_editor_dummy.cpp 
CPUSRCS = ../uae_cpu/basilisk_glue.cpp ../uae_cpu/memory.cpp ../uae_cpu/newcpu.cpp ../uae_cpu/readcpu.cpp ../uae_cpu/fpu/fpu_ieee.cpp cpustbl.cpp cpudefs.cpp cpuemu.cpp
INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL} -s
INSTALL_DATA = ${INSTALL} -m 644

## Files
SRCS = ../main.cpp main_sdl.cpp ../prefs.cpp ../dummy/prefs_dummy.cpp ../sdl/sys_unix_sdl.cpp \
    ../rom_patches.cpp ../slot_rom.cpp ../rsrc_patches.cpp ../emul_op.cpp \
    ../macos_util.cpp ../xpram.cpp ../dummy/xpram_dummy.cpp ../timer.cpp timer_unix.cpp \
    ../dummy/clip_dummy.cpp ../adb.cpp ../serial.cpp ../dummy/serial_dummy.cpp ../ether.cpp ../sony.cpp \
    ../disk.cpp ../cdrom.cpp ../scsi.cpp ../video.cpp ../sdl/video_sdl.cpp ../audio.cpp \
    ../extfs.cpp ../user_strings.cpp user_strings_sdl.cpp \
    $(SYSSRCS) $(CPUSRCS)
APP = BasiliskII

## Rules
.PHONY: modules install uninstall clean distclean depend dep
.SUFFIXES:
.SUFFIXES: .c .cpp .s .o .h

all: $(APP)

OBJ_DIR = obj
$(OBJ_DIR)::
	@[ -d $(OBJ_DIR) ] || mkdir $(OBJ_DIR) > /dev/null 2>&1

define SRCS_LIST_TO_OBJS
	$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(foreach file, $(SRCS), \
	$(basename $(notdir $(file))))))
endef
OBJS = $(SRCS_LIST_TO_OBJS)

SRC_PATHS += $(sort $(foreach file, $(SRCS), $(dir $(file))))
VPATH :=
VPATH += $(addprefix :, $(subst  ,:, $(filter-out $($(subst, :, ,$(VPATH))), $(SRC_PATHS))))

$(APP): $(OBJ_DIR) $(OBJS)
	$(CXX) -o $(APP) $(LDFLAGS) $(OBJS) $(LIBS)

mostlyclean:
	rm -f $(APP) $(OBJ_DIR)/* core* *.core *~ *.bak

clean: mostlyclean
	rm -f cpuemu.cpp cpudefs.cpp cputmp*.s cpufast*.s cpustbl.cpp cputbl.h

depend dep:
	makedepend $(CPPFLAGS) -Y. $(SRCS) 2>/dev/null

$(OBJ_DIR)/%.o : %.c
	$(CC) $(CPPFLAGS) $(DEFS) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o : %.m
	cc -arch i386 $(CPPFLAGS) $(DEFS) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(DEFS) $(CXXFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o : %.s
	$(CC)  -c $< -o $@

$(OBJ_DIR)/cpuopti: $(OBJ_DIR)/cpuopti.o
	$(CC) $(LDFLAGS) -o $(OBJ_DIR)/cpuopti $(OBJ_DIR)/cpuopti.o
$(OBJ_DIR)/build68k: $(OBJ_DIR)/build68k.o
	$(CC) $(LDFLAGS) -o $(OBJ_DIR)/build68k $(OBJ_DIR)/build68k.o
$(OBJ_DIR)/gencpu: $(OBJ_DIR)/gencpu.o $(OBJ_DIR)/readcpu.o $(OBJ_DIR)/cpudefs.o
	$(CC) $(LDFLAGS) -o $(OBJ_DIR)/gencpu $(OBJ_DIR)/gencpu.o $(OBJ_DIR)/readcpu.o $(OBJ_DIR)/cpudefs.o
cpudefs.cpp: $(OBJ_DIR)/build68k ../uae_cpu/table68k
	$(OBJ_DIR)/build68k <../uae_cpu/table68k >cpudefs.cpp
cpustbl.cpp: cpuemu.cpp
cputbl.h: cpuemu.cpp

cpuemu.cpp: $(OBJ_DIR)/gencpu
	$(OBJ_DIR)/gencpu

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
	$(CXX) $(CPPFLAGSD) $(DEFS) -S $(CXXFLAGS) $< -o cputmp.s
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
#	rm -f cputmp8.s

#-------------------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend depends on it.
