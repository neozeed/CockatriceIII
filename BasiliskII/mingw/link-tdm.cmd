c++ -o CockatriceIII.exe        obj/main.o obj/main_sdl.o obj/prefs.o obj/prefs_dummy.o obj/sys_unix_sdl.o obj/rom_patches.o obj/slot_rom.o obj/rsrc_patches.o obj/emul_op.o obj/macos_util.o obj/xpram.o obj/xpram_dummy.o obj/timer.o obj/timer_common.o obj/clip_dummy.o obj/adb.o obj/serial.o obj/serial_dummy.o obj/ether.o obj/sony.o obj/disk.o obj/cdrom.o obj/scsi.o obj/video.o obj/video_sdl.o obj/audio.o obj/extfs.o obj/user_strings.o obj/user_strings_unix.o obj/sdl_pcap.o obj/scsi_dummy.o obj/audio_sdl.o obj/prefs_editor_dummy.o obj/basilisk_glue.o obj/memory.o obj/newcpu.o obj/readcpu.o obj/cpustbl.o obj/cpudefs.o obj/cpuemu.o obj/fpu_ieee.o cockatricerc.o ..\slirp\libslirp.a ..\drmingw-0.7.7-win32\lib\libexchndl.a -Wl,-Bdynamic -lSDL -lws2_32  -liphlpapi -Wl,-Bstatic -lgcc -lstdc++ -lwinpthread -static -static-libgcc -static-libstdc++