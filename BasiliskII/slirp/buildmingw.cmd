@echo off
del /Q *.o
del /Q libslirp.a
gcc -c -Os -I. *.c
ar rcs libslirp.a *.o
del /Q *.o
echo "tada!?"
dir libslirp.a