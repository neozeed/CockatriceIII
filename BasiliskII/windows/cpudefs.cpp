#include "sysdeps.h"
#include "readcpu.h"
struct instr_def defs68k[] = {
{ 60, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 0, 0, { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }  }, 16, "ORSR.B  #1"},
{ 124, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 0, 2, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "ORSR.W  #1"},
{ 192, 8, {17,17,11,11,11,12,12,12,0,0,0,0,0,0,0,0}, 63936, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 17, "CHK2.z  #1,s[!Dreg,Areg,Aipi,Apdi,Immd]"},
{ 0, 8, {17,17,13,13,13,14,14,14,0,0,0,0,0,0,0,0}, 65280, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 19, "OR.z    #z,d[!Areg]"},
{ 572, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 0, 0, { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }  }, 16, "ANDSR.B #1"},
{ 636, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 0, 2, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "ANDSR.W #1"},
{ 512, 8, {17,17,13,13,13,14,14,14,0,0,0,0,0,0,0,0}, 65280, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 19, "AND.z   #z,d[!Areg]"},
{ 1024, 8, {17,17,13,13,13,14,14,14,0,0,0,0,0,0,0,0}, 65280, 0, 0, { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 19, "SUB.z   #z,d[!Areg]"},
{ 1536, 8, {17,17,13,13,13,14,14,14,0,0,0,0,0,0,0,0}, 65280, 0, 0, { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 19, "ADD.z   #z,d[!Areg]"},
{ 1728, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "CALLM   s[!Dreg,Areg,Aipi,Apdi,Immd]"},
{ 1728, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "RTM     s[Dreg,Areg]"},
{ 2048, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 0 }, { 1, 1 }, { 1, 1 }  }, 17, "BTST    #1,s[!Areg]"},
{ 2112, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 0 }, { 1, 1 }, { 1, 1 }  }, 19, "BCHG    #1,s[!Areg,Immd]"},
{ 2176, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 0 }, { 1, 1 }, { 1, 1 }  }, 19, "BCLR    #1,s[!Areg,Immd]"},
{ 2240, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 0 }, { 1, 1 }, { 1, 1 }  }, 19, "BSET    #1,s[!Areg,Immd]"},
{ 2620, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 0, 0, { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }  }, 16, "EORSR.B #1"},
{ 2684, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 0, 2, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "EORSR.W #1"},
{ 2560, 8, {17,17,13,13,13,14,14,14,0,0,0,0,0,0,0,0}, 65280, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 19, "EOR.z   #z,d[!Areg]"},
{ 3072, 8, {17,17,11,11,11,12,12,12,0,0,0,0,0,0,0,0}, 65280, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 17, "CMP.z   #z,s[!Areg,Immd]"},
{ 2752, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 19, "CAS.B   #1,s[!Dreg,Areg,Immd,PC8r,PC16]"},
{ 3264, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 19, "CAS.W   #1,s[!Dreg,Areg,Immd,PC8r,PC16]"},
{ 3324, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "CAS2.W  #2"},
{ 3584, 8, {17,17,11,11,11,12,12,12,0,0,0,0,0,0,0,0}, 65280, 2, 2, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 19, "MOVES.z #1,s[!Dreg,Areg,Immd,PC8r,PC16]"},
{ 3776, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 19, "CAS.L   #1,s[!Dreg,Areg,Immd,PC8r,PC16]"},
{ 3836, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "CAS2.L  #2"},
{ 256, 9, {15,15,15,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 18, "MVPMR.W d[Areg-Ad16],Dr"},
{ 320, 9, {15,15,15,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 18, "MVPMR.L d[Areg-Ad16],Dr"},
{ 384, 9, {15,15,15,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 18, "MVPRM.W Dr,d[Areg-Ad16]"},
{ 448, 9, {15,15,15,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 18, "MVPRM.L Dr,d[Areg-Ad16]"},
{ 256, 9, {15,15,15,11,11,11,12,12,12,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 0 }, { 1, 1 }, { 1, 1 }  }, 17, "BTST    Dr,s[!Areg]"},
{ 320, 9, {15,15,15,11,11,11,12,12,12,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 0 }, { 1, 1 }, { 1, 1 }  }, 19, "BCHG    Dr,s[!Areg,Immd]"},
{ 384, 9, {15,15,15,11,11,11,12,12,12,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 0 }, { 1, 1 }, { 1, 1 }  }, 19, "BCLR    Dr,s[!Areg,Immd]"},
{ 448, 9, {15,15,15,11,11,11,12,12,12,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 0 }, { 1, 1 }, { 1, 1 }  }, 19, "BSET    Dr,s[!Areg,Immd]"},
{ 4096, 12, {14,14,14,13,13,13,11,11,11,12,12,12,0,0,0,0}, 61440, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 18, "MOVE.B  s,d[!Areg]"},
{ 8192, 12, {14,14,14,13,13,13,11,11,11,12,12,12,0,0,0,0}, 61440, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 18, "MOVEA.L s,d[Areg]"},
{ 8192, 12, {14,14,14,13,13,13,11,11,11,12,12,12,0,0,0,0}, 61440, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 18, "MOVE.L  s,d[!Areg]"},
{ 12288, 12, {14,14,14,13,13,13,11,11,11,12,12,12,0,0,0,0}, 61440, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 18, "MOVEA.W s,d[Areg]"},
{ 12288, 12, {14,14,14,13,13,13,11,11,11,12,12,12,0,0,0,0}, 61440, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 18, "MOVE.W  s,d[!Areg]"},
{ 16384, 8, {17,17,13,13,13,14,14,14,0,0,0,0,0,0,0,0}, 65280, 0, 0, { { 1, 0 }, { 1, 4 }, { 1, 0 }, { 1, 4 }, { 1, 0 }  }, 48, "NEGX.z  d[!Areg]"},
{ 16576, 6, {13,13,13,14,14,14,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 1, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "MVSR2.W d[!Areg]"},
{ 16896, 8, {17,17,13,13,13,14,14,14,0,0,0,0,0,0,0,0}, 65280, 0, 0, { { 1, 1 }, { 1, 2 }, { 1, 3 }, { 1, 2 }, { 1, 2 }  }, 32, "CLR.z   d[!Areg]"},
{ 17088, 6, {13,13,13,14,14,14,0,0,0,0,0,0,0,0,0,0}, 65472, 1, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "MVSR2.B d[!Areg]"},
{ 17408, 8, {17,17,13,13,13,14,14,14,0,0,0,0,0,0,0,0}, 65280, 0, 0, { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 48, "NEG.z   d[!Areg]"},
{ 17600, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 16, "MV2SR.B s[!Areg]"},
{ 17920, 8, {17,17,13,13,13,14,14,14,0,0,0,0,0,0,0,0}, 65280, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 48, "NOT.z   d[!Areg]"},
{ 18112, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 2, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "MV2SR.W s[!Areg]"},
{ 18440, 3, {15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65528, 2, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 49, "LINK.L  Ar,#2"},
{ 18432, 6, {13,13,13,14,14,14,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 0, 0 }, { 1, 5 }, { 0, 0 }, { 1, 5 }, { 1, 0 }  }, 48, "NBCD.B  d[!Areg]"},
{ 18504, 3, {9,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65528, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "BKPT    #k"},
{ 18496, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 48, "SWAP.W  s[Dreg]"},
{ 18496, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 0, "PEA.L   s[!Dreg,Areg,Aipi,Apdi,Immd]"},
{ 18560, 6, {13,13,13,14,14,14,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 48, "EXT.W   d[Dreg]"},
{ 18560, 6, {13,13,13,14,14,14,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 2, "MVMLE.W #1,d[!Dreg,Areg,Aipi]"},
{ 18624, 6, {13,13,13,14,14,14,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 48, "EXT.L   d[Dreg]"},
{ 18624, 6, {13,13,13,14,14,14,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 2, "MVMLE.L #1,d[!Dreg,Areg,Aipi]"},
{ 18880, 6, {13,13,13,14,14,14,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 48, "EXT.B   d[Dreg]"},
{ 18944, 8, {17,17,11,11,11,12,12,12,0,0,0,0,0,0,0,0}, 65280, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 16, "TST.z   s"},
{ 19136, 6, {13,13,13,14,14,14,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 48, "TAS.B   d[!Areg]"},
{ 19196, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 0, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 0, "ILLEGAL"},
{ 19456, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 2, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 19, "MULL.L  #1,s[!Areg]"},
{ 19520, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 19, "DIVL.L  #1,s[!Areg]"},
{ 19584, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 1, "MVMEL.W #1,s[!Dreg,Areg,Apdi,Immd]"},
{ 19648, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 1, "MVMEL.L #1,s[!Dreg,Areg,Apdi,Immd]"},
{ 20032, 4, {8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0}, 65520, 0, 0, { { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }  }, 16, "TRAP    #J"},
{ 20048, 3, {15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65528, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 49, "LINK.W  Ar,#1"},
{ 20056, 3, {15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65528, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 48, "UNLK.L  Ar"},
{ 20064, 3, {15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65528, 0, 2, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 16, "MVR2USP.L Ar"},
{ 20072, 3, {15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65528, 0, 2, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 32, "MVUSP2R.L Ar"},
{ 20080, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 0, 2, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 0, "RESET"},
{ 20081, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 0, "NOP"},
{ 20082, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 0, 2, { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 16, "STOP    #1"},
{ 20083, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 0, 2, { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 0, "RTE"},
{ 20084, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 0, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "RTD     #1"},
{ 20085, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 0, "RTS"},
{ 20086, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 0, 0, { { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }  }, 0, "TRAPV"},
{ 20087, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 0, 0, { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 0, "RTR"},
{ 20090, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 1, 2, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "MOVEC2  #1"},
{ 20091, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 1, 2, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "MOVE2C  #1"},
{ 20096, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 4, 6 }, { 4, 6 }, { 4, 6 }, { 4, 6 }, { 4, 6 }  }, 128, "JSR.L   s[!Dreg,Areg,Aipi,Apdi,Immd]"},
{ 16640, 9, {15,15,15,11,11,11,12,12,12,0,0,0,0,0,0,0}, 61888, 0, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 17, "CHK.L   s[!Areg],Dr"},
{ 16768, 9, {15,15,15,11,11,11,12,12,12,0,0,0,0,0,0,0}, 61888, 0, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 17, "CHK.W   s[!Areg],Dr"},
{ 20160, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 0, 0, { { 4, 6 }, { 4, 6 }, { 4, 6 }, { 4, 6 }, { 4, 6 }  }, 128, "JMP.L   s[!Dreg,Areg,Aipi,Apdi,Immd]"},
{ 16832, 9, {15,15,15,11,11,11,12,12,12,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 2, "LEA.L   s[!Dreg,Areg,Aipi,Apdi,Immd],Ar"},
{ 20544, 9, {7,7,7,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 19, "ADDA.W  #j,d[Areg]"},
{ 20608, 9, {7,7,7,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 19, "ADDA.L  #j,d[Areg]"},
{ 20480, 11, {7,7,7,17,17,13,13,13,14,14,14,0,0,0,0,0}, 61696, 0, 0, { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 19, "ADD.z   #j,d[!Areg]"},
{ 20800, 9, {7,7,7,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 19, "SUBA.W  #j,d[Areg]"},
{ 20864, 9, {7,7,7,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 19, "SUBA.L  #j,d[Areg]"},
{ 20736, 11, {7,7,7,17,17,13,13,13,14,14,14,0,0,0,0,0}, 61696, 0, 0, { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 19, "SUB.z   #j,d[!Areg]"},
{ 20680, 7, {2,2,2,2,15,15,15,0,0,0,0,0,0,0,0,0}, 61688, 0, 0, { { 2, 1 }, { 2, 1 }, { 2, 1 }, { 2, 1 }, { 2, 1 }  }, 49, "DBcc.W  Dr,#1"},
{ 20672, 10, {2,2,2,2,13,13,13,14,14,14,0,0,0,0,0,0}, 61632, 0, 0, { { 2, 1 }, { 2, 1 }, { 2, 1 }, { 2, 1 }, { 2, 1 }  }, 32, "Scc.B   d[!Areg]"},
{ 20730, 4, {2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0}, 61695, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "TRAPcc  #1"},
{ 20731, 4, {2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0}, 61695, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "TRAPcc  #2"},
{ 20732, 4, {2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0}, 61695, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 0, "TRAPcc"},
{ 24832, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 0, 0, { { 4, 6 }, { 4, 6 }, { 4, 6 }, { 4, 6 }, { 4, 6 }  }, 64, "BSR.W   #1"},
{ 24832, 8, {6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0}, 65280, 0, 0, { { 4, 6 }, { 4, 6 }, { 4, 6 }, { 4, 6 }, { 4, 6 }  }, 64, "BSR.B   #i"},
{ 25087, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 0, 0, { { 4, 6 }, { 4, 6 }, { 4, 6 }, { 4, 6 }, { 4, 6 }  }, 64, "BSR.L   #2"},
{ 24576, 4, {3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0}, 61695, 0, 0, { { 2, 1 }, { 2, 1 }, { 2, 1 }, { 2, 1 }, { 2, 1 }  }, 64, "Bcc.W   #1"},
{ 24576, 12, {3,3,3,3,6,6,6,6,6,6,6,6,0,0,0,0}, 61440, 0, 0, { { 2, 1 }, { 2, 1 }, { 2, 1 }, { 2, 1 }, { 2, 1 }  }, 64, "Bcc.B   #i"},
{ 24831, 4, {3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0}, 61695, 0, 0, { { 2, 1 }, { 2, 1 }, { 2, 1 }, { 2, 1 }, { 2, 1 }  }, 64, "Bcc.L   #2"},
{ 28672, 11, {15,15,15,5,5,5,5,5,5,5,5,0,0,0,0,0}, 61696, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 18, "MOVE.L  #i,Dr"},
{ 32768, 11, {15,15,15,17,17,11,11,11,12,12,12,0,0,0,0,0}, 61696, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 19, "OR.z    s[!Areg],Dr"},
{ 32960, 9, {15,15,15,11,11,11,12,12,12,0,0,0,0,0,0,0}, 61888, 0, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 19, "DIVU.W  s[!Areg],Dr"},
{ 33024, 9, {15,15,15,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 0, 0, { { 0, 0 }, { 1, 4 }, { 0, 0 }, { 1, 4 }, { 1, 0 }  }, 19, "SBCD.B  d[Dreg],Dr"},
{ 33024, 9, {15,15,15,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 0, 0, { { 0, 0 }, { 1, 4 }, { 0, 0 }, { 1, 4 }, { 1, 0 }  }, 19, "SBCD.B  d[Areg-Apdi],Arp"},
{ 33024, 11, {15,15,15,17,17,13,13,13,14,14,14,0,0,0,0,0}, 61696, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 19, "OR.z    Dr,d[!Areg,Dreg]"},
{ 33088, 9, {15,15,15,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 18, "PACK    d[Dreg],Dr"},
{ 33088, 9, {15,15,15,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 18, "PACK    d[Areg-Apdi],Arp"},
{ 33152, 9, {15,15,15,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 18, "UNPK    d[Dreg],Dr"},
{ 33152, 9, {15,15,15,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 18, "UNPK    d[Areg-Apdi],Arp"},
{ 33216, 9, {15,15,15,11,11,11,12,12,12,0,0,0,0,0,0,0}, 61888, 0, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 19, "DIVS.W  s[!Areg],Dr"},
{ 36864, 11, {15,15,15,17,17,11,11,11,12,12,12,0,0,0,0,0}, 61696, 0, 0, { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 19, "SUB.z   s,Dr"},
{ 37056, 9, {15,15,15,11,11,11,12,12,12,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 19, "SUBA.W  s,Ar"},
{ 37120, 11, {15,15,15,17,17,13,13,13,14,14,14,0,0,0,0,0}, 61696, 0, 0, { { 0, 0 }, { 1, 0 }, { 0, 0 }, { 1, 0 }, { 1, 0 }  }, 19, "SUBX.z  d[Dreg],Dr"},
{ 37120, 11, {15,15,15,17,17,13,13,13,14,14,14,0,0,0,0,0}, 61696, 0, 0, { { 0, 0 }, { 1, 0 }, { 0, 0 }, { 1, 0 }, { 1, 0 }  }, 19, "SUBX.z  d[Areg-Apdi],Arp"},
{ 37120, 11, {15,15,15,17,17,13,13,13,14,14,14,0,0,0,0,0}, 61696, 0, 0, { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 19, "SUB.z   Dr,d[!Areg,Dreg]"},
{ 37312, 9, {15,15,15,11,11,11,12,12,12,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 19, "SUBA.L  s,Ar"},
{ 45056, 11, {15,15,15,17,17,11,11,11,12,12,12,0,0,0,0,0}, 61696, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 17, "CMP.z   s,Dr"},
{ 45248, 9, {15,15,15,11,11,11,12,12,12,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 17, "CMPA.W  s,Ar"},
{ 45504, 9, {15,15,15,11,11,11,12,12,12,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 17, "CMPA.L  s,Ar"},
{ 45312, 11, {15,15,15,17,17,13,13,13,14,14,14,0,0,0,0,0}, 61696, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 17, "CMPM.z  d[Areg-Aipi],ArP"},
{ 45312, 11, {15,15,15,17,17,13,13,13,14,14,14,0,0,0,0,0}, 61696, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 19, "EOR.z   Dr,d[!Areg]"},
{ 49152, 11, {15,15,15,17,17,11,11,11,12,12,12,0,0,0,0,0}, 61696, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 19, "AND.z   s[!Areg],Dr"},
{ 49344, 9, {15,15,15,11,11,11,12,12,12,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 19, "MULU.W  s[!Areg],Dr"},
{ 49408, 9, {15,15,15,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 0, 0, { { 0, 0 }, { 1, 4 }, { 0, 0 }, { 1, 4 }, { 1, 0 }  }, 19, "ABCD.B  d[Dreg],Dr"},
{ 49408, 9, {15,15,15,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 0, 0, { { 0, 0 }, { 1, 4 }, { 0, 0 }, { 1, 4 }, { 1, 0 }  }, 19, "ABCD.B  d[Areg-Apdi],Arp"},
{ 49408, 11, {15,15,15,17,17,13,13,13,14,14,14,0,0,0,0,0}, 61696, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 19, "AND.z   Dr,d[!Areg,Dreg]"},
{ 49472, 9, {15,15,15,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 51, "EXG.L   Dr,d[Dreg]"},
{ 49472, 9, {15,15,15,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 51, "EXG.L   Ar,d[Areg]"},
{ 49536, 9, {15,15,15,13,13,13,14,14,14,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 51, "EXG.L   Dr,d[Areg]"},
{ 49600, 9, {15,15,15,11,11,11,12,12,12,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 2 }  }, 19, "MULS.W  s[!Areg],Dr"},
{ 53248, 11, {15,15,15,17,17,11,11,11,12,12,12,0,0,0,0,0}, 61696, 0, 0, { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 19, "ADD.z   s,Dr"},
{ 53440, 9, {15,15,15,11,11,11,12,12,12,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 19, "ADDA.W  s,Ar"},
{ 53504, 11, {15,15,15,17,17,13,13,13,14,14,14,0,0,0,0,0}, 61696, 0, 0, { { 0, 0 }, { 1, 0 }, { 0, 0 }, { 1, 0 }, { 1, 0 }  }, 19, "ADDX.z  d[Dreg],Dr"},
{ 53504, 11, {15,15,15,17,17,13,13,13,14,14,14,0,0,0,0,0}, 61696, 0, 0, { { 0, 0 }, { 1, 0 }, { 0, 0 }, { 1, 0 }, { 1, 0 }  }, 19, "ADDX.z  d[Areg-Apdi],Arp"},
{ 53504, 11, {15,15,15,17,17,13,13,13,14,14,14,0,0,0,0,0}, 61696, 0, 0, { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 19, "ADD.z   Dr,d[!Areg,Dreg]"},
{ 53696, 9, {15,15,15,11,11,11,12,12,12,0,0,0,0,0,0,0}, 61888, 0, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 19, "ADDA.L  s,Ar"},
{ 57344, 9, {7,7,7,4,17,17,16,16,16,0,0,0,0,0,0,0}, 61496, 0, 0, { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 19, "ASf.z   #j,DR"},
{ 57352, 9, {7,7,7,4,17,17,16,16,16,0,0,0,0,0,0,0}, 61496, 0, 0, { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 0 }  }, 19, "LSf.z   #j,DR"},
{ 57360, 9, {7,7,7,4,17,17,16,16,16,0,0,0,0,0,0,0}, 61496, 0, 0, { { 0, 0 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 0 }  }, 19, "ROXf.z  #j,DR"},
{ 57368, 9, {7,7,7,4,17,17,16,16,16,0,0,0,0,0,0,0}, 61496, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 0 }  }, 19, "ROf.z   #j,DR"},
{ 57376, 9, {15,15,15,4,17,17,16,16,16,0,0,0,0,0,0,0}, 61496, 0, 0, { { 0, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 19, "ASf.z   Dr,DR"},
{ 57384, 9, {15,15,15,4,17,17,16,16,16,0,0,0,0,0,0,0}, 61496, 0, 0, { { 0, 0 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 0 }  }, 19, "LSf.z   Dr,DR"},
{ 57392, 9, {15,15,15,4,17,17,16,16,16,0,0,0,0,0,0,0}, 61496, 0, 0, { { 0, 0 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 0 }  }, 19, "ROXf.z  Dr,DR"},
{ 57400, 9, {15,15,15,4,17,17,16,16,16,0,0,0,0,0,0,0}, 61496, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 0 }  }, 19, "ROf.z   Dr,DR"},
{ 57536, 7, {4,13,13,13,14,14,14,0,0,0,0,0,0,0,0,0}, 65216, 0, 0, { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 0 }  }, 19, "ASfW.W  d[!Dreg,Areg]"},
{ 58048, 7, {4,13,13,13,14,14,14,0,0,0,0,0,0,0,0,0}, 65216, 0, 0, { { 1, 0 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 0 }  }, 19, "LSfW.W  d[!Dreg,Areg]"},
{ 58560, 7, {4,13,13,13,14,14,14,0,0,0,0,0,0,0,0,0}, 65216, 0, 0, { { 0, 0 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 0 }  }, 19, "ROXfW.W d[!Dreg,Areg]"},
{ 59072, 7, {4,13,13,13,14,14,14,0,0,0,0,0,0,0,0,0}, 65216, 0, 0, { { 1, 1 }, { 1, 0 }, { 1, 0 }, { 1, 2 }, { 1, 0 }  }, 19, "ROfW.W  d[!Dreg,Areg]"},
{ 59584, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 17, "BFTST   #1,s[!Areg,Apdi,Aipi,Immd]"},
{ 59840, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 17, "BFEXTU  #1,s[!Areg,Apdi,Aipi,Immd]"},
{ 60096, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 19, "BFCHG   #1,s[!Areg,Apdi,Aipi,Immd,PC8r,PC16]"},
{ 60352, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 17, "BFEXTS  #1,s[!Areg,Apdi,Aipi,Immd]"},
{ 60608, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 19, "BFCLR   #1,s[!Areg,Apdi,Aipi,Immd,PC8r,PC16]"},
{ 60864, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 17, "BFFFO   #1,s[!Areg,Apdi,Aipi,Immd]"},
{ 61120, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 19, "BFSET   #1,s[!Areg,Apdi,Aipi,Immd,PC8r,PC16]"},
{ 61376, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 2, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 19, "BFINS   #1,s[!Areg,Apdi,Aipi,Immd,PC8r,PC16]"},
{ 61952, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 3, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 17, "FPP      #1,s"},
{ 62016, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 3, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 17, "FDBcc    #1,s[Areg-Dreg]"},
{ 62016, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 3, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 17, "FScc     #1,s[!Areg,Immd,PC8r,PC16]"},
{ 62074, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 3, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "FTRAPcc  #1"},
{ 62075, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 3, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "FTRAPcc  #2"},
{ 62076, 0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65535, 3, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 0, "FTRAPcc"},
{ 62080, 6, {10,10,10,10,10,10,0,0,0,0,0,0,0,0,0,0}, 65472, 3, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 17, "FBcc     #K,#1"},
{ 62144, 6, {10,10,10,10,10,10,0,0,0,0,0,0,0,0,0,0}, 65472, 3, 0, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 17, "FBcc     #K,#2"},
{ 62208, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 3, 2, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 32, "FSAVE    s[!Dreg,Areg,Aipi,Immd,PC8r,PC16]"},
{ 62272, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 3, 2, { { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }, { 3, 5 }  }, 16, "FRESTORE s[!Dreg,Areg,Apdi,Immd]"},
{ 62472, 5, {18,18,15,15,15,0,0,0,0,0,0,0,0,0,0,0}, 65336, 4, 2, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 2, "CINVL    #p,Ar"},
{ 62480, 5, {18,18,15,15,15,0,0,0,0,0,0,0,0,0,0,0}, 65336, 4, 2, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 2, "CINVP    #p,Ar"},
{ 62488, 5, {18,18,15,15,15,0,0,0,0,0,0,0,0,0,0,0}, 65336, 4, 2, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 0, "CINVA    #p"},
{ 62504, 5, {18,18,15,15,15,0,0,0,0,0,0,0,0,0,0,0}, 65336, 4, 2, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 2, "CPUSHL   #p,Ar"},
{ 62512, 5, {18,18,15,15,15,0,0,0,0,0,0,0,0,0,0,0}, 65336, 4, 2, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 2, "CPUSHP   #p,Ar"},
{ 62520, 5, {18,18,15,15,15,0,0,0,0,0,0,0,0,0,0,0}, 65336, 4, 2, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 0, "CPUSHA   #p"},
{ 63008, 3, {15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0}, 65528, 4, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 18, "MOVE16   ArP,ARP"},
{ 62976, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 4, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 18, "MOVE16   s[Dreg-Aipi],Al"},
{ 62976, 6, {13,13,13,14,14,14,0,0,0,0,0,0,0,0,0,0}, 65472, 4, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 18, "MOVE16   Al,d[Areg-Aipi]"},
{ 62976, 6, {11,11,11,12,12,12,0,0,0,0,0,0,0,0,0,0}, 65472, 4, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 18, "MOVE16   s[Aind],Al"},
{ 62976, 6, {13,13,13,14,14,14,0,0,0,0,0,0,0,0,0,0}, 65472, 4, 0, { { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 1 }  }, 18, "MOVE16   Al,d[Aipi-Aind]"}};
int n_defs68k = 178;
