CDENABLE.SYS: CD driver for Windows NT 4.0 and upwards
------------------------------------------------------

Copy "Cdenable.Sys" to "System32\Drivers" directory.

Function "CdenableSysInstallStart" must be called once
with administrator rights. After that, normal user rights suffice.

Function "CdenableSysStopRemove" must be called when
new version of the driver is updated, followed by
"CdenableSysInstallStart". If not called, the changes will
take effect only after reboot.

Files ntcd.cpp/ntcd.h:
	Interface to the driver. Please read the comments in "ntcd.h" file.
	Rename "ntcd.cpp" -> "ntcd.c" if you wish.

Sample code to obtain the handle needed for
"CdenableSysReadCdBytes" and "CdenableSysReadCdSectors":

	char dname[64];
	HANDLE hcd;

	sprintf(dname,"\\\\.\\%c:",(char)('A' + drive));
	hcd = CreateFile (dname, GENERIC_READ,
                   FILE_SHARE_READ|FILE_SHARE_WRITE,
                   NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
                   NULL);
	if( hcd == INVALID_HANDLE_VALUE ) hcd = 0;
	return(hcd);

Call "CloseHandle" when you no longer need hcd.

The driver uses documented functions only. I expect it to
be fully compatible with NT 5.0, but I have not yet verified that.


11/17/1997
Lauri Pesonen


- ntcd.cpp/ntcd.h: app level interface, found in the folder \BasiliskII\src\Windows\cdenable
- this file was instructions to Cliff, maybe(?)
