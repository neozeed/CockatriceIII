This is the first public version of Cockatrice (Basalisk is a mythical lizard, so I picked another one at random).

 **** THERE IS A BUG IN PARSING PREF FILES, PUT AN EMPTY LINE or a HASH as the last entry, and everything will be fine!!!!!!!!!!!!!! ****

Enclosed is two executables, and the SDL dll that I'm using (although there is nothing special about it).

What is new in this release of Cockatrice, is that it supports winpcap!  This will allow you to  use native networking.  Although this is more geared to wired networking.  For wireless, use SLiRP.  There is no tun/tap networking in this version.

To setup the winpcap networking, run the program ethlist to determin the network adapters available in your computer.


C:\BasiliskII\mingw>ethlist.exe
Network devices:
  Number       NAME                                     (Description)
  0  \Device\NPF_{6D96D148-9B3D-4AF6-9FC3-1B4987074978} (Local Area Connection)

Press Enter to continue...


In this example there is a single interface.  But due to the nature of Windows, the index number could easily change, but the GUID is what pcap is expecting and for now that is what you have to specifiy in the BasiliskII_Prefs file.

In this example you would add the line:

ether \Device\NPF_{6D96D148-9B3D-4AF6-9FC3-1B4987074978}

And then you shold be good to go.

When you start Cockatrice, you should then see something similar to this:

C:\BasiliskII\mingw>BasiliskII.exe
Basilisk II V0.8 by Christian Bauer et al.
Using Rom [..\test\Quadra800.rom]
Reading ROM file...
EtherInit with \Device\NPF_{6D96D148-9B3D-4AF6-9FC3-1B4987074978}
one or the other 0 0 1!?
Using pcap version [WinPcap version 4.1.3 (packet.dll version 4.1.0.2980), based
 on libpcap version 1.0 branch 1_0_rel0b (20091008)]
Ethernet address fe fd 00 00 17 90
SDL_Audio inited 16bit, 44100Hz, 2 channels


To use the SLiRP (ie user mode NAT) you simply use the statement

ether slirp

And if your MacOS uses DHCP it'll figure out the configuration on it's own.  Otherwise use the folowing address:

IP			10.0.2.15
NetMask			255.255.255.0
Gateway			10.0.2.2
DNS			10.0.2.3

YOU CANNOT PING ANYTHING ON YOUR NETWORK OR THE INTERNET with SLiRP mode.  This is normal, and expected.  If you must ping something to ensure the stack is working, ping 10.0.2.2.  It is the only thing that can ping.

I've done my best to make the SLiRP as stable as possible, but it's possible that it may fail frm time to time. But I've downloaded 150MB files at 67KB/sec without issue.  

Plenty of things are missing from this version, as it is derived from BasiliskII version 0.8.  I am striving to make it 100% SDL reliant for system calls, but for now the os x/Linux and MinGW are more tied to UNIX, while the Visual C++ version is more agnostic.  But for now I'm only happy with the GCC/Clang built versions. 

For me, anyways the following is what I use for a system configuraton:

#######################
#       Quadra 800
modelid 29
rom     ..\test\Quadra800.rom
cpu     4
fpu     false
#
ramsize 67108864
screen win/800/60
nocdrom false
nosound false
nogui true
#######################

I've mostly tested with os 8.0 for internet stuff, and 7.11 for using AppleTalk to communicate with Shoebill, and Windows NT AppleTalk servers.

