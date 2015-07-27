rm -f cpudefs.c
rm -f cpuemu_31.c
rm -f cpuemu_32.c
rm -f cpustbl.c
rm -f cputbl.h
rm -f *.o
rm -f build68k gencpu

gcc -g   -arch i386 -std=c99 build68k.c -o build68k
./build68k <table68k > cpudefs.c
rm -f build68k build68k.o
gcc -g   -arch i386 -std=c99 gencpu.c readcpu.c cpudefs.c -o gencpu
./gencpu
#rm -f gencpu.o readcpu.o cpudefs.o gencpu
rm -f gencpu.o readcpu.o gencpu
gcc -g   -arch i386 -std=c99 -c cpuemu_31.c                                      
gcc -g   -arch i386 -std=c99    -c cpuemu_32.c
gcc -g   -arch i386 -std=c99    -c cpuemu_common.c
gcc -g   -arch i386 -std=c99    -c cpummu030.c
gcc -g   -arch i386 -std=c99    -c cpummu.c
gcc -g   -arch i386 -std=c99    -c custom.c
gcc -g   -arch i386 -std=c99    -c cpustbl.c
gcc -g   -arch i386 -std=c99    -c fpp.c
gcc -g   -arch i386 -std=c99    -c newcpu.c
gcc -g   -arch i386 -std=c99    -c readcpu.c
gcc -g   -arch i386 -std=c99    -c cpudefs.c
gcc -g   -arch i386 -std=c99    -c memory.c
gcc -g  -arch i386 -std=c99    -c missing.c
gcc -g   -arch i386 *.o -o xx
