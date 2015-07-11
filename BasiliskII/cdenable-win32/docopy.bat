@echo off
echo.

if "%MYMODE%"=="_MYDEBUG" echo Copying DEBUG binaries ...
if "%MYMODE%"=="_MYRELEASE" echo Copying RELEASE binaries ...

if "%MYMODE%"=="_MYDEBUG" copy L:\DDK\LIB\I386\CHECKED\cdenable.sys e:\Winnt\System32\drivers\*.*
if "%MYMODE%"=="_MYRELEASE" copy L:\DDK\LIB\I386\FREE\cdenable.sys e:\Winnt\System32\drivers\*.*

echo.
echo Creating symbolic info for SoftICE ...

e:
cd \Winnt\System32\drivers
del cdenable.NMS

rem C:\NTICE\nmsym.exe /UNLOAD:cdenable.sys /TRANSLATE:SOURCE,PACKAGE,ALWAYS cdenable.sys /SYMLOAD:cdenable.NMS
"E:\Program Files\NuMega\SoftIceNT\nmsym.exe" /UNLOAD:cdenable.sys /TRANSLATE:SOURCE,PACKAGE,ALWAYS cdenable.sys /SYMLOAD:cdenable.NMS

goto end

:error
echo ERROR: cdenable.sys is still loaded!

:end
pause
