@echo off
del /Q cpudefs.c
del /Q cpuemu_31.c
del /Q cpuemu_32.c
del /Q cpustbl.c
del /Q cputbl.h
del /Q *.exe
gcc -std=c99 build68k.c -o build68k
build68k <table68k > cpudefs.c
gcc -std=c99 gencpu.c readcpu.c cpudefs.c -o gencpu
gencpu
gcc -std=c99 -I\pcem\building\mingw\include\SDL\   -c cpuemu_31.c 
gcc -std=c99 -I\pcem\building\mingw\include\SDL\   -c cpuemu_32.c
gcc -std=c99 -I\pcem\building\mingw\include\SDL\   -c cpuemu_common.c
gcc -std=c99 -I\pcem\building\mingw\include\SDL\   -c cpummu030.c
gcc -std=c99 -I\pcem\building\mingw\include\SDL\   -c cpummu.c
gcc -std=c99 -I\pcem\building\mingw\include\SDL\   -c custom.c
gcc -std=c99 -I\pcem\building\mingw\include\SDL\   -c cpustbl.c
gcc -std=c99 -I\pcem\building\mingw\include\SDL\   -c fpp.c
gcc -std=c99 -I\pcem\building\mingw\include\SDL\   -c newcpu.c
gcc -std=c99 -I\pcem\building\mingw\include\SDL\   -c readcpu.c
