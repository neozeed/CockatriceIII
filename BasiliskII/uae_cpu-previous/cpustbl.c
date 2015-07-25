#include "sysconfig.h"
#include "sysdeps.h"
#include "options_cpu.h"
#include "memory.h"
#include "custom.h"
#include "events.h"
#include "newcpu.h"
#include "cpu_prefetch.h"
#include "cputbl.h"
#define CPUFUNC(x) x##_ff
#define SET_CFLG_ALWAYS(x) SET_CFLG(x)
#define SET_NFLG_ALWAYS(x) SET_NFLG(x)
#ifdef NOFLAGS
#include "noflags.h"
#endif
#ifdef CPUEMU_31
#ifndef CPUEMU_68000_ONLY
const struct cputbl CPUFUNC(op_smalltbl_31)[] = {
{ CPUFUNC(op_0000_31), 0 }, /* OR */
{ CPUFUNC(op_0010_31), 16 }, /* OR */
{ CPUFUNC(op_0018_31), 24 }, /* OR */
{ CPUFUNC(op_0020_31), 32 }, /* OR */
{ CPUFUNC(op_0028_31), 40 }, /* OR */
{ CPUFUNC(op_0030_31), 48 }, /* OR */
{ CPUFUNC(op_0038_31), 56 }, /* OR */
{ CPUFUNC(op_0039_31), 57 }, /* OR */
{ CPUFUNC(op_003c_31), 60 }, /* ORSR */
{ CPUFUNC(op_0040_31), 64 }, /* OR */
{ CPUFUNC(op_0050_31), 80 }, /* OR */
{ CPUFUNC(op_0058_31), 88 }, /* OR */
{ CPUFUNC(op_0060_31), 96 }, /* OR */
{ CPUFUNC(op_0068_31), 104 }, /* OR */
{ CPUFUNC(op_0070_31), 112 }, /* OR */
{ CPUFUNC(op_0078_31), 120 }, /* OR */
{ CPUFUNC(op_0079_31), 121 }, /* OR */
{ CPUFUNC(op_007c_31), 124 }, /* ORSR */
{ CPUFUNC(op_0080_31), 128 }, /* OR */
{ CPUFUNC(op_0090_31), 144 }, /* OR */
{ CPUFUNC(op_0098_31), 152 }, /* OR */
{ CPUFUNC(op_00a0_31), 160 }, /* OR */
{ CPUFUNC(op_00a8_31), 168 }, /* OR */
{ CPUFUNC(op_00b0_31), 176 }, /* OR */
{ CPUFUNC(op_00b8_31), 184 }, /* OR */
{ CPUFUNC(op_00b9_31), 185 }, /* OR */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_00d0_31), 208 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_00e8_31), 232 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_00f0_31), 240 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_00f8_31), 248 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_00f9_31), 249 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_00fa_31), 250 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_00fb_31), 251 }, /* CHK2 */
#endif
{ CPUFUNC(op_0100_31), 256 }, /* BTST */
{ CPUFUNC(op_0108_31), 264 }, /* MVPMR */
{ CPUFUNC(op_0110_31), 272 }, /* BTST */
{ CPUFUNC(op_0118_31), 280 }, /* BTST */
{ CPUFUNC(op_0120_31), 288 }, /* BTST */
{ CPUFUNC(op_0128_31), 296 }, /* BTST */
{ CPUFUNC(op_0130_31), 304 }, /* BTST */
{ CPUFUNC(op_0138_31), 312 }, /* BTST */
{ CPUFUNC(op_0139_31), 313 }, /* BTST */
{ CPUFUNC(op_013a_31), 314 }, /* BTST */
{ CPUFUNC(op_013b_31), 315 }, /* BTST */
{ CPUFUNC(op_013c_31), 316 }, /* BTST */
{ CPUFUNC(op_0140_31), 320 }, /* BCHG */
{ CPUFUNC(op_0148_31), 328 }, /* MVPMR */
{ CPUFUNC(op_0150_31), 336 }, /* BCHG */
{ CPUFUNC(op_0158_31), 344 }, /* BCHG */
{ CPUFUNC(op_0160_31), 352 }, /* BCHG */
{ CPUFUNC(op_0168_31), 360 }, /* BCHG */
{ CPUFUNC(op_0170_31), 368 }, /* BCHG */
{ CPUFUNC(op_0178_31), 376 }, /* BCHG */
{ CPUFUNC(op_0179_31), 377 }, /* BCHG */
{ CPUFUNC(op_0180_31), 384 }, /* BCLR */
{ CPUFUNC(op_0188_31), 392 }, /* MVPRM */
{ CPUFUNC(op_0190_31), 400 }, /* BCLR */
{ CPUFUNC(op_0198_31), 408 }, /* BCLR */
{ CPUFUNC(op_01a0_31), 416 }, /* BCLR */
{ CPUFUNC(op_01a8_31), 424 }, /* BCLR */
{ CPUFUNC(op_01b0_31), 432 }, /* BCLR */
{ CPUFUNC(op_01b8_31), 440 }, /* BCLR */
{ CPUFUNC(op_01b9_31), 441 }, /* BCLR */
{ CPUFUNC(op_01c0_31), 448 }, /* BSET */
{ CPUFUNC(op_01c8_31), 456 }, /* MVPRM */
{ CPUFUNC(op_01d0_31), 464 }, /* BSET */
{ CPUFUNC(op_01d8_31), 472 }, /* BSET */
{ CPUFUNC(op_01e0_31), 480 }, /* BSET */
{ CPUFUNC(op_01e8_31), 488 }, /* BSET */
{ CPUFUNC(op_01f0_31), 496 }, /* BSET */
{ CPUFUNC(op_01f8_31), 504 }, /* BSET */
{ CPUFUNC(op_01f9_31), 505 }, /* BSET */
{ CPUFUNC(op_0200_31), 512 }, /* AND */
{ CPUFUNC(op_0210_31), 528 }, /* AND */
{ CPUFUNC(op_0218_31), 536 }, /* AND */
{ CPUFUNC(op_0220_31), 544 }, /* AND */
{ CPUFUNC(op_0228_31), 552 }, /* AND */
{ CPUFUNC(op_0230_31), 560 }, /* AND */
{ CPUFUNC(op_0238_31), 568 }, /* AND */
{ CPUFUNC(op_0239_31), 569 }, /* AND */
{ CPUFUNC(op_023c_31), 572 }, /* ANDSR */
{ CPUFUNC(op_0240_31), 576 }, /* AND */
{ CPUFUNC(op_0250_31), 592 }, /* AND */
{ CPUFUNC(op_0258_31), 600 }, /* AND */
{ CPUFUNC(op_0260_31), 608 }, /* AND */
{ CPUFUNC(op_0268_31), 616 }, /* AND */
{ CPUFUNC(op_0270_31), 624 }, /* AND */
{ CPUFUNC(op_0278_31), 632 }, /* AND */
{ CPUFUNC(op_0279_31), 633 }, /* AND */
{ CPUFUNC(op_027c_31), 636 }, /* ANDSR */
{ CPUFUNC(op_0280_31), 640 }, /* AND */
{ CPUFUNC(op_0290_31), 656 }, /* AND */
{ CPUFUNC(op_0298_31), 664 }, /* AND */
{ CPUFUNC(op_02a0_31), 672 }, /* AND */
{ CPUFUNC(op_02a8_31), 680 }, /* AND */
{ CPUFUNC(op_02b0_31), 688 }, /* AND */
{ CPUFUNC(op_02b8_31), 696 }, /* AND */
{ CPUFUNC(op_02b9_31), 697 }, /* AND */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_02d0_31), 720 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_02e8_31), 744 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_02f0_31), 752 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_02f8_31), 760 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_02f9_31), 761 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_02fa_31), 762 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_02fb_31), 763 }, /* CHK2 */
#endif
{ CPUFUNC(op_0400_31), 1024 }, /* SUB */
{ CPUFUNC(op_0410_31), 1040 }, /* SUB */
{ CPUFUNC(op_0418_31), 1048 }, /* SUB */
{ CPUFUNC(op_0420_31), 1056 }, /* SUB */
{ CPUFUNC(op_0428_31), 1064 }, /* SUB */
{ CPUFUNC(op_0430_31), 1072 }, /* SUB */
{ CPUFUNC(op_0438_31), 1080 }, /* SUB */
{ CPUFUNC(op_0439_31), 1081 }, /* SUB */
{ CPUFUNC(op_0440_31), 1088 }, /* SUB */
{ CPUFUNC(op_0450_31), 1104 }, /* SUB */
{ CPUFUNC(op_0458_31), 1112 }, /* SUB */
{ CPUFUNC(op_0460_31), 1120 }, /* SUB */
{ CPUFUNC(op_0468_31), 1128 }, /* SUB */
{ CPUFUNC(op_0470_31), 1136 }, /* SUB */
{ CPUFUNC(op_0478_31), 1144 }, /* SUB */
{ CPUFUNC(op_0479_31), 1145 }, /* SUB */
{ CPUFUNC(op_0480_31), 1152 }, /* SUB */
{ CPUFUNC(op_0490_31), 1168 }, /* SUB */
{ CPUFUNC(op_0498_31), 1176 }, /* SUB */
{ CPUFUNC(op_04a0_31), 1184 }, /* SUB */
{ CPUFUNC(op_04a8_31), 1192 }, /* SUB */
{ CPUFUNC(op_04b0_31), 1200 }, /* SUB */
{ CPUFUNC(op_04b8_31), 1208 }, /* SUB */
{ CPUFUNC(op_04b9_31), 1209 }, /* SUB */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_04d0_31), 1232 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_04e8_31), 1256 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_04f0_31), 1264 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_04f8_31), 1272 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_04f9_31), 1273 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_04fa_31), 1274 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_04fb_31), 1275 }, /* CHK2 */
#endif
{ CPUFUNC(op_0600_31), 1536 }, /* ADD */
{ CPUFUNC(op_0610_31), 1552 }, /* ADD */
{ CPUFUNC(op_0618_31), 1560 }, /* ADD */
{ CPUFUNC(op_0620_31), 1568 }, /* ADD */
{ CPUFUNC(op_0628_31), 1576 }, /* ADD */
{ CPUFUNC(op_0630_31), 1584 }, /* ADD */
{ CPUFUNC(op_0638_31), 1592 }, /* ADD */
{ CPUFUNC(op_0639_31), 1593 }, /* ADD */
{ CPUFUNC(op_0640_31), 1600 }, /* ADD */
{ CPUFUNC(op_0650_31), 1616 }, /* ADD */
{ CPUFUNC(op_0658_31), 1624 }, /* ADD */
{ CPUFUNC(op_0660_31), 1632 }, /* ADD */
{ CPUFUNC(op_0668_31), 1640 }, /* ADD */
{ CPUFUNC(op_0670_31), 1648 }, /* ADD */
{ CPUFUNC(op_0678_31), 1656 }, /* ADD */
{ CPUFUNC(op_0679_31), 1657 }, /* ADD */
{ CPUFUNC(op_0680_31), 1664 }, /* ADD */
{ CPUFUNC(op_0690_31), 1680 }, /* ADD */
{ CPUFUNC(op_0698_31), 1688 }, /* ADD */
{ CPUFUNC(op_06a0_31), 1696 }, /* ADD */
{ CPUFUNC(op_06a8_31), 1704 }, /* ADD */
{ CPUFUNC(op_06b0_31), 1712 }, /* ADD */
{ CPUFUNC(op_06b8_31), 1720 }, /* ADD */
{ CPUFUNC(op_06b9_31), 1721 }, /* ADD */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06c0_31), 1728 }, /* RTM */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06c8_31), 1736 }, /* RTM */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06d0_31), 1744 }, /* CALLM */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06e8_31), 1768 }, /* CALLM */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06f0_31), 1776 }, /* CALLM */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06f8_31), 1784 }, /* CALLM */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06f9_31), 1785 }, /* CALLM */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06fa_31), 1786 }, /* CALLM */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06fb_31), 1787 }, /* CALLM */
#endif
{ CPUFUNC(op_0800_31), 2048 }, /* BTST */
{ CPUFUNC(op_0810_31), 2064 }, /* BTST */
{ CPUFUNC(op_0818_31), 2072 }, /* BTST */
{ CPUFUNC(op_0820_31), 2080 }, /* BTST */
{ CPUFUNC(op_0828_31), 2088 }, /* BTST */
{ CPUFUNC(op_0830_31), 2096 }, /* BTST */
{ CPUFUNC(op_0838_31), 2104 }, /* BTST */
{ CPUFUNC(op_0839_31), 2105 }, /* BTST */
{ CPUFUNC(op_083a_31), 2106 }, /* BTST */
{ CPUFUNC(op_083b_31), 2107 }, /* BTST */
{ CPUFUNC(op_0840_31), 2112 }, /* BCHG */
{ CPUFUNC(op_0850_31), 2128 }, /* BCHG */
{ CPUFUNC(op_0858_31), 2136 }, /* BCHG */
{ CPUFUNC(op_0860_31), 2144 }, /* BCHG */
{ CPUFUNC(op_0868_31), 2152 }, /* BCHG */
{ CPUFUNC(op_0870_31), 2160 }, /* BCHG */
{ CPUFUNC(op_0878_31), 2168 }, /* BCHG */
{ CPUFUNC(op_0879_31), 2169 }, /* BCHG */
{ CPUFUNC(op_0880_31), 2176 }, /* BCLR */
{ CPUFUNC(op_0890_31), 2192 }, /* BCLR */
{ CPUFUNC(op_0898_31), 2200 }, /* BCLR */
{ CPUFUNC(op_08a0_31), 2208 }, /* BCLR */
{ CPUFUNC(op_08a8_31), 2216 }, /* BCLR */
{ CPUFUNC(op_08b0_31), 2224 }, /* BCLR */
{ CPUFUNC(op_08b8_31), 2232 }, /* BCLR */
{ CPUFUNC(op_08b9_31), 2233 }, /* BCLR */
{ CPUFUNC(op_08c0_31), 2240 }, /* BSET */
{ CPUFUNC(op_08d0_31), 2256 }, /* BSET */
{ CPUFUNC(op_08d8_31), 2264 }, /* BSET */
{ CPUFUNC(op_08e0_31), 2272 }, /* BSET */
{ CPUFUNC(op_08e8_31), 2280 }, /* BSET */
{ CPUFUNC(op_08f0_31), 2288 }, /* BSET */
{ CPUFUNC(op_08f8_31), 2296 }, /* BSET */
{ CPUFUNC(op_08f9_31), 2297 }, /* BSET */
{ CPUFUNC(op_0a00_31), 2560 }, /* EOR */
{ CPUFUNC(op_0a10_31), 2576 }, /* EOR */
{ CPUFUNC(op_0a18_31), 2584 }, /* EOR */
{ CPUFUNC(op_0a20_31), 2592 }, /* EOR */
{ CPUFUNC(op_0a28_31), 2600 }, /* EOR */
{ CPUFUNC(op_0a30_31), 2608 }, /* EOR */
{ CPUFUNC(op_0a38_31), 2616 }, /* EOR */
{ CPUFUNC(op_0a39_31), 2617 }, /* EOR */
{ CPUFUNC(op_0a3c_31), 2620 }, /* EORSR */
{ CPUFUNC(op_0a40_31), 2624 }, /* EOR */
{ CPUFUNC(op_0a50_31), 2640 }, /* EOR */
{ CPUFUNC(op_0a58_31), 2648 }, /* EOR */
{ CPUFUNC(op_0a60_31), 2656 }, /* EOR */
{ CPUFUNC(op_0a68_31), 2664 }, /* EOR */
{ CPUFUNC(op_0a70_31), 2672 }, /* EOR */
{ CPUFUNC(op_0a78_31), 2680 }, /* EOR */
{ CPUFUNC(op_0a79_31), 2681 }, /* EOR */
{ CPUFUNC(op_0a7c_31), 2684 }, /* EORSR */
{ CPUFUNC(op_0a80_31), 2688 }, /* EOR */
{ CPUFUNC(op_0a90_31), 2704 }, /* EOR */
{ CPUFUNC(op_0a98_31), 2712 }, /* EOR */
{ CPUFUNC(op_0aa0_31), 2720 }, /* EOR */
{ CPUFUNC(op_0aa8_31), 2728 }, /* EOR */
{ CPUFUNC(op_0ab0_31), 2736 }, /* EOR */
{ CPUFUNC(op_0ab8_31), 2744 }, /* EOR */
{ CPUFUNC(op_0ab9_31), 2745 }, /* EOR */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ad0_31), 2768 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ad8_31), 2776 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ae0_31), 2784 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ae8_31), 2792 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0af0_31), 2800 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0af8_31), 2808 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0af9_31), 2809 }, /* CAS */
#endif
{ CPUFUNC(op_0c00_31), 3072 }, /* CMP */
{ CPUFUNC(op_0c10_31), 3088 }, /* CMP */
{ CPUFUNC(op_0c18_31), 3096 }, /* CMP */
{ CPUFUNC(op_0c20_31), 3104 }, /* CMP */
{ CPUFUNC(op_0c28_31), 3112 }, /* CMP */
{ CPUFUNC(op_0c30_31), 3120 }, /* CMP */
{ CPUFUNC(op_0c38_31), 3128 }, /* CMP */
{ CPUFUNC(op_0c39_31), 3129 }, /* CMP */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0c3a_31), 3130 }, /* CMP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0c3b_31), 3131 }, /* CMP */
#endif
{ CPUFUNC(op_0c40_31), 3136 }, /* CMP */
{ CPUFUNC(op_0c50_31), 3152 }, /* CMP */
{ CPUFUNC(op_0c58_31), 3160 }, /* CMP */
{ CPUFUNC(op_0c60_31), 3168 }, /* CMP */
{ CPUFUNC(op_0c68_31), 3176 }, /* CMP */
{ CPUFUNC(op_0c70_31), 3184 }, /* CMP */
{ CPUFUNC(op_0c78_31), 3192 }, /* CMP */
{ CPUFUNC(op_0c79_31), 3193 }, /* CMP */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0c7a_31), 3194 }, /* CMP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0c7b_31), 3195 }, /* CMP */
#endif
{ CPUFUNC(op_0c80_31), 3200 }, /* CMP */
{ CPUFUNC(op_0c90_31), 3216 }, /* CMP */
{ CPUFUNC(op_0c98_31), 3224 }, /* CMP */
{ CPUFUNC(op_0ca0_31), 3232 }, /* CMP */
{ CPUFUNC(op_0ca8_31), 3240 }, /* CMP */
{ CPUFUNC(op_0cb0_31), 3248 }, /* CMP */
{ CPUFUNC(op_0cb8_31), 3256 }, /* CMP */
{ CPUFUNC(op_0cb9_31), 3257 }, /* CMP */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0cba_31), 3258 }, /* CMP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0cbb_31), 3259 }, /* CMP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0cd0_31), 3280 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0cd8_31), 3288 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ce0_31), 3296 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ce8_31), 3304 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0cf0_31), 3312 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0cf8_31), 3320 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0cf9_31), 3321 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0cfc_31), 3324 }, /* CAS2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e10_31), 3600 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e18_31), 3608 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e20_31), 3616 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e28_31), 3624 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e30_31), 3632 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e38_31), 3640 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e39_31), 3641 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e50_31), 3664 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e58_31), 3672 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e60_31), 3680 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e68_31), 3688 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e70_31), 3696 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e78_31), 3704 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e79_31), 3705 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e90_31), 3728 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e98_31), 3736 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ea0_31), 3744 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ea8_31), 3752 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0eb0_31), 3760 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0eb8_31), 3768 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0eb9_31), 3769 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ed0_31), 3792 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ed8_31), 3800 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ee0_31), 3808 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ee8_31), 3816 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ef0_31), 3824 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ef8_31), 3832 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ef9_31), 3833 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0efc_31), 3836 }, /* CAS2 */
#endif
{ CPUFUNC(op_1000_31), 4096 }, /* MOVE */
{ CPUFUNC(op_1010_31), 4112 }, /* MOVE */
{ CPUFUNC(op_1018_31), 4120 }, /* MOVE */
{ CPUFUNC(op_1020_31), 4128 }, /* MOVE */
{ CPUFUNC(op_1028_31), 4136 }, /* MOVE */
{ CPUFUNC(op_1030_31), 4144 }, /* MOVE */
{ CPUFUNC(op_1038_31), 4152 }, /* MOVE */
{ CPUFUNC(op_1039_31), 4153 }, /* MOVE */
{ CPUFUNC(op_103a_31), 4154 }, /* MOVE */
{ CPUFUNC(op_103b_31), 4155 }, /* MOVE */
{ CPUFUNC(op_103c_31), 4156 }, /* MOVE */
{ CPUFUNC(op_1080_31), 4224 }, /* MOVE */
{ CPUFUNC(op_1090_31), 4240 }, /* MOVE */
{ CPUFUNC(op_1098_31), 4248 }, /* MOVE */
{ CPUFUNC(op_10a0_31), 4256 }, /* MOVE */
{ CPUFUNC(op_10a8_31), 4264 }, /* MOVE */
{ CPUFUNC(op_10b0_31), 4272 }, /* MOVE */
{ CPUFUNC(op_10b8_31), 4280 }, /* MOVE */
{ CPUFUNC(op_10b9_31), 4281 }, /* MOVE */
{ CPUFUNC(op_10ba_31), 4282 }, /* MOVE */
{ CPUFUNC(op_10bb_31), 4283 }, /* MOVE */
{ CPUFUNC(op_10bc_31), 4284 }, /* MOVE */
{ CPUFUNC(op_10c0_31), 4288 }, /* MOVE */
{ CPUFUNC(op_10d0_31), 4304 }, /* MOVE */
{ CPUFUNC(op_10d8_31), 4312 }, /* MOVE */
{ CPUFUNC(op_10e0_31), 4320 }, /* MOVE */
{ CPUFUNC(op_10e8_31), 4328 }, /* MOVE */
{ CPUFUNC(op_10f0_31), 4336 }, /* MOVE */
{ CPUFUNC(op_10f8_31), 4344 }, /* MOVE */
{ CPUFUNC(op_10f9_31), 4345 }, /* MOVE */
{ CPUFUNC(op_10fa_31), 4346 }, /* MOVE */
{ CPUFUNC(op_10fb_31), 4347 }, /* MOVE */
{ CPUFUNC(op_10fc_31), 4348 }, /* MOVE */
{ CPUFUNC(op_1100_31), 4352 }, /* MOVE */
{ CPUFUNC(op_1110_31), 4368 }, /* MOVE */
{ CPUFUNC(op_1118_31), 4376 }, /* MOVE */
{ CPUFUNC(op_1120_31), 4384 }, /* MOVE */
{ CPUFUNC(op_1128_31), 4392 }, /* MOVE */
{ CPUFUNC(op_1130_31), 4400 }, /* MOVE */
{ CPUFUNC(op_1138_31), 4408 }, /* MOVE */
{ CPUFUNC(op_1139_31), 4409 }, /* MOVE */
{ CPUFUNC(op_113a_31), 4410 }, /* MOVE */
{ CPUFUNC(op_113b_31), 4411 }, /* MOVE */
{ CPUFUNC(op_113c_31), 4412 }, /* MOVE */
{ CPUFUNC(op_1140_31), 4416 }, /* MOVE */
{ CPUFUNC(op_1150_31), 4432 }, /* MOVE */
{ CPUFUNC(op_1158_31), 4440 }, /* MOVE */
{ CPUFUNC(op_1160_31), 4448 }, /* MOVE */
{ CPUFUNC(op_1168_31), 4456 }, /* MOVE */
{ CPUFUNC(op_1170_31), 4464 }, /* MOVE */
{ CPUFUNC(op_1178_31), 4472 }, /* MOVE */
{ CPUFUNC(op_1179_31), 4473 }, /* MOVE */
{ CPUFUNC(op_117a_31), 4474 }, /* MOVE */
{ CPUFUNC(op_117b_31), 4475 }, /* MOVE */
{ CPUFUNC(op_117c_31), 4476 }, /* MOVE */
{ CPUFUNC(op_1180_31), 4480 }, /* MOVE */
{ CPUFUNC(op_1190_31), 4496 }, /* MOVE */
{ CPUFUNC(op_1198_31), 4504 }, /* MOVE */
{ CPUFUNC(op_11a0_31), 4512 }, /* MOVE */
{ CPUFUNC(op_11a8_31), 4520 }, /* MOVE */
{ CPUFUNC(op_11b0_31), 4528 }, /* MOVE */
{ CPUFUNC(op_11b8_31), 4536 }, /* MOVE */
{ CPUFUNC(op_11b9_31), 4537 }, /* MOVE */
{ CPUFUNC(op_11ba_31), 4538 }, /* MOVE */
{ CPUFUNC(op_11bb_31), 4539 }, /* MOVE */
{ CPUFUNC(op_11bc_31), 4540 }, /* MOVE */
{ CPUFUNC(op_11c0_31), 4544 }, /* MOVE */
{ CPUFUNC(op_11d0_31), 4560 }, /* MOVE */
{ CPUFUNC(op_11d8_31), 4568 }, /* MOVE */
{ CPUFUNC(op_11e0_31), 4576 }, /* MOVE */
{ CPUFUNC(op_11e8_31), 4584 }, /* MOVE */
{ CPUFUNC(op_11f0_31), 4592 }, /* MOVE */
{ CPUFUNC(op_11f8_31), 4600 }, /* MOVE */
{ CPUFUNC(op_11f9_31), 4601 }, /* MOVE */
{ CPUFUNC(op_11fa_31), 4602 }, /* MOVE */
{ CPUFUNC(op_11fb_31), 4603 }, /* MOVE */
{ CPUFUNC(op_11fc_31), 4604 }, /* MOVE */
{ CPUFUNC(op_13c0_31), 5056 }, /* MOVE */
{ CPUFUNC(op_13d0_31), 5072 }, /* MOVE */
{ CPUFUNC(op_13d8_31), 5080 }, /* MOVE */
{ CPUFUNC(op_13e0_31), 5088 }, /* MOVE */
{ CPUFUNC(op_13e8_31), 5096 }, /* MOVE */
{ CPUFUNC(op_13f0_31), 5104 }, /* MOVE */
{ CPUFUNC(op_13f8_31), 5112 }, /* MOVE */
{ CPUFUNC(op_13f9_31), 5113 }, /* MOVE */
{ CPUFUNC(op_13fa_31), 5114 }, /* MOVE */
{ CPUFUNC(op_13fb_31), 5115 }, /* MOVE */
{ CPUFUNC(op_13fc_31), 5116 }, /* MOVE */
{ CPUFUNC(op_2000_31), 8192 }, /* MOVE */
{ CPUFUNC(op_2008_31), 8200 }, /* MOVE */
{ CPUFUNC(op_2010_31), 8208 }, /* MOVE */
{ CPUFUNC(op_2018_31), 8216 }, /* MOVE */
{ CPUFUNC(op_2020_31), 8224 }, /* MOVE */
{ CPUFUNC(op_2028_31), 8232 }, /* MOVE */
{ CPUFUNC(op_2030_31), 8240 }, /* MOVE */
{ CPUFUNC(op_2038_31), 8248 }, /* MOVE */
{ CPUFUNC(op_2039_31), 8249 }, /* MOVE */
{ CPUFUNC(op_203a_31), 8250 }, /* MOVE */
{ CPUFUNC(op_203b_31), 8251 }, /* MOVE */
{ CPUFUNC(op_203c_31), 8252 }, /* MOVE */
{ CPUFUNC(op_2040_31), 8256 }, /* MOVEA */
{ CPUFUNC(op_2048_31), 8264 }, /* MOVEA */
{ CPUFUNC(op_2050_31), 8272 }, /* MOVEA */
{ CPUFUNC(op_2058_31), 8280 }, /* MOVEA */
{ CPUFUNC(op_2060_31), 8288 }, /* MOVEA */
{ CPUFUNC(op_2068_31), 8296 }, /* MOVEA */
{ CPUFUNC(op_2070_31), 8304 }, /* MOVEA */
{ CPUFUNC(op_2078_31), 8312 }, /* MOVEA */
{ CPUFUNC(op_2079_31), 8313 }, /* MOVEA */
{ CPUFUNC(op_207a_31), 8314 }, /* MOVEA */
{ CPUFUNC(op_207b_31), 8315 }, /* MOVEA */
{ CPUFUNC(op_207c_31), 8316 }, /* MOVEA */
{ CPUFUNC(op_2080_31), 8320 }, /* MOVE */
{ CPUFUNC(op_2088_31), 8328 }, /* MOVE */
{ CPUFUNC(op_2090_31), 8336 }, /* MOVE */
{ CPUFUNC(op_2098_31), 8344 }, /* MOVE */
{ CPUFUNC(op_20a0_31), 8352 }, /* MOVE */
{ CPUFUNC(op_20a8_31), 8360 }, /* MOVE */
{ CPUFUNC(op_20b0_31), 8368 }, /* MOVE */
{ CPUFUNC(op_20b8_31), 8376 }, /* MOVE */
{ CPUFUNC(op_20b9_31), 8377 }, /* MOVE */
{ CPUFUNC(op_20ba_31), 8378 }, /* MOVE */
{ CPUFUNC(op_20bb_31), 8379 }, /* MOVE */
{ CPUFUNC(op_20bc_31), 8380 }, /* MOVE */
{ CPUFUNC(op_20c0_31), 8384 }, /* MOVE */
{ CPUFUNC(op_20c8_31), 8392 }, /* MOVE */
{ CPUFUNC(op_20d0_31), 8400 }, /* MOVE */
{ CPUFUNC(op_20d8_31), 8408 }, /* MOVE */
{ CPUFUNC(op_20e0_31), 8416 }, /* MOVE */
{ CPUFUNC(op_20e8_31), 8424 }, /* MOVE */
{ CPUFUNC(op_20f0_31), 8432 }, /* MOVE */
{ CPUFUNC(op_20f8_31), 8440 }, /* MOVE */
{ CPUFUNC(op_20f9_31), 8441 }, /* MOVE */
{ CPUFUNC(op_20fa_31), 8442 }, /* MOVE */
{ CPUFUNC(op_20fb_31), 8443 }, /* MOVE */
{ CPUFUNC(op_20fc_31), 8444 }, /* MOVE */
{ CPUFUNC(op_2100_31), 8448 }, /* MOVE */
{ CPUFUNC(op_2108_31), 8456 }, /* MOVE */
{ CPUFUNC(op_2110_31), 8464 }, /* MOVE */
{ CPUFUNC(op_2118_31), 8472 }, /* MOVE */
{ CPUFUNC(op_2120_31), 8480 }, /* MOVE */
{ CPUFUNC(op_2128_31), 8488 }, /* MOVE */
{ CPUFUNC(op_2130_31), 8496 }, /* MOVE */
{ CPUFUNC(op_2138_31), 8504 }, /* MOVE */
{ CPUFUNC(op_2139_31), 8505 }, /* MOVE */
{ CPUFUNC(op_213a_31), 8506 }, /* MOVE */
{ CPUFUNC(op_213b_31), 8507 }, /* MOVE */
{ CPUFUNC(op_213c_31), 8508 }, /* MOVE */
{ CPUFUNC(op_2140_31), 8512 }, /* MOVE */
{ CPUFUNC(op_2148_31), 8520 }, /* MOVE */
{ CPUFUNC(op_2150_31), 8528 }, /* MOVE */
{ CPUFUNC(op_2158_31), 8536 }, /* MOVE */
{ CPUFUNC(op_2160_31), 8544 }, /* MOVE */
{ CPUFUNC(op_2168_31), 8552 }, /* MOVE */
{ CPUFUNC(op_2170_31), 8560 }, /* MOVE */
{ CPUFUNC(op_2178_31), 8568 }, /* MOVE */
{ CPUFUNC(op_2179_31), 8569 }, /* MOVE */
{ CPUFUNC(op_217a_31), 8570 }, /* MOVE */
{ CPUFUNC(op_217b_31), 8571 }, /* MOVE */
{ CPUFUNC(op_217c_31), 8572 }, /* MOVE */
{ CPUFUNC(op_2180_31), 8576 }, /* MOVE */
{ CPUFUNC(op_2188_31), 8584 }, /* MOVE */
{ CPUFUNC(op_2190_31), 8592 }, /* MOVE */
{ CPUFUNC(op_2198_31), 8600 }, /* MOVE */
{ CPUFUNC(op_21a0_31), 8608 }, /* MOVE */
{ CPUFUNC(op_21a8_31), 8616 }, /* MOVE */
{ CPUFUNC(op_21b0_31), 8624 }, /* MOVE */
{ CPUFUNC(op_21b8_31), 8632 }, /* MOVE */
{ CPUFUNC(op_21b9_31), 8633 }, /* MOVE */
{ CPUFUNC(op_21ba_31), 8634 }, /* MOVE */
{ CPUFUNC(op_21bb_31), 8635 }, /* MOVE */
{ CPUFUNC(op_21bc_31), 8636 }, /* MOVE */
{ CPUFUNC(op_21c0_31), 8640 }, /* MOVE */
{ CPUFUNC(op_21c8_31), 8648 }, /* MOVE */
{ CPUFUNC(op_21d0_31), 8656 }, /* MOVE */
{ CPUFUNC(op_21d8_31), 8664 }, /* MOVE */
{ CPUFUNC(op_21e0_31), 8672 }, /* MOVE */
{ CPUFUNC(op_21e8_31), 8680 }, /* MOVE */
{ CPUFUNC(op_21f0_31), 8688 }, /* MOVE */
{ CPUFUNC(op_21f8_31), 8696 }, /* MOVE */
{ CPUFUNC(op_21f9_31), 8697 }, /* MOVE */
{ CPUFUNC(op_21fa_31), 8698 }, /* MOVE */
{ CPUFUNC(op_21fb_31), 8699 }, /* MOVE */
{ CPUFUNC(op_21fc_31), 8700 }, /* MOVE */
{ CPUFUNC(op_23c0_31), 9152 }, /* MOVE */
{ CPUFUNC(op_23c8_31), 9160 }, /* MOVE */
{ CPUFUNC(op_23d0_31), 9168 }, /* MOVE */
{ CPUFUNC(op_23d8_31), 9176 }, /* MOVE */
{ CPUFUNC(op_23e0_31), 9184 }, /* MOVE */
{ CPUFUNC(op_23e8_31), 9192 }, /* MOVE */
{ CPUFUNC(op_23f0_31), 9200 }, /* MOVE */
{ CPUFUNC(op_23f8_31), 9208 }, /* MOVE */
{ CPUFUNC(op_23f9_31), 9209 }, /* MOVE */
{ CPUFUNC(op_23fa_31), 9210 }, /* MOVE */
{ CPUFUNC(op_23fb_31), 9211 }, /* MOVE */
{ CPUFUNC(op_23fc_31), 9212 }, /* MOVE */
{ CPUFUNC(op_3000_31), 12288 }, /* MOVE */
{ CPUFUNC(op_3008_31), 12296 }, /* MOVE */
{ CPUFUNC(op_3010_31), 12304 }, /* MOVE */
{ CPUFUNC(op_3018_31), 12312 }, /* MOVE */
{ CPUFUNC(op_3020_31), 12320 }, /* MOVE */
{ CPUFUNC(op_3028_31), 12328 }, /* MOVE */
{ CPUFUNC(op_3030_31), 12336 }, /* MOVE */
{ CPUFUNC(op_3038_31), 12344 }, /* MOVE */
{ CPUFUNC(op_3039_31), 12345 }, /* MOVE */
{ CPUFUNC(op_303a_31), 12346 }, /* MOVE */
{ CPUFUNC(op_303b_31), 12347 }, /* MOVE */
{ CPUFUNC(op_303c_31), 12348 }, /* MOVE */
{ CPUFUNC(op_3040_31), 12352 }, /* MOVEA */
{ CPUFUNC(op_3048_31), 12360 }, /* MOVEA */
{ CPUFUNC(op_3050_31), 12368 }, /* MOVEA */
{ CPUFUNC(op_3058_31), 12376 }, /* MOVEA */
{ CPUFUNC(op_3060_31), 12384 }, /* MOVEA */
{ CPUFUNC(op_3068_31), 12392 }, /* MOVEA */
{ CPUFUNC(op_3070_31), 12400 }, /* MOVEA */
{ CPUFUNC(op_3078_31), 12408 }, /* MOVEA */
{ CPUFUNC(op_3079_31), 12409 }, /* MOVEA */
{ CPUFUNC(op_307a_31), 12410 }, /* MOVEA */
{ CPUFUNC(op_307b_31), 12411 }, /* MOVEA */
{ CPUFUNC(op_307c_31), 12412 }, /* MOVEA */
{ CPUFUNC(op_3080_31), 12416 }, /* MOVE */
{ CPUFUNC(op_3088_31), 12424 }, /* MOVE */
{ CPUFUNC(op_3090_31), 12432 }, /* MOVE */
{ CPUFUNC(op_3098_31), 12440 }, /* MOVE */
{ CPUFUNC(op_30a0_31), 12448 }, /* MOVE */
{ CPUFUNC(op_30a8_31), 12456 }, /* MOVE */
{ CPUFUNC(op_30b0_31), 12464 }, /* MOVE */
{ CPUFUNC(op_30b8_31), 12472 }, /* MOVE */
{ CPUFUNC(op_30b9_31), 12473 }, /* MOVE */
{ CPUFUNC(op_30ba_31), 12474 }, /* MOVE */
{ CPUFUNC(op_30bb_31), 12475 }, /* MOVE */
{ CPUFUNC(op_30bc_31), 12476 }, /* MOVE */
{ CPUFUNC(op_30c0_31), 12480 }, /* MOVE */
{ CPUFUNC(op_30c8_31), 12488 }, /* MOVE */
{ CPUFUNC(op_30d0_31), 12496 }, /* MOVE */
{ CPUFUNC(op_30d8_31), 12504 }, /* MOVE */
{ CPUFUNC(op_30e0_31), 12512 }, /* MOVE */
{ CPUFUNC(op_30e8_31), 12520 }, /* MOVE */
{ CPUFUNC(op_30f0_31), 12528 }, /* MOVE */
{ CPUFUNC(op_30f8_31), 12536 }, /* MOVE */
{ CPUFUNC(op_30f9_31), 12537 }, /* MOVE */
{ CPUFUNC(op_30fa_31), 12538 }, /* MOVE */
{ CPUFUNC(op_30fb_31), 12539 }, /* MOVE */
{ CPUFUNC(op_30fc_31), 12540 }, /* MOVE */
{ CPUFUNC(op_3100_31), 12544 }, /* MOVE */
{ CPUFUNC(op_3108_31), 12552 }, /* MOVE */
{ CPUFUNC(op_3110_31), 12560 }, /* MOVE */
{ CPUFUNC(op_3118_31), 12568 }, /* MOVE */
{ CPUFUNC(op_3120_31), 12576 }, /* MOVE */
{ CPUFUNC(op_3128_31), 12584 }, /* MOVE */
{ CPUFUNC(op_3130_31), 12592 }, /* MOVE */
{ CPUFUNC(op_3138_31), 12600 }, /* MOVE */
{ CPUFUNC(op_3139_31), 12601 }, /* MOVE */
{ CPUFUNC(op_313a_31), 12602 }, /* MOVE */
{ CPUFUNC(op_313b_31), 12603 }, /* MOVE */
{ CPUFUNC(op_313c_31), 12604 }, /* MOVE */
{ CPUFUNC(op_3140_31), 12608 }, /* MOVE */
{ CPUFUNC(op_3148_31), 12616 }, /* MOVE */
{ CPUFUNC(op_3150_31), 12624 }, /* MOVE */
{ CPUFUNC(op_3158_31), 12632 }, /* MOVE */
{ CPUFUNC(op_3160_31), 12640 }, /* MOVE */
{ CPUFUNC(op_3168_31), 12648 }, /* MOVE */
{ CPUFUNC(op_3170_31), 12656 }, /* MOVE */
{ CPUFUNC(op_3178_31), 12664 }, /* MOVE */
{ CPUFUNC(op_3179_31), 12665 }, /* MOVE */
{ CPUFUNC(op_317a_31), 12666 }, /* MOVE */
{ CPUFUNC(op_317b_31), 12667 }, /* MOVE */
{ CPUFUNC(op_317c_31), 12668 }, /* MOVE */
{ CPUFUNC(op_3180_31), 12672 }, /* MOVE */
{ CPUFUNC(op_3188_31), 12680 }, /* MOVE */
{ CPUFUNC(op_3190_31), 12688 }, /* MOVE */
{ CPUFUNC(op_3198_31), 12696 }, /* MOVE */
{ CPUFUNC(op_31a0_31), 12704 }, /* MOVE */
{ CPUFUNC(op_31a8_31), 12712 }, /* MOVE */
{ CPUFUNC(op_31b0_31), 12720 }, /* MOVE */
{ CPUFUNC(op_31b8_31), 12728 }, /* MOVE */
{ CPUFUNC(op_31b9_31), 12729 }, /* MOVE */
{ CPUFUNC(op_31ba_31), 12730 }, /* MOVE */
{ CPUFUNC(op_31bb_31), 12731 }, /* MOVE */
{ CPUFUNC(op_31bc_31), 12732 }, /* MOVE */
{ CPUFUNC(op_31c0_31), 12736 }, /* MOVE */
{ CPUFUNC(op_31c8_31), 12744 }, /* MOVE */
{ CPUFUNC(op_31d0_31), 12752 }, /* MOVE */
{ CPUFUNC(op_31d8_31), 12760 }, /* MOVE */
{ CPUFUNC(op_31e0_31), 12768 }, /* MOVE */
{ CPUFUNC(op_31e8_31), 12776 }, /* MOVE */
{ CPUFUNC(op_31f0_31), 12784 }, /* MOVE */
{ CPUFUNC(op_31f8_31), 12792 }, /* MOVE */
{ CPUFUNC(op_31f9_31), 12793 }, /* MOVE */
{ CPUFUNC(op_31fa_31), 12794 }, /* MOVE */
{ CPUFUNC(op_31fb_31), 12795 }, /* MOVE */
{ CPUFUNC(op_31fc_31), 12796 }, /* MOVE */
{ CPUFUNC(op_33c0_31), 13248 }, /* MOVE */
{ CPUFUNC(op_33c8_31), 13256 }, /* MOVE */
{ CPUFUNC(op_33d0_31), 13264 }, /* MOVE */
{ CPUFUNC(op_33d8_31), 13272 }, /* MOVE */
{ CPUFUNC(op_33e0_31), 13280 }, /* MOVE */
{ CPUFUNC(op_33e8_31), 13288 }, /* MOVE */
{ CPUFUNC(op_33f0_31), 13296 }, /* MOVE */
{ CPUFUNC(op_33f8_31), 13304 }, /* MOVE */
{ CPUFUNC(op_33f9_31), 13305 }, /* MOVE */
{ CPUFUNC(op_33fa_31), 13306 }, /* MOVE */
{ CPUFUNC(op_33fb_31), 13307 }, /* MOVE */
{ CPUFUNC(op_33fc_31), 13308 }, /* MOVE */
{ CPUFUNC(op_4000_31), 16384 }, /* NEGX */
{ CPUFUNC(op_4010_31), 16400 }, /* NEGX */
{ CPUFUNC(op_4018_31), 16408 }, /* NEGX */
{ CPUFUNC(op_4020_31), 16416 }, /* NEGX */
{ CPUFUNC(op_4028_31), 16424 }, /* NEGX */
{ CPUFUNC(op_4030_31), 16432 }, /* NEGX */
{ CPUFUNC(op_4038_31), 16440 }, /* NEGX */
{ CPUFUNC(op_4039_31), 16441 }, /* NEGX */
{ CPUFUNC(op_4040_31), 16448 }, /* NEGX */
{ CPUFUNC(op_4050_31), 16464 }, /* NEGX */
{ CPUFUNC(op_4058_31), 16472 }, /* NEGX */
{ CPUFUNC(op_4060_31), 16480 }, /* NEGX */
{ CPUFUNC(op_4068_31), 16488 }, /* NEGX */
{ CPUFUNC(op_4070_31), 16496 }, /* NEGX */
{ CPUFUNC(op_4078_31), 16504 }, /* NEGX */
{ CPUFUNC(op_4079_31), 16505 }, /* NEGX */
{ CPUFUNC(op_4080_31), 16512 }, /* NEGX */
{ CPUFUNC(op_4090_31), 16528 }, /* NEGX */
{ CPUFUNC(op_4098_31), 16536 }, /* NEGX */
{ CPUFUNC(op_40a0_31), 16544 }, /* NEGX */
{ CPUFUNC(op_40a8_31), 16552 }, /* NEGX */
{ CPUFUNC(op_40b0_31), 16560 }, /* NEGX */
{ CPUFUNC(op_40b8_31), 16568 }, /* NEGX */
{ CPUFUNC(op_40b9_31), 16569 }, /* NEGX */
{ CPUFUNC(op_40c0_31), 16576 }, /* MVSR2 */
{ CPUFUNC(op_40d0_31), 16592 }, /* MVSR2 */
{ CPUFUNC(op_40d8_31), 16600 }, /* MVSR2 */
{ CPUFUNC(op_40e0_31), 16608 }, /* MVSR2 */
{ CPUFUNC(op_40e8_31), 16616 }, /* MVSR2 */
{ CPUFUNC(op_40f0_31), 16624 }, /* MVSR2 */
{ CPUFUNC(op_40f8_31), 16632 }, /* MVSR2 */
{ CPUFUNC(op_40f9_31), 16633 }, /* MVSR2 */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4100_31), 16640 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4110_31), 16656 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4118_31), 16664 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4120_31), 16672 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4128_31), 16680 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4130_31), 16688 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4138_31), 16696 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4139_31), 16697 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_413a_31), 16698 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_413b_31), 16699 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_413c_31), 16700 }, /* CHK */
#endif
{ CPUFUNC(op_4180_31), 16768 }, /* CHK */
{ CPUFUNC(op_4190_31), 16784 }, /* CHK */
{ CPUFUNC(op_4198_31), 16792 }, /* CHK */
{ CPUFUNC(op_41a0_31), 16800 }, /* CHK */
{ CPUFUNC(op_41a8_31), 16808 }, /* CHK */
{ CPUFUNC(op_41b0_31), 16816 }, /* CHK */
{ CPUFUNC(op_41b8_31), 16824 }, /* CHK */
{ CPUFUNC(op_41b9_31), 16825 }, /* CHK */
{ CPUFUNC(op_41ba_31), 16826 }, /* CHK */
{ CPUFUNC(op_41bb_31), 16827 }, /* CHK */
{ CPUFUNC(op_41bc_31), 16828 }, /* CHK */
{ CPUFUNC(op_41d0_31), 16848 }, /* LEA */
{ CPUFUNC(op_41e8_31), 16872 }, /* LEA */
{ CPUFUNC(op_41f0_31), 16880 }, /* LEA */
{ CPUFUNC(op_41f8_31), 16888 }, /* LEA */
{ CPUFUNC(op_41f9_31), 16889 }, /* LEA */
{ CPUFUNC(op_41fa_31), 16890 }, /* LEA */
{ CPUFUNC(op_41fb_31), 16891 }, /* LEA */
{ CPUFUNC(op_4200_31), 16896 }, /* CLR */
{ CPUFUNC(op_4210_31), 16912 }, /* CLR */
{ CPUFUNC(op_4218_31), 16920 }, /* CLR */
{ CPUFUNC(op_4220_31), 16928 }, /* CLR */
{ CPUFUNC(op_4228_31), 16936 }, /* CLR */
{ CPUFUNC(op_4230_31), 16944 }, /* CLR */
{ CPUFUNC(op_4238_31), 16952 }, /* CLR */
{ CPUFUNC(op_4239_31), 16953 }, /* CLR */
{ CPUFUNC(op_4240_31), 16960 }, /* CLR */
{ CPUFUNC(op_4250_31), 16976 }, /* CLR */
{ CPUFUNC(op_4258_31), 16984 }, /* CLR */
{ CPUFUNC(op_4260_31), 16992 }, /* CLR */
{ CPUFUNC(op_4268_31), 17000 }, /* CLR */
{ CPUFUNC(op_4270_31), 17008 }, /* CLR */
{ CPUFUNC(op_4278_31), 17016 }, /* CLR */
{ CPUFUNC(op_4279_31), 17017 }, /* CLR */
{ CPUFUNC(op_4280_31), 17024 }, /* CLR */
{ CPUFUNC(op_4290_31), 17040 }, /* CLR */
{ CPUFUNC(op_4298_31), 17048 }, /* CLR */
{ CPUFUNC(op_42a0_31), 17056 }, /* CLR */
{ CPUFUNC(op_42a8_31), 17064 }, /* CLR */
{ CPUFUNC(op_42b0_31), 17072 }, /* CLR */
{ CPUFUNC(op_42b8_31), 17080 }, /* CLR */
{ CPUFUNC(op_42b9_31), 17081 }, /* CLR */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_42c0_31), 17088 }, /* MVSR2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_42d0_31), 17104 }, /* MVSR2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_42d8_31), 17112 }, /* MVSR2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_42e0_31), 17120 }, /* MVSR2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_42e8_31), 17128 }, /* MVSR2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_42f0_31), 17136 }, /* MVSR2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_42f8_31), 17144 }, /* MVSR2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_42f9_31), 17145 }, /* MVSR2 */
#endif
{ CPUFUNC(op_4400_31), 17408 }, /* NEG */
{ CPUFUNC(op_4410_31), 17424 }, /* NEG */
{ CPUFUNC(op_4418_31), 17432 }, /* NEG */
{ CPUFUNC(op_4420_31), 17440 }, /* NEG */
{ CPUFUNC(op_4428_31), 17448 }, /* NEG */
{ CPUFUNC(op_4430_31), 17456 }, /* NEG */
{ CPUFUNC(op_4438_31), 17464 }, /* NEG */
{ CPUFUNC(op_4439_31), 17465 }, /* NEG */
{ CPUFUNC(op_4440_31), 17472 }, /* NEG */
{ CPUFUNC(op_4450_31), 17488 }, /* NEG */
{ CPUFUNC(op_4458_31), 17496 }, /* NEG */
{ CPUFUNC(op_4460_31), 17504 }, /* NEG */
{ CPUFUNC(op_4468_31), 17512 }, /* NEG */
{ CPUFUNC(op_4470_31), 17520 }, /* NEG */
{ CPUFUNC(op_4478_31), 17528 }, /* NEG */
{ CPUFUNC(op_4479_31), 17529 }, /* NEG */
{ CPUFUNC(op_4480_31), 17536 }, /* NEG */
{ CPUFUNC(op_4490_31), 17552 }, /* NEG */
{ CPUFUNC(op_4498_31), 17560 }, /* NEG */
{ CPUFUNC(op_44a0_31), 17568 }, /* NEG */
{ CPUFUNC(op_44a8_31), 17576 }, /* NEG */
{ CPUFUNC(op_44b0_31), 17584 }, /* NEG */
{ CPUFUNC(op_44b8_31), 17592 }, /* NEG */
{ CPUFUNC(op_44b9_31), 17593 }, /* NEG */
{ CPUFUNC(op_44c0_31), 17600 }, /* MV2SR */
{ CPUFUNC(op_44d0_31), 17616 }, /* MV2SR */
{ CPUFUNC(op_44d8_31), 17624 }, /* MV2SR */
{ CPUFUNC(op_44e0_31), 17632 }, /* MV2SR */
{ CPUFUNC(op_44e8_31), 17640 }, /* MV2SR */
{ CPUFUNC(op_44f0_31), 17648 }, /* MV2SR */
{ CPUFUNC(op_44f8_31), 17656 }, /* MV2SR */
{ CPUFUNC(op_44f9_31), 17657 }, /* MV2SR */
{ CPUFUNC(op_44fa_31), 17658 }, /* MV2SR */
{ CPUFUNC(op_44fb_31), 17659 }, /* MV2SR */
{ CPUFUNC(op_44fc_31), 17660 }, /* MV2SR */
{ CPUFUNC(op_4600_31), 17920 }, /* NOT */
{ CPUFUNC(op_4610_31), 17936 }, /* NOT */
{ CPUFUNC(op_4618_31), 17944 }, /* NOT */
{ CPUFUNC(op_4620_31), 17952 }, /* NOT */
{ CPUFUNC(op_4628_31), 17960 }, /* NOT */
{ CPUFUNC(op_4630_31), 17968 }, /* NOT */
{ CPUFUNC(op_4638_31), 17976 }, /* NOT */
{ CPUFUNC(op_4639_31), 17977 }, /* NOT */
{ CPUFUNC(op_4640_31), 17984 }, /* NOT */
{ CPUFUNC(op_4650_31), 18000 }, /* NOT */
{ CPUFUNC(op_4658_31), 18008 }, /* NOT */
{ CPUFUNC(op_4660_31), 18016 }, /* NOT */
{ CPUFUNC(op_4668_31), 18024 }, /* NOT */
{ CPUFUNC(op_4670_31), 18032 }, /* NOT */
{ CPUFUNC(op_4678_31), 18040 }, /* NOT */
{ CPUFUNC(op_4679_31), 18041 }, /* NOT */
{ CPUFUNC(op_4680_31), 18048 }, /* NOT */
{ CPUFUNC(op_4690_31), 18064 }, /* NOT */
{ CPUFUNC(op_4698_31), 18072 }, /* NOT */
{ CPUFUNC(op_46a0_31), 18080 }, /* NOT */
{ CPUFUNC(op_46a8_31), 18088 }, /* NOT */
{ CPUFUNC(op_46b0_31), 18096 }, /* NOT */
{ CPUFUNC(op_46b8_31), 18104 }, /* NOT */
{ CPUFUNC(op_46b9_31), 18105 }, /* NOT */
{ CPUFUNC(op_46c0_31), 18112 }, /* MV2SR */
{ CPUFUNC(op_46d0_31), 18128 }, /* MV2SR */
{ CPUFUNC(op_46d8_31), 18136 }, /* MV2SR */
{ CPUFUNC(op_46e0_31), 18144 }, /* MV2SR */
{ CPUFUNC(op_46e8_31), 18152 }, /* MV2SR */
{ CPUFUNC(op_46f0_31), 18160 }, /* MV2SR */
{ CPUFUNC(op_46f8_31), 18168 }, /* MV2SR */
{ CPUFUNC(op_46f9_31), 18169 }, /* MV2SR */
{ CPUFUNC(op_46fa_31), 18170 }, /* MV2SR */
{ CPUFUNC(op_46fb_31), 18171 }, /* MV2SR */
{ CPUFUNC(op_46fc_31), 18172 }, /* MV2SR */
{ CPUFUNC(op_4800_31), 18432 }, /* NBCD */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4808_31), 18440 }, /* LINK */
#endif
{ CPUFUNC(op_4810_31), 18448 }, /* NBCD */
{ CPUFUNC(op_4818_31), 18456 }, /* NBCD */
{ CPUFUNC(op_4820_31), 18464 }, /* NBCD */
{ CPUFUNC(op_4828_31), 18472 }, /* NBCD */
{ CPUFUNC(op_4830_31), 18480 }, /* NBCD */
{ CPUFUNC(op_4838_31), 18488 }, /* NBCD */
{ CPUFUNC(op_4839_31), 18489 }, /* NBCD */
{ CPUFUNC(op_4840_31), 18496 }, /* SWAP */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4848_31), 18504 }, /* BKPT */
#endif
{ CPUFUNC(op_4850_31), 18512 }, /* PEA */
{ CPUFUNC(op_4868_31), 18536 }, /* PEA */
{ CPUFUNC(op_4870_31), 18544 }, /* PEA */
{ CPUFUNC(op_4878_31), 18552 }, /* PEA */
{ CPUFUNC(op_4879_31), 18553 }, /* PEA */
{ CPUFUNC(op_487a_31), 18554 }, /* PEA */
{ CPUFUNC(op_487b_31), 18555 }, /* PEA */
{ CPUFUNC(op_4880_31), 18560 }, /* EXT */
{ CPUFUNC(op_4890_31), 18576 }, /* MVMLE */
{ CPUFUNC(op_48a0_31), 18592 }, /* MVMLE */
{ CPUFUNC(op_48a8_31), 18600 }, /* MVMLE */
{ CPUFUNC(op_48b0_31), 18608 }, /* MVMLE */
{ CPUFUNC(op_48b8_31), 18616 }, /* MVMLE */
{ CPUFUNC(op_48b9_31), 18617 }, /* MVMLE */
{ CPUFUNC(op_48c0_31), 18624 }, /* EXT */
{ CPUFUNC(op_48d0_31), 18640 }, /* MVMLE */
{ CPUFUNC(op_48e0_31), 18656 }, /* MVMLE */
{ CPUFUNC(op_48e8_31), 18664 }, /* MVMLE */
{ CPUFUNC(op_48f0_31), 18672 }, /* MVMLE */
{ CPUFUNC(op_48f8_31), 18680 }, /* MVMLE */
{ CPUFUNC(op_48f9_31), 18681 }, /* MVMLE */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_49c0_31), 18880 }, /* EXT */
#endif
{ CPUFUNC(op_4a00_31), 18944 }, /* TST */
{ CPUFUNC(op_4a10_31), 18960 }, /* TST */
{ CPUFUNC(op_4a18_31), 18968 }, /* TST */
{ CPUFUNC(op_4a20_31), 18976 }, /* TST */
{ CPUFUNC(op_4a28_31), 18984 }, /* TST */
{ CPUFUNC(op_4a30_31), 18992 }, /* TST */
{ CPUFUNC(op_4a38_31), 19000 }, /* TST */
{ CPUFUNC(op_4a39_31), 19001 }, /* TST */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4a3a_31), 19002 }, /* TST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4a3b_31), 19003 }, /* TST */
#endif
{ CPUFUNC(op_4a40_31), 19008 }, /* TST */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4a48_31), 19016 }, /* TST */
#endif
{ CPUFUNC(op_4a50_31), 19024 }, /* TST */
{ CPUFUNC(op_4a58_31), 19032 }, /* TST */
{ CPUFUNC(op_4a60_31), 19040 }, /* TST */
{ CPUFUNC(op_4a68_31), 19048 }, /* TST */
{ CPUFUNC(op_4a70_31), 19056 }, /* TST */
{ CPUFUNC(op_4a78_31), 19064 }, /* TST */
{ CPUFUNC(op_4a79_31), 19065 }, /* TST */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4a7a_31), 19066 }, /* TST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4a7b_31), 19067 }, /* TST */
#endif
{ CPUFUNC(op_4a80_31), 19072 }, /* TST */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4a88_31), 19080 }, /* TST */
#endif
{ CPUFUNC(op_4a90_31), 19088 }, /* TST */
{ CPUFUNC(op_4a98_31), 19096 }, /* TST */
{ CPUFUNC(op_4aa0_31), 19104 }, /* TST */
{ CPUFUNC(op_4aa8_31), 19112 }, /* TST */
{ CPUFUNC(op_4ab0_31), 19120 }, /* TST */
{ CPUFUNC(op_4ab8_31), 19128 }, /* TST */
{ CPUFUNC(op_4ab9_31), 19129 }, /* TST */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4aba_31), 19130 }, /* TST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4abb_31), 19131 }, /* TST */
#endif
{ CPUFUNC(op_4ac0_31), 19136 }, /* TAS */
{ CPUFUNC(op_4ad0_31), 19152 }, /* TAS */
{ CPUFUNC(op_4ad8_31), 19160 }, /* TAS */
{ CPUFUNC(op_4ae0_31), 19168 }, /* TAS */
{ CPUFUNC(op_4ae8_31), 19176 }, /* TAS */
{ CPUFUNC(op_4af0_31), 19184 }, /* TAS */
{ CPUFUNC(op_4af8_31), 19192 }, /* TAS */
{ CPUFUNC(op_4af9_31), 19193 }, /* TAS */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c00_31), 19456 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c10_31), 19472 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c18_31), 19480 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c20_31), 19488 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c28_31), 19496 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c30_31), 19504 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c38_31), 19512 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c39_31), 19513 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c3a_31), 19514 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c3b_31), 19515 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c3c_31), 19516 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c40_31), 19520 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c50_31), 19536 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c58_31), 19544 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c60_31), 19552 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c68_31), 19560 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c70_31), 19568 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c78_31), 19576 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c79_31), 19577 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c7a_31), 19578 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c7b_31), 19579 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c7c_31), 19580 }, /* DIVL */
#endif
{ CPUFUNC(op_4c90_31), 19600 }, /* MVMEL */
{ CPUFUNC(op_4c98_31), 19608 }, /* MVMEL */
{ CPUFUNC(op_4ca8_31), 19624 }, /* MVMEL */
{ CPUFUNC(op_4cb0_31), 19632 }, /* MVMEL */
{ CPUFUNC(op_4cb8_31), 19640 }, /* MVMEL */
{ CPUFUNC(op_4cb9_31), 19641 }, /* MVMEL */
{ CPUFUNC(op_4cba_31), 19642 }, /* MVMEL */
{ CPUFUNC(op_4cbb_31), 19643 }, /* MVMEL */
{ CPUFUNC(op_4cd0_31), 19664 }, /* MVMEL */
{ CPUFUNC(op_4cd8_31), 19672 }, /* MVMEL */
{ CPUFUNC(op_4ce8_31), 19688 }, /* MVMEL */
{ CPUFUNC(op_4cf0_31), 19696 }, /* MVMEL */
{ CPUFUNC(op_4cf8_31), 19704 }, /* MVMEL */
{ CPUFUNC(op_4cf9_31), 19705 }, /* MVMEL */
{ CPUFUNC(op_4cfa_31), 19706 }, /* MVMEL */
{ CPUFUNC(op_4cfb_31), 19707 }, /* MVMEL */
{ CPUFUNC(op_4e40_31), 20032 }, /* TRAP */
{ CPUFUNC(op_4e50_31), 20048 }, /* LINK */
{ CPUFUNC(op_4e58_31), 20056 }, /* UNLK */
{ CPUFUNC(op_4e60_31), 20064 }, /* MVR2USP */
{ CPUFUNC(op_4e68_31), 20072 }, /* MVUSP2R */
{ CPUFUNC(op_4e70_31), 20080 }, /* RESET */
{ CPUFUNC(op_4e71_31), 20081 }, /* NOP */
{ CPUFUNC(op_4e72_31), 20082 }, /* STOP */
{ CPUFUNC(op_4e73_31), 20083 }, /* RTE */
{ CPUFUNC(op_4e74_31), 20084 }, /* RTD */
{ CPUFUNC(op_4e75_31), 20085 }, /* RTS */
{ CPUFUNC(op_4e76_31), 20086 }, /* TRAPV */
{ CPUFUNC(op_4e77_31), 20087 }, /* RTR */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4e7a_31), 20090 }, /* MOVEC2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4e7b_31), 20091 }, /* MOVE2C */
#endif
{ CPUFUNC(op_4e90_31), 20112 }, /* JSR */
{ CPUFUNC(op_4ea8_31), 20136 }, /* JSR */
{ CPUFUNC(op_4eb0_31), 20144 }, /* JSR */
{ CPUFUNC(op_4eb8_31), 20152 }, /* JSR */
{ CPUFUNC(op_4eb9_31), 20153 }, /* JSR */
{ CPUFUNC(op_4eba_31), 20154 }, /* JSR */
{ CPUFUNC(op_4ebb_31), 20155 }, /* JSR */
{ CPUFUNC(op_4ed0_31), 20176 }, /* JMP */
{ CPUFUNC(op_4ee8_31), 20200 }, /* JMP */
{ CPUFUNC(op_4ef0_31), 20208 }, /* JMP */
{ CPUFUNC(op_4ef8_31), 20216 }, /* JMP */
{ CPUFUNC(op_4ef9_31), 20217 }, /* JMP */
{ CPUFUNC(op_4efa_31), 20218 }, /* JMP */
{ CPUFUNC(op_4efb_31), 20219 }, /* JMP */
{ CPUFUNC(op_5000_31), 20480 }, /* ADD */
{ CPUFUNC(op_5010_31), 20496 }, /* ADD */
{ CPUFUNC(op_5018_31), 20504 }, /* ADD */
{ CPUFUNC(op_5020_31), 20512 }, /* ADD */
{ CPUFUNC(op_5028_31), 20520 }, /* ADD */
{ CPUFUNC(op_5030_31), 20528 }, /* ADD */
{ CPUFUNC(op_5038_31), 20536 }, /* ADD */
{ CPUFUNC(op_5039_31), 20537 }, /* ADD */
{ CPUFUNC(op_5040_31), 20544 }, /* ADD */
{ CPUFUNC(op_5048_31), 20552 }, /* ADDA */
{ CPUFUNC(op_5050_31), 20560 }, /* ADD */
{ CPUFUNC(op_5058_31), 20568 }, /* ADD */
{ CPUFUNC(op_5060_31), 20576 }, /* ADD */
{ CPUFUNC(op_5068_31), 20584 }, /* ADD */
{ CPUFUNC(op_5070_31), 20592 }, /* ADD */
{ CPUFUNC(op_5078_31), 20600 }, /* ADD */
{ CPUFUNC(op_5079_31), 20601 }, /* ADD */
{ CPUFUNC(op_5080_31), 20608 }, /* ADD */
{ CPUFUNC(op_5088_31), 20616 }, /* ADDA */
{ CPUFUNC(op_5090_31), 20624 }, /* ADD */
{ CPUFUNC(op_5098_31), 20632 }, /* ADD */
{ CPUFUNC(op_50a0_31), 20640 }, /* ADD */
{ CPUFUNC(op_50a8_31), 20648 }, /* ADD */
{ CPUFUNC(op_50b0_31), 20656 }, /* ADD */
{ CPUFUNC(op_50b8_31), 20664 }, /* ADD */
{ CPUFUNC(op_50b9_31), 20665 }, /* ADD */
{ CPUFUNC(op_50c0_31), 20672 }, /* Scc */
{ CPUFUNC(op_50c8_31), 20680 }, /* DBcc */
{ CPUFUNC(op_50d0_31), 20688 }, /* Scc */
{ CPUFUNC(op_50d8_31), 20696 }, /* Scc */
{ CPUFUNC(op_50e0_31), 20704 }, /* Scc */
{ CPUFUNC(op_50e8_31), 20712 }, /* Scc */
{ CPUFUNC(op_50f0_31), 20720 }, /* Scc */
{ CPUFUNC(op_50f8_31), 20728 }, /* Scc */
{ CPUFUNC(op_50f9_31), 20729 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_50fa_31), 20730 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_50fb_31), 20731 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_50fc_31), 20732 }, /* TRAPcc */
#endif
{ CPUFUNC(op_5100_31), 20736 }, /* SUB */
{ CPUFUNC(op_5110_31), 20752 }, /* SUB */
{ CPUFUNC(op_5118_31), 20760 }, /* SUB */
{ CPUFUNC(op_5120_31), 20768 }, /* SUB */
{ CPUFUNC(op_5128_31), 20776 }, /* SUB */
{ CPUFUNC(op_5130_31), 20784 }, /* SUB */
{ CPUFUNC(op_5138_31), 20792 }, /* SUB */
{ CPUFUNC(op_5139_31), 20793 }, /* SUB */
{ CPUFUNC(op_5140_31), 20800 }, /* SUB */
{ CPUFUNC(op_5148_31), 20808 }, /* SUBA */
{ CPUFUNC(op_5150_31), 20816 }, /* SUB */
{ CPUFUNC(op_5158_31), 20824 }, /* SUB */
{ CPUFUNC(op_5160_31), 20832 }, /* SUB */
{ CPUFUNC(op_5168_31), 20840 }, /* SUB */
{ CPUFUNC(op_5170_31), 20848 }, /* SUB */
{ CPUFUNC(op_5178_31), 20856 }, /* SUB */
{ CPUFUNC(op_5179_31), 20857 }, /* SUB */
{ CPUFUNC(op_5180_31), 20864 }, /* SUB */
{ CPUFUNC(op_5188_31), 20872 }, /* SUBA */
{ CPUFUNC(op_5190_31), 20880 }, /* SUB */
{ CPUFUNC(op_5198_31), 20888 }, /* SUB */
{ CPUFUNC(op_51a0_31), 20896 }, /* SUB */
{ CPUFUNC(op_51a8_31), 20904 }, /* SUB */
{ CPUFUNC(op_51b0_31), 20912 }, /* SUB */
{ CPUFUNC(op_51b8_31), 20920 }, /* SUB */
{ CPUFUNC(op_51b9_31), 20921 }, /* SUB */
{ CPUFUNC(op_51c0_31), 20928 }, /* Scc */
{ CPUFUNC(op_51c8_31), 20936 }, /* DBcc */
{ CPUFUNC(op_51d0_31), 20944 }, /* Scc */
{ CPUFUNC(op_51d8_31), 20952 }, /* Scc */
{ CPUFUNC(op_51e0_31), 20960 }, /* Scc */
{ CPUFUNC(op_51e8_31), 20968 }, /* Scc */
{ CPUFUNC(op_51f0_31), 20976 }, /* Scc */
{ CPUFUNC(op_51f8_31), 20984 }, /* Scc */
{ CPUFUNC(op_51f9_31), 20985 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_51fa_31), 20986 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_51fb_31), 20987 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_51fc_31), 20988 }, /* TRAPcc */
#endif
{ CPUFUNC(op_52c0_31), 21184 }, /* Scc */
{ CPUFUNC(op_52c8_31), 21192 }, /* DBcc */
{ CPUFUNC(op_52d0_31), 21200 }, /* Scc */
{ CPUFUNC(op_52d8_31), 21208 }, /* Scc */
{ CPUFUNC(op_52e0_31), 21216 }, /* Scc */
{ CPUFUNC(op_52e8_31), 21224 }, /* Scc */
{ CPUFUNC(op_52f0_31), 21232 }, /* Scc */
{ CPUFUNC(op_52f8_31), 21240 }, /* Scc */
{ CPUFUNC(op_52f9_31), 21241 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_52fa_31), 21242 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_52fb_31), 21243 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_52fc_31), 21244 }, /* TRAPcc */
#endif
{ CPUFUNC(op_53c0_31), 21440 }, /* Scc */
{ CPUFUNC(op_53c8_31), 21448 }, /* DBcc */
{ CPUFUNC(op_53d0_31), 21456 }, /* Scc */
{ CPUFUNC(op_53d8_31), 21464 }, /* Scc */
{ CPUFUNC(op_53e0_31), 21472 }, /* Scc */
{ CPUFUNC(op_53e8_31), 21480 }, /* Scc */
{ CPUFUNC(op_53f0_31), 21488 }, /* Scc */
{ CPUFUNC(op_53f8_31), 21496 }, /* Scc */
{ CPUFUNC(op_53f9_31), 21497 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_53fa_31), 21498 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_53fb_31), 21499 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_53fc_31), 21500 }, /* TRAPcc */
#endif
{ CPUFUNC(op_54c0_31), 21696 }, /* Scc */
{ CPUFUNC(op_54c8_31), 21704 }, /* DBcc */
{ CPUFUNC(op_54d0_31), 21712 }, /* Scc */
{ CPUFUNC(op_54d8_31), 21720 }, /* Scc */
{ CPUFUNC(op_54e0_31), 21728 }, /* Scc */
{ CPUFUNC(op_54e8_31), 21736 }, /* Scc */
{ CPUFUNC(op_54f0_31), 21744 }, /* Scc */
{ CPUFUNC(op_54f8_31), 21752 }, /* Scc */
{ CPUFUNC(op_54f9_31), 21753 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_54fa_31), 21754 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_54fb_31), 21755 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_54fc_31), 21756 }, /* TRAPcc */
#endif
{ CPUFUNC(op_55c0_31), 21952 }, /* Scc */
{ CPUFUNC(op_55c8_31), 21960 }, /* DBcc */
{ CPUFUNC(op_55d0_31), 21968 }, /* Scc */
{ CPUFUNC(op_55d8_31), 21976 }, /* Scc */
{ CPUFUNC(op_55e0_31), 21984 }, /* Scc */
{ CPUFUNC(op_55e8_31), 21992 }, /* Scc */
{ CPUFUNC(op_55f0_31), 22000 }, /* Scc */
{ CPUFUNC(op_55f8_31), 22008 }, /* Scc */
{ CPUFUNC(op_55f9_31), 22009 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_55fa_31), 22010 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_55fb_31), 22011 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_55fc_31), 22012 }, /* TRAPcc */
#endif
{ CPUFUNC(op_56c0_31), 22208 }, /* Scc */
{ CPUFUNC(op_56c8_31), 22216 }, /* DBcc */
{ CPUFUNC(op_56d0_31), 22224 }, /* Scc */
{ CPUFUNC(op_56d8_31), 22232 }, /* Scc */
{ CPUFUNC(op_56e0_31), 22240 }, /* Scc */
{ CPUFUNC(op_56e8_31), 22248 }, /* Scc */
{ CPUFUNC(op_56f0_31), 22256 }, /* Scc */
{ CPUFUNC(op_56f8_31), 22264 }, /* Scc */
{ CPUFUNC(op_56f9_31), 22265 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_56fa_31), 22266 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_56fb_31), 22267 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_56fc_31), 22268 }, /* TRAPcc */
#endif
{ CPUFUNC(op_57c0_31), 22464 }, /* Scc */
{ CPUFUNC(op_57c8_31), 22472 }, /* DBcc */
{ CPUFUNC(op_57d0_31), 22480 }, /* Scc */
{ CPUFUNC(op_57d8_31), 22488 }, /* Scc */
{ CPUFUNC(op_57e0_31), 22496 }, /* Scc */
{ CPUFUNC(op_57e8_31), 22504 }, /* Scc */
{ CPUFUNC(op_57f0_31), 22512 }, /* Scc */
{ CPUFUNC(op_57f8_31), 22520 }, /* Scc */
{ CPUFUNC(op_57f9_31), 22521 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_57fa_31), 22522 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_57fb_31), 22523 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_57fc_31), 22524 }, /* TRAPcc */
#endif
{ CPUFUNC(op_58c0_31), 22720 }, /* Scc */
{ CPUFUNC(op_58c8_31), 22728 }, /* DBcc */
{ CPUFUNC(op_58d0_31), 22736 }, /* Scc */
{ CPUFUNC(op_58d8_31), 22744 }, /* Scc */
{ CPUFUNC(op_58e0_31), 22752 }, /* Scc */
{ CPUFUNC(op_58e8_31), 22760 }, /* Scc */
{ CPUFUNC(op_58f0_31), 22768 }, /* Scc */
{ CPUFUNC(op_58f8_31), 22776 }, /* Scc */
{ CPUFUNC(op_58f9_31), 22777 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_58fa_31), 22778 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_58fb_31), 22779 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_58fc_31), 22780 }, /* TRAPcc */
#endif
{ CPUFUNC(op_59c0_31), 22976 }, /* Scc */
{ CPUFUNC(op_59c8_31), 22984 }, /* DBcc */
{ CPUFUNC(op_59d0_31), 22992 }, /* Scc */
{ CPUFUNC(op_59d8_31), 23000 }, /* Scc */
{ CPUFUNC(op_59e0_31), 23008 }, /* Scc */
{ CPUFUNC(op_59e8_31), 23016 }, /* Scc */
{ CPUFUNC(op_59f0_31), 23024 }, /* Scc */
{ CPUFUNC(op_59f8_31), 23032 }, /* Scc */
{ CPUFUNC(op_59f9_31), 23033 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_59fa_31), 23034 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_59fb_31), 23035 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_59fc_31), 23036 }, /* TRAPcc */
#endif
{ CPUFUNC(op_5ac0_31), 23232 }, /* Scc */
{ CPUFUNC(op_5ac8_31), 23240 }, /* DBcc */
{ CPUFUNC(op_5ad0_31), 23248 }, /* Scc */
{ CPUFUNC(op_5ad8_31), 23256 }, /* Scc */
{ CPUFUNC(op_5ae0_31), 23264 }, /* Scc */
{ CPUFUNC(op_5ae8_31), 23272 }, /* Scc */
{ CPUFUNC(op_5af0_31), 23280 }, /* Scc */
{ CPUFUNC(op_5af8_31), 23288 }, /* Scc */
{ CPUFUNC(op_5af9_31), 23289 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5afa_31), 23290 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5afb_31), 23291 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5afc_31), 23292 }, /* TRAPcc */
#endif
{ CPUFUNC(op_5bc0_31), 23488 }, /* Scc */
{ CPUFUNC(op_5bc8_31), 23496 }, /* DBcc */
{ CPUFUNC(op_5bd0_31), 23504 }, /* Scc */
{ CPUFUNC(op_5bd8_31), 23512 }, /* Scc */
{ CPUFUNC(op_5be0_31), 23520 }, /* Scc */
{ CPUFUNC(op_5be8_31), 23528 }, /* Scc */
{ CPUFUNC(op_5bf0_31), 23536 }, /* Scc */
{ CPUFUNC(op_5bf8_31), 23544 }, /* Scc */
{ CPUFUNC(op_5bf9_31), 23545 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5bfa_31), 23546 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5bfb_31), 23547 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5bfc_31), 23548 }, /* TRAPcc */
#endif
{ CPUFUNC(op_5cc0_31), 23744 }, /* Scc */
{ CPUFUNC(op_5cc8_31), 23752 }, /* DBcc */
{ CPUFUNC(op_5cd0_31), 23760 }, /* Scc */
{ CPUFUNC(op_5cd8_31), 23768 }, /* Scc */
{ CPUFUNC(op_5ce0_31), 23776 }, /* Scc */
{ CPUFUNC(op_5ce8_31), 23784 }, /* Scc */
{ CPUFUNC(op_5cf0_31), 23792 }, /* Scc */
{ CPUFUNC(op_5cf8_31), 23800 }, /* Scc */
{ CPUFUNC(op_5cf9_31), 23801 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5cfa_31), 23802 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5cfb_31), 23803 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5cfc_31), 23804 }, /* TRAPcc */
#endif
{ CPUFUNC(op_5dc0_31), 24000 }, /* Scc */
{ CPUFUNC(op_5dc8_31), 24008 }, /* DBcc */
{ CPUFUNC(op_5dd0_31), 24016 }, /* Scc */
{ CPUFUNC(op_5dd8_31), 24024 }, /* Scc */
{ CPUFUNC(op_5de0_31), 24032 }, /* Scc */
{ CPUFUNC(op_5de8_31), 24040 }, /* Scc */
{ CPUFUNC(op_5df0_31), 24048 }, /* Scc */
{ CPUFUNC(op_5df8_31), 24056 }, /* Scc */
{ CPUFUNC(op_5df9_31), 24057 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5dfa_31), 24058 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5dfb_31), 24059 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5dfc_31), 24060 }, /* TRAPcc */
#endif
{ CPUFUNC(op_5ec0_31), 24256 }, /* Scc */
{ CPUFUNC(op_5ec8_31), 24264 }, /* DBcc */
{ CPUFUNC(op_5ed0_31), 24272 }, /* Scc */
{ CPUFUNC(op_5ed8_31), 24280 }, /* Scc */
{ CPUFUNC(op_5ee0_31), 24288 }, /* Scc */
{ CPUFUNC(op_5ee8_31), 24296 }, /* Scc */
{ CPUFUNC(op_5ef0_31), 24304 }, /* Scc */
{ CPUFUNC(op_5ef8_31), 24312 }, /* Scc */
{ CPUFUNC(op_5ef9_31), 24313 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5efa_31), 24314 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5efb_31), 24315 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5efc_31), 24316 }, /* TRAPcc */
#endif
{ CPUFUNC(op_5fc0_31), 24512 }, /* Scc */
{ CPUFUNC(op_5fc8_31), 24520 }, /* DBcc */
{ CPUFUNC(op_5fd0_31), 24528 }, /* Scc */
{ CPUFUNC(op_5fd8_31), 24536 }, /* Scc */
{ CPUFUNC(op_5fe0_31), 24544 }, /* Scc */
{ CPUFUNC(op_5fe8_31), 24552 }, /* Scc */
{ CPUFUNC(op_5ff0_31), 24560 }, /* Scc */
{ CPUFUNC(op_5ff8_31), 24568 }, /* Scc */
{ CPUFUNC(op_5ff9_31), 24569 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5ffa_31), 24570 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5ffb_31), 24571 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5ffc_31), 24572 }, /* TRAPcc */
#endif
{ CPUFUNC(op_6000_31), 24576 }, /* Bcc */
{ CPUFUNC(op_6001_31), 24577 }, /* Bcc */
{ CPUFUNC(op_60ff_31), 24831 }, /* Bcc */
{ CPUFUNC(op_6100_31), 24832 }, /* BSR */
{ CPUFUNC(op_6101_31), 24833 }, /* BSR */
{ CPUFUNC(op_61ff_31), 25087 }, /* BSR */
{ CPUFUNC(op_6200_31), 25088 }, /* Bcc */
{ CPUFUNC(op_6201_31), 25089 }, /* Bcc */
{ CPUFUNC(op_62ff_31), 25343 }, /* Bcc */
{ CPUFUNC(op_6300_31), 25344 }, /* Bcc */
{ CPUFUNC(op_6301_31), 25345 }, /* Bcc */
{ CPUFUNC(op_63ff_31), 25599 }, /* Bcc */
{ CPUFUNC(op_6400_31), 25600 }, /* Bcc */
{ CPUFUNC(op_6401_31), 25601 }, /* Bcc */
{ CPUFUNC(op_64ff_31), 25855 }, /* Bcc */
{ CPUFUNC(op_6500_31), 25856 }, /* Bcc */
{ CPUFUNC(op_6501_31), 25857 }, /* Bcc */
{ CPUFUNC(op_65ff_31), 26111 }, /* Bcc */
{ CPUFUNC(op_6600_31), 26112 }, /* Bcc */
{ CPUFUNC(op_6601_31), 26113 }, /* Bcc */
{ CPUFUNC(op_66ff_31), 26367 }, /* Bcc */
{ CPUFUNC(op_6700_31), 26368 }, /* Bcc */
{ CPUFUNC(op_6701_31), 26369 }, /* Bcc */
{ CPUFUNC(op_67ff_31), 26623 }, /* Bcc */
{ CPUFUNC(op_6800_31), 26624 }, /* Bcc */
{ CPUFUNC(op_6801_31), 26625 }, /* Bcc */
{ CPUFUNC(op_68ff_31), 26879 }, /* Bcc */
{ CPUFUNC(op_6900_31), 26880 }, /* Bcc */
{ CPUFUNC(op_6901_31), 26881 }, /* Bcc */
{ CPUFUNC(op_69ff_31), 27135 }, /* Bcc */
{ CPUFUNC(op_6a00_31), 27136 }, /* Bcc */
{ CPUFUNC(op_6a01_31), 27137 }, /* Bcc */
{ CPUFUNC(op_6aff_31), 27391 }, /* Bcc */
{ CPUFUNC(op_6b00_31), 27392 }, /* Bcc */
{ CPUFUNC(op_6b01_31), 27393 }, /* Bcc */
{ CPUFUNC(op_6bff_31), 27647 }, /* Bcc */
{ CPUFUNC(op_6c00_31), 27648 }, /* Bcc */
{ CPUFUNC(op_6c01_31), 27649 }, /* Bcc */
{ CPUFUNC(op_6cff_31), 27903 }, /* Bcc */
{ CPUFUNC(op_6d00_31), 27904 }, /* Bcc */
{ CPUFUNC(op_6d01_31), 27905 }, /* Bcc */
{ CPUFUNC(op_6dff_31), 28159 }, /* Bcc */
{ CPUFUNC(op_6e00_31), 28160 }, /* Bcc */
{ CPUFUNC(op_6e01_31), 28161 }, /* Bcc */
{ CPUFUNC(op_6eff_31), 28415 }, /* Bcc */
{ CPUFUNC(op_6f00_31), 28416 }, /* Bcc */
{ CPUFUNC(op_6f01_31), 28417 }, /* Bcc */
{ CPUFUNC(op_6fff_31), 28671 }, /* Bcc */
{ CPUFUNC(op_7000_31), 28672 }, /* MOVE */
{ CPUFUNC(op_8000_31), 32768 }, /* OR */
{ CPUFUNC(op_8010_31), 32784 }, /* OR */
{ CPUFUNC(op_8018_31), 32792 }, /* OR */
{ CPUFUNC(op_8020_31), 32800 }, /* OR */
{ CPUFUNC(op_8028_31), 32808 }, /* OR */
{ CPUFUNC(op_8030_31), 32816 }, /* OR */
{ CPUFUNC(op_8038_31), 32824 }, /* OR */
{ CPUFUNC(op_8039_31), 32825 }, /* OR */
{ CPUFUNC(op_803a_31), 32826 }, /* OR */
{ CPUFUNC(op_803b_31), 32827 }, /* OR */
{ CPUFUNC(op_803c_31), 32828 }, /* OR */
{ CPUFUNC(op_8040_31), 32832 }, /* OR */
{ CPUFUNC(op_8050_31), 32848 }, /* OR */
{ CPUFUNC(op_8058_31), 32856 }, /* OR */
{ CPUFUNC(op_8060_31), 32864 }, /* OR */
{ CPUFUNC(op_8068_31), 32872 }, /* OR */
{ CPUFUNC(op_8070_31), 32880 }, /* OR */
{ CPUFUNC(op_8078_31), 32888 }, /* OR */
{ CPUFUNC(op_8079_31), 32889 }, /* OR */
{ CPUFUNC(op_807a_31), 32890 }, /* OR */
{ CPUFUNC(op_807b_31), 32891 }, /* OR */
{ CPUFUNC(op_807c_31), 32892 }, /* OR */
{ CPUFUNC(op_8080_31), 32896 }, /* OR */
{ CPUFUNC(op_8090_31), 32912 }, /* OR */
{ CPUFUNC(op_8098_31), 32920 }, /* OR */
{ CPUFUNC(op_80a0_31), 32928 }, /* OR */
{ CPUFUNC(op_80a8_31), 32936 }, /* OR */
{ CPUFUNC(op_80b0_31), 32944 }, /* OR */
{ CPUFUNC(op_80b8_31), 32952 }, /* OR */
{ CPUFUNC(op_80b9_31), 32953 }, /* OR */
{ CPUFUNC(op_80ba_31), 32954 }, /* OR */
{ CPUFUNC(op_80bb_31), 32955 }, /* OR */
{ CPUFUNC(op_80bc_31), 32956 }, /* OR */
{ CPUFUNC(op_80c0_31), 32960 }, /* DIVU */
{ CPUFUNC(op_80d0_31), 32976 }, /* DIVU */
{ CPUFUNC(op_80d8_31), 32984 }, /* DIVU */
{ CPUFUNC(op_80e0_31), 32992 }, /* DIVU */
{ CPUFUNC(op_80e8_31), 33000 }, /* DIVU */
{ CPUFUNC(op_80f0_31), 33008 }, /* DIVU */
{ CPUFUNC(op_80f8_31), 33016 }, /* DIVU */
{ CPUFUNC(op_80f9_31), 33017 }, /* DIVU */
{ CPUFUNC(op_80fa_31), 33018 }, /* DIVU */
{ CPUFUNC(op_80fb_31), 33019 }, /* DIVU */
{ CPUFUNC(op_80fc_31), 33020 }, /* DIVU */
{ CPUFUNC(op_8100_31), 33024 }, /* SBCD */
{ CPUFUNC(op_8108_31), 33032 }, /* SBCD */
{ CPUFUNC(op_8110_31), 33040 }, /* OR */
{ CPUFUNC(op_8118_31), 33048 }, /* OR */
{ CPUFUNC(op_8120_31), 33056 }, /* OR */
{ CPUFUNC(op_8128_31), 33064 }, /* OR */
{ CPUFUNC(op_8130_31), 33072 }, /* OR */
{ CPUFUNC(op_8138_31), 33080 }, /* OR */
{ CPUFUNC(op_8139_31), 33081 }, /* OR */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_8140_31), 33088 }, /* PACK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_8148_31), 33096 }, /* PACK */
#endif
{ CPUFUNC(op_8150_31), 33104 }, /* OR */
{ CPUFUNC(op_8158_31), 33112 }, /* OR */
{ CPUFUNC(op_8160_31), 33120 }, /* OR */
{ CPUFUNC(op_8168_31), 33128 }, /* OR */
{ CPUFUNC(op_8170_31), 33136 }, /* OR */
{ CPUFUNC(op_8178_31), 33144 }, /* OR */
{ CPUFUNC(op_8179_31), 33145 }, /* OR */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_8180_31), 33152 }, /* UNPK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_8188_31), 33160 }, /* UNPK */
#endif
{ CPUFUNC(op_8190_31), 33168 }, /* OR */
{ CPUFUNC(op_8198_31), 33176 }, /* OR */
{ CPUFUNC(op_81a0_31), 33184 }, /* OR */
{ CPUFUNC(op_81a8_31), 33192 }, /* OR */
{ CPUFUNC(op_81b0_31), 33200 }, /* OR */
{ CPUFUNC(op_81b8_31), 33208 }, /* OR */
{ CPUFUNC(op_81b9_31), 33209 }, /* OR */
{ CPUFUNC(op_81c0_31), 33216 }, /* DIVS */
{ CPUFUNC(op_81d0_31), 33232 }, /* DIVS */
{ CPUFUNC(op_81d8_31), 33240 }, /* DIVS */
{ CPUFUNC(op_81e0_31), 33248 }, /* DIVS */
{ CPUFUNC(op_81e8_31), 33256 }, /* DIVS */
{ CPUFUNC(op_81f0_31), 33264 }, /* DIVS */
{ CPUFUNC(op_81f8_31), 33272 }, /* DIVS */
{ CPUFUNC(op_81f9_31), 33273 }, /* DIVS */
{ CPUFUNC(op_81fa_31), 33274 }, /* DIVS */
{ CPUFUNC(op_81fb_31), 33275 }, /* DIVS */
{ CPUFUNC(op_81fc_31), 33276 }, /* DIVS */
{ CPUFUNC(op_9000_31), 36864 }, /* SUB */
{ CPUFUNC(op_9010_31), 36880 }, /* SUB */
{ CPUFUNC(op_9018_31), 36888 }, /* SUB */
{ CPUFUNC(op_9020_31), 36896 }, /* SUB */
{ CPUFUNC(op_9028_31), 36904 }, /* SUB */
{ CPUFUNC(op_9030_31), 36912 }, /* SUB */
{ CPUFUNC(op_9038_31), 36920 }, /* SUB */
{ CPUFUNC(op_9039_31), 36921 }, /* SUB */
{ CPUFUNC(op_903a_31), 36922 }, /* SUB */
{ CPUFUNC(op_903b_31), 36923 }, /* SUB */
{ CPUFUNC(op_903c_31), 36924 }, /* SUB */
{ CPUFUNC(op_9040_31), 36928 }, /* SUB */
{ CPUFUNC(op_9048_31), 36936 }, /* SUB */
{ CPUFUNC(op_9050_31), 36944 }, /* SUB */
{ CPUFUNC(op_9058_31), 36952 }, /* SUB */
{ CPUFUNC(op_9060_31), 36960 }, /* SUB */
{ CPUFUNC(op_9068_31), 36968 }, /* SUB */
{ CPUFUNC(op_9070_31), 36976 }, /* SUB */
{ CPUFUNC(op_9078_31), 36984 }, /* SUB */
{ CPUFUNC(op_9079_31), 36985 }, /* SUB */
{ CPUFUNC(op_907a_31), 36986 }, /* SUB */
{ CPUFUNC(op_907b_31), 36987 }, /* SUB */
{ CPUFUNC(op_907c_31), 36988 }, /* SUB */
{ CPUFUNC(op_9080_31), 36992 }, /* SUB */
{ CPUFUNC(op_9088_31), 37000 }, /* SUB */
{ CPUFUNC(op_9090_31), 37008 }, /* SUB */
{ CPUFUNC(op_9098_31), 37016 }, /* SUB */
{ CPUFUNC(op_90a0_31), 37024 }, /* SUB */
{ CPUFUNC(op_90a8_31), 37032 }, /* SUB */
{ CPUFUNC(op_90b0_31), 37040 }, /* SUB */
{ CPUFUNC(op_90b8_31), 37048 }, /* SUB */
{ CPUFUNC(op_90b9_31), 37049 }, /* SUB */
{ CPUFUNC(op_90ba_31), 37050 }, /* SUB */
{ CPUFUNC(op_90bb_31), 37051 }, /* SUB */
{ CPUFUNC(op_90bc_31), 37052 }, /* SUB */
{ CPUFUNC(op_90c0_31), 37056 }, /* SUBA */
{ CPUFUNC(op_90c8_31), 37064 }, /* SUBA */
{ CPUFUNC(op_90d0_31), 37072 }, /* SUBA */
{ CPUFUNC(op_90d8_31), 37080 }, /* SUBA */
{ CPUFUNC(op_90e0_31), 37088 }, /* SUBA */
{ CPUFUNC(op_90e8_31), 37096 }, /* SUBA */
{ CPUFUNC(op_90f0_31), 37104 }, /* SUBA */
{ CPUFUNC(op_90f8_31), 37112 }, /* SUBA */
{ CPUFUNC(op_90f9_31), 37113 }, /* SUBA */
{ CPUFUNC(op_90fa_31), 37114 }, /* SUBA */
{ CPUFUNC(op_90fb_31), 37115 }, /* SUBA */
{ CPUFUNC(op_90fc_31), 37116 }, /* SUBA */
{ CPUFUNC(op_9100_31), 37120 }, /* SUBX */
{ CPUFUNC(op_9108_31), 37128 }, /* SUBX */
{ CPUFUNC(op_9110_31), 37136 }, /* SUB */
{ CPUFUNC(op_9118_31), 37144 }, /* SUB */
{ CPUFUNC(op_9120_31), 37152 }, /* SUB */
{ CPUFUNC(op_9128_31), 37160 }, /* SUB */
{ CPUFUNC(op_9130_31), 37168 }, /* SUB */
{ CPUFUNC(op_9138_31), 37176 }, /* SUB */
{ CPUFUNC(op_9139_31), 37177 }, /* SUB */
{ CPUFUNC(op_9140_31), 37184 }, /* SUBX */
{ CPUFUNC(op_9148_31), 37192 }, /* SUBX */
{ CPUFUNC(op_9150_31), 37200 }, /* SUB */
{ CPUFUNC(op_9158_31), 37208 }, /* SUB */
{ CPUFUNC(op_9160_31), 37216 }, /* SUB */
{ CPUFUNC(op_9168_31), 37224 }, /* SUB */
{ CPUFUNC(op_9170_31), 37232 }, /* SUB */
{ CPUFUNC(op_9178_31), 37240 }, /* SUB */
{ CPUFUNC(op_9179_31), 37241 }, /* SUB */
{ CPUFUNC(op_9180_31), 37248 }, /* SUBX */
{ CPUFUNC(op_9188_31), 37256 }, /* SUBX */
{ CPUFUNC(op_9190_31), 37264 }, /* SUB */
{ CPUFUNC(op_9198_31), 37272 }, /* SUB */
{ CPUFUNC(op_91a0_31), 37280 }, /* SUB */
{ CPUFUNC(op_91a8_31), 37288 }, /* SUB */
{ CPUFUNC(op_91b0_31), 37296 }, /* SUB */
{ CPUFUNC(op_91b8_31), 37304 }, /* SUB */
{ CPUFUNC(op_91b9_31), 37305 }, /* SUB */
{ CPUFUNC(op_91c0_31), 37312 }, /* SUBA */
{ CPUFUNC(op_91c8_31), 37320 }, /* SUBA */
{ CPUFUNC(op_91d0_31), 37328 }, /* SUBA */
{ CPUFUNC(op_91d8_31), 37336 }, /* SUBA */
{ CPUFUNC(op_91e0_31), 37344 }, /* SUBA */
{ CPUFUNC(op_91e8_31), 37352 }, /* SUBA */
{ CPUFUNC(op_91f0_31), 37360 }, /* SUBA */
{ CPUFUNC(op_91f8_31), 37368 }, /* SUBA */
{ CPUFUNC(op_91f9_31), 37369 }, /* SUBA */
{ CPUFUNC(op_91fa_31), 37370 }, /* SUBA */
{ CPUFUNC(op_91fb_31), 37371 }, /* SUBA */
{ CPUFUNC(op_91fc_31), 37372 }, /* SUBA */
{ CPUFUNC(op_b000_31), 45056 }, /* CMP */
{ CPUFUNC(op_b010_31), 45072 }, /* CMP */
{ CPUFUNC(op_b018_31), 45080 }, /* CMP */
{ CPUFUNC(op_b020_31), 45088 }, /* CMP */
{ CPUFUNC(op_b028_31), 45096 }, /* CMP */
{ CPUFUNC(op_b030_31), 45104 }, /* CMP */
{ CPUFUNC(op_b038_31), 45112 }, /* CMP */
{ CPUFUNC(op_b039_31), 45113 }, /* CMP */
{ CPUFUNC(op_b03a_31), 45114 }, /* CMP */
{ CPUFUNC(op_b03b_31), 45115 }, /* CMP */
{ CPUFUNC(op_b03c_31), 45116 }, /* CMP */
{ CPUFUNC(op_b040_31), 45120 }, /* CMP */
{ CPUFUNC(op_b048_31), 45128 }, /* CMP */
{ CPUFUNC(op_b050_31), 45136 }, /* CMP */
{ CPUFUNC(op_b058_31), 45144 }, /* CMP */
{ CPUFUNC(op_b060_31), 45152 }, /* CMP */
{ CPUFUNC(op_b068_31), 45160 }, /* CMP */
{ CPUFUNC(op_b070_31), 45168 }, /* CMP */
{ CPUFUNC(op_b078_31), 45176 }, /* CMP */
{ CPUFUNC(op_b079_31), 45177 }, /* CMP */
{ CPUFUNC(op_b07a_31), 45178 }, /* CMP */
{ CPUFUNC(op_b07b_31), 45179 }, /* CMP */
{ CPUFUNC(op_b07c_31), 45180 }, /* CMP */
{ CPUFUNC(op_b080_31), 45184 }, /* CMP */
{ CPUFUNC(op_b088_31), 45192 }, /* CMP */
{ CPUFUNC(op_b090_31), 45200 }, /* CMP */
{ CPUFUNC(op_b098_31), 45208 }, /* CMP */
{ CPUFUNC(op_b0a0_31), 45216 }, /* CMP */
{ CPUFUNC(op_b0a8_31), 45224 }, /* CMP */
{ CPUFUNC(op_b0b0_31), 45232 }, /* CMP */
{ CPUFUNC(op_b0b8_31), 45240 }, /* CMP */
{ CPUFUNC(op_b0b9_31), 45241 }, /* CMP */
{ CPUFUNC(op_b0ba_31), 45242 }, /* CMP */
{ CPUFUNC(op_b0bb_31), 45243 }, /* CMP */
{ CPUFUNC(op_b0bc_31), 45244 }, /* CMP */
{ CPUFUNC(op_b0c0_31), 45248 }, /* CMPA */
{ CPUFUNC(op_b0c8_31), 45256 }, /* CMPA */
{ CPUFUNC(op_b0d0_31), 45264 }, /* CMPA */
{ CPUFUNC(op_b0d8_31), 45272 }, /* CMPA */
{ CPUFUNC(op_b0e0_31), 45280 }, /* CMPA */
{ CPUFUNC(op_b0e8_31), 45288 }, /* CMPA */
{ CPUFUNC(op_b0f0_31), 45296 }, /* CMPA */
{ CPUFUNC(op_b0f8_31), 45304 }, /* CMPA */
{ CPUFUNC(op_b0f9_31), 45305 }, /* CMPA */
{ CPUFUNC(op_b0fa_31), 45306 }, /* CMPA */
{ CPUFUNC(op_b0fb_31), 45307 }, /* CMPA */
{ CPUFUNC(op_b0fc_31), 45308 }, /* CMPA */
{ CPUFUNC(op_b100_31), 45312 }, /* EOR */
{ CPUFUNC(op_b108_31), 45320 }, /* CMPM */
{ CPUFUNC(op_b110_31), 45328 }, /* EOR */
{ CPUFUNC(op_b118_31), 45336 }, /* EOR */
{ CPUFUNC(op_b120_31), 45344 }, /* EOR */
{ CPUFUNC(op_b128_31), 45352 }, /* EOR */
{ CPUFUNC(op_b130_31), 45360 }, /* EOR */
{ CPUFUNC(op_b138_31), 45368 }, /* EOR */
{ CPUFUNC(op_b139_31), 45369 }, /* EOR */
{ CPUFUNC(op_b140_31), 45376 }, /* EOR */
{ CPUFUNC(op_b148_31), 45384 }, /* CMPM */
{ CPUFUNC(op_b150_31), 45392 }, /* EOR */
{ CPUFUNC(op_b158_31), 45400 }, /* EOR */
{ CPUFUNC(op_b160_31), 45408 }, /* EOR */
{ CPUFUNC(op_b168_31), 45416 }, /* EOR */
{ CPUFUNC(op_b170_31), 45424 }, /* EOR */
{ CPUFUNC(op_b178_31), 45432 }, /* EOR */
{ CPUFUNC(op_b179_31), 45433 }, /* EOR */
{ CPUFUNC(op_b180_31), 45440 }, /* EOR */
{ CPUFUNC(op_b188_31), 45448 }, /* CMPM */
{ CPUFUNC(op_b190_31), 45456 }, /* EOR */
{ CPUFUNC(op_b198_31), 45464 }, /* EOR */
{ CPUFUNC(op_b1a0_31), 45472 }, /* EOR */
{ CPUFUNC(op_b1a8_31), 45480 }, /* EOR */
{ CPUFUNC(op_b1b0_31), 45488 }, /* EOR */
{ CPUFUNC(op_b1b8_31), 45496 }, /* EOR */
{ CPUFUNC(op_b1b9_31), 45497 }, /* EOR */
{ CPUFUNC(op_b1c0_31), 45504 }, /* CMPA */
{ CPUFUNC(op_b1c8_31), 45512 }, /* CMPA */
{ CPUFUNC(op_b1d0_31), 45520 }, /* CMPA */
{ CPUFUNC(op_b1d8_31), 45528 }, /* CMPA */
{ CPUFUNC(op_b1e0_31), 45536 }, /* CMPA */
{ CPUFUNC(op_b1e8_31), 45544 }, /* CMPA */
{ CPUFUNC(op_b1f0_31), 45552 }, /* CMPA */
{ CPUFUNC(op_b1f8_31), 45560 }, /* CMPA */
{ CPUFUNC(op_b1f9_31), 45561 }, /* CMPA */
{ CPUFUNC(op_b1fa_31), 45562 }, /* CMPA */
{ CPUFUNC(op_b1fb_31), 45563 }, /* CMPA */
{ CPUFUNC(op_b1fc_31), 45564 }, /* CMPA */
{ CPUFUNC(op_c000_31), 49152 }, /* AND */
{ CPUFUNC(op_c010_31), 49168 }, /* AND */
{ CPUFUNC(op_c018_31), 49176 }, /* AND */
{ CPUFUNC(op_c020_31), 49184 }, /* AND */
{ CPUFUNC(op_c028_31), 49192 }, /* AND */
{ CPUFUNC(op_c030_31), 49200 }, /* AND */
{ CPUFUNC(op_c038_31), 49208 }, /* AND */
{ CPUFUNC(op_c039_31), 49209 }, /* AND */
{ CPUFUNC(op_c03a_31), 49210 }, /* AND */
{ CPUFUNC(op_c03b_31), 49211 }, /* AND */
{ CPUFUNC(op_c03c_31), 49212 }, /* AND */
{ CPUFUNC(op_c040_31), 49216 }, /* AND */
{ CPUFUNC(op_c050_31), 49232 }, /* AND */
{ CPUFUNC(op_c058_31), 49240 }, /* AND */
{ CPUFUNC(op_c060_31), 49248 }, /* AND */
{ CPUFUNC(op_c068_31), 49256 }, /* AND */
{ CPUFUNC(op_c070_31), 49264 }, /* AND */
{ CPUFUNC(op_c078_31), 49272 }, /* AND */
{ CPUFUNC(op_c079_31), 49273 }, /* AND */
{ CPUFUNC(op_c07a_31), 49274 }, /* AND */
{ CPUFUNC(op_c07b_31), 49275 }, /* AND */
{ CPUFUNC(op_c07c_31), 49276 }, /* AND */
{ CPUFUNC(op_c080_31), 49280 }, /* AND */
{ CPUFUNC(op_c090_31), 49296 }, /* AND */
{ CPUFUNC(op_c098_31), 49304 }, /* AND */
{ CPUFUNC(op_c0a0_31), 49312 }, /* AND */
{ CPUFUNC(op_c0a8_31), 49320 }, /* AND */
{ CPUFUNC(op_c0b0_31), 49328 }, /* AND */
{ CPUFUNC(op_c0b8_31), 49336 }, /* AND */
{ CPUFUNC(op_c0b9_31), 49337 }, /* AND */
{ CPUFUNC(op_c0ba_31), 49338 }, /* AND */
{ CPUFUNC(op_c0bb_31), 49339 }, /* AND */
{ CPUFUNC(op_c0bc_31), 49340 }, /* AND */
{ CPUFUNC(op_c0c0_31), 49344 }, /* MULU */
{ CPUFUNC(op_c0d0_31), 49360 }, /* MULU */
{ CPUFUNC(op_c0d8_31), 49368 }, /* MULU */
{ CPUFUNC(op_c0e0_31), 49376 }, /* MULU */
{ CPUFUNC(op_c0e8_31), 49384 }, /* MULU */
{ CPUFUNC(op_c0f0_31), 49392 }, /* MULU */
{ CPUFUNC(op_c0f8_31), 49400 }, /* MULU */
{ CPUFUNC(op_c0f9_31), 49401 }, /* MULU */
{ CPUFUNC(op_c0fa_31), 49402 }, /* MULU */
{ CPUFUNC(op_c0fb_31), 49403 }, /* MULU */
{ CPUFUNC(op_c0fc_31), 49404 }, /* MULU */
{ CPUFUNC(op_c100_31), 49408 }, /* ABCD */
{ CPUFUNC(op_c108_31), 49416 }, /* ABCD */
{ CPUFUNC(op_c110_31), 49424 }, /* AND */
{ CPUFUNC(op_c118_31), 49432 }, /* AND */
{ CPUFUNC(op_c120_31), 49440 }, /* AND */
{ CPUFUNC(op_c128_31), 49448 }, /* AND */
{ CPUFUNC(op_c130_31), 49456 }, /* AND */
{ CPUFUNC(op_c138_31), 49464 }, /* AND */
{ CPUFUNC(op_c139_31), 49465 }, /* AND */
{ CPUFUNC(op_c140_31), 49472 }, /* EXG */
{ CPUFUNC(op_c148_31), 49480 }, /* EXG */
{ CPUFUNC(op_c150_31), 49488 }, /* AND */
{ CPUFUNC(op_c158_31), 49496 }, /* AND */
{ CPUFUNC(op_c160_31), 49504 }, /* AND */
{ CPUFUNC(op_c168_31), 49512 }, /* AND */
{ CPUFUNC(op_c170_31), 49520 }, /* AND */
{ CPUFUNC(op_c178_31), 49528 }, /* AND */
{ CPUFUNC(op_c179_31), 49529 }, /* AND */
{ CPUFUNC(op_c188_31), 49544 }, /* EXG */
{ CPUFUNC(op_c190_31), 49552 }, /* AND */
{ CPUFUNC(op_c198_31), 49560 }, /* AND */
{ CPUFUNC(op_c1a0_31), 49568 }, /* AND */
{ CPUFUNC(op_c1a8_31), 49576 }, /* AND */
{ CPUFUNC(op_c1b0_31), 49584 }, /* AND */
{ CPUFUNC(op_c1b8_31), 49592 }, /* AND */
{ CPUFUNC(op_c1b9_31), 49593 }, /* AND */
{ CPUFUNC(op_c1c0_31), 49600 }, /* MULS */
{ CPUFUNC(op_c1d0_31), 49616 }, /* MULS */
{ CPUFUNC(op_c1d8_31), 49624 }, /* MULS */
{ CPUFUNC(op_c1e0_31), 49632 }, /* MULS */
{ CPUFUNC(op_c1e8_31), 49640 }, /* MULS */
{ CPUFUNC(op_c1f0_31), 49648 }, /* MULS */
{ CPUFUNC(op_c1f8_31), 49656 }, /* MULS */
{ CPUFUNC(op_c1f9_31), 49657 }, /* MULS */
{ CPUFUNC(op_c1fa_31), 49658 }, /* MULS */
{ CPUFUNC(op_c1fb_31), 49659 }, /* MULS */
{ CPUFUNC(op_c1fc_31), 49660 }, /* MULS */
{ CPUFUNC(op_d000_31), 53248 }, /* ADD */
{ CPUFUNC(op_d010_31), 53264 }, /* ADD */
{ CPUFUNC(op_d018_31), 53272 }, /* ADD */
{ CPUFUNC(op_d020_31), 53280 }, /* ADD */
{ CPUFUNC(op_d028_31), 53288 }, /* ADD */
{ CPUFUNC(op_d030_31), 53296 }, /* ADD */
{ CPUFUNC(op_d038_31), 53304 }, /* ADD */
{ CPUFUNC(op_d039_31), 53305 }, /* ADD */
{ CPUFUNC(op_d03a_31), 53306 }, /* ADD */
{ CPUFUNC(op_d03b_31), 53307 }, /* ADD */
{ CPUFUNC(op_d03c_31), 53308 }, /* ADD */
{ CPUFUNC(op_d040_31), 53312 }, /* ADD */
{ CPUFUNC(op_d048_31), 53320 }, /* ADD */
{ CPUFUNC(op_d050_31), 53328 }, /* ADD */
{ CPUFUNC(op_d058_31), 53336 }, /* ADD */
{ CPUFUNC(op_d060_31), 53344 }, /* ADD */
{ CPUFUNC(op_d068_31), 53352 }, /* ADD */
{ CPUFUNC(op_d070_31), 53360 }, /* ADD */
{ CPUFUNC(op_d078_31), 53368 }, /* ADD */
{ CPUFUNC(op_d079_31), 53369 }, /* ADD */
{ CPUFUNC(op_d07a_31), 53370 }, /* ADD */
{ CPUFUNC(op_d07b_31), 53371 }, /* ADD */
{ CPUFUNC(op_d07c_31), 53372 }, /* ADD */
{ CPUFUNC(op_d080_31), 53376 }, /* ADD */
{ CPUFUNC(op_d088_31), 53384 }, /* ADD */
{ CPUFUNC(op_d090_31), 53392 }, /* ADD */
{ CPUFUNC(op_d098_31), 53400 }, /* ADD */
{ CPUFUNC(op_d0a0_31), 53408 }, /* ADD */
{ CPUFUNC(op_d0a8_31), 53416 }, /* ADD */
{ CPUFUNC(op_d0b0_31), 53424 }, /* ADD */
{ CPUFUNC(op_d0b8_31), 53432 }, /* ADD */
{ CPUFUNC(op_d0b9_31), 53433 }, /* ADD */
{ CPUFUNC(op_d0ba_31), 53434 }, /* ADD */
{ CPUFUNC(op_d0bb_31), 53435 }, /* ADD */
{ CPUFUNC(op_d0bc_31), 53436 }, /* ADD */
{ CPUFUNC(op_d0c0_31), 53440 }, /* ADDA */
{ CPUFUNC(op_d0c8_31), 53448 }, /* ADDA */
{ CPUFUNC(op_d0d0_31), 53456 }, /* ADDA */
{ CPUFUNC(op_d0d8_31), 53464 }, /* ADDA */
{ CPUFUNC(op_d0e0_31), 53472 }, /* ADDA */
{ CPUFUNC(op_d0e8_31), 53480 }, /* ADDA */
{ CPUFUNC(op_d0f0_31), 53488 }, /* ADDA */
{ CPUFUNC(op_d0f8_31), 53496 }, /* ADDA */
{ CPUFUNC(op_d0f9_31), 53497 }, /* ADDA */
{ CPUFUNC(op_d0fa_31), 53498 }, /* ADDA */
{ CPUFUNC(op_d0fb_31), 53499 }, /* ADDA */
{ CPUFUNC(op_d0fc_31), 53500 }, /* ADDA */
{ CPUFUNC(op_d100_31), 53504 }, /* ADDX */
{ CPUFUNC(op_d108_31), 53512 }, /* ADDX */
{ CPUFUNC(op_d110_31), 53520 }, /* ADD */
{ CPUFUNC(op_d118_31), 53528 }, /* ADD */
{ CPUFUNC(op_d120_31), 53536 }, /* ADD */
{ CPUFUNC(op_d128_31), 53544 }, /* ADD */
{ CPUFUNC(op_d130_31), 53552 }, /* ADD */
{ CPUFUNC(op_d138_31), 53560 }, /* ADD */
{ CPUFUNC(op_d139_31), 53561 }, /* ADD */
{ CPUFUNC(op_d140_31), 53568 }, /* ADDX */
{ CPUFUNC(op_d148_31), 53576 }, /* ADDX */
{ CPUFUNC(op_d150_31), 53584 }, /* ADD */
{ CPUFUNC(op_d158_31), 53592 }, /* ADD */
{ CPUFUNC(op_d160_31), 53600 }, /* ADD */
{ CPUFUNC(op_d168_31), 53608 }, /* ADD */
{ CPUFUNC(op_d170_31), 53616 }, /* ADD */
{ CPUFUNC(op_d178_31), 53624 }, /* ADD */
{ CPUFUNC(op_d179_31), 53625 }, /* ADD */
{ CPUFUNC(op_d180_31), 53632 }, /* ADDX */
{ CPUFUNC(op_d188_31), 53640 }, /* ADDX */
{ CPUFUNC(op_d190_31), 53648 }, /* ADD */
{ CPUFUNC(op_d198_31), 53656 }, /* ADD */
{ CPUFUNC(op_d1a0_31), 53664 }, /* ADD */
{ CPUFUNC(op_d1a8_31), 53672 }, /* ADD */
{ CPUFUNC(op_d1b0_31), 53680 }, /* ADD */
{ CPUFUNC(op_d1b8_31), 53688 }, /* ADD */
{ CPUFUNC(op_d1b9_31), 53689 }, /* ADD */
{ CPUFUNC(op_d1c0_31), 53696 }, /* ADDA */
{ CPUFUNC(op_d1c8_31), 53704 }, /* ADDA */
{ CPUFUNC(op_d1d0_31), 53712 }, /* ADDA */
{ CPUFUNC(op_d1d8_31), 53720 }, /* ADDA */
{ CPUFUNC(op_d1e0_31), 53728 }, /* ADDA */
{ CPUFUNC(op_d1e8_31), 53736 }, /* ADDA */
{ CPUFUNC(op_d1f0_31), 53744 }, /* ADDA */
{ CPUFUNC(op_d1f8_31), 53752 }, /* ADDA */
{ CPUFUNC(op_d1f9_31), 53753 }, /* ADDA */
{ CPUFUNC(op_d1fa_31), 53754 }, /* ADDA */
{ CPUFUNC(op_d1fb_31), 53755 }, /* ADDA */
{ CPUFUNC(op_d1fc_31), 53756 }, /* ADDA */
{ CPUFUNC(op_e000_31), 57344 }, /* ASR */
{ CPUFUNC(op_e008_31), 57352 }, /* LSR */
{ CPUFUNC(op_e010_31), 57360 }, /* ROXR */
{ CPUFUNC(op_e018_31), 57368 }, /* ROR */
{ CPUFUNC(op_e020_31), 57376 }, /* ASR */
{ CPUFUNC(op_e028_31), 57384 }, /* LSR */
{ CPUFUNC(op_e030_31), 57392 }, /* ROXR */
{ CPUFUNC(op_e038_31), 57400 }, /* ROR */
{ CPUFUNC(op_e040_31), 57408 }, /* ASR */
{ CPUFUNC(op_e048_31), 57416 }, /* LSR */
{ CPUFUNC(op_e050_31), 57424 }, /* ROXR */
{ CPUFUNC(op_e058_31), 57432 }, /* ROR */
{ CPUFUNC(op_e060_31), 57440 }, /* ASR */
{ CPUFUNC(op_e068_31), 57448 }, /* LSR */
{ CPUFUNC(op_e070_31), 57456 }, /* ROXR */
{ CPUFUNC(op_e078_31), 57464 }, /* ROR */
{ CPUFUNC(op_e080_31), 57472 }, /* ASR */
{ CPUFUNC(op_e088_31), 57480 }, /* LSR */
{ CPUFUNC(op_e090_31), 57488 }, /* ROXR */
{ CPUFUNC(op_e098_31), 57496 }, /* ROR */
{ CPUFUNC(op_e0a0_31), 57504 }, /* ASR */
{ CPUFUNC(op_e0a8_31), 57512 }, /* LSR */
{ CPUFUNC(op_e0b0_31), 57520 }, /* ROXR */
{ CPUFUNC(op_e0b8_31), 57528 }, /* ROR */
{ CPUFUNC(op_e0d0_31), 57552 }, /* ASRW */
{ CPUFUNC(op_e0d8_31), 57560 }, /* ASRW */
{ CPUFUNC(op_e0e0_31), 57568 }, /* ASRW */
{ CPUFUNC(op_e0e8_31), 57576 }, /* ASRW */
{ CPUFUNC(op_e0f0_31), 57584 }, /* ASRW */
{ CPUFUNC(op_e0f8_31), 57592 }, /* ASRW */
{ CPUFUNC(op_e0f9_31), 57593 }, /* ASRW */
{ CPUFUNC(op_e100_31), 57600 }, /* ASL */
{ CPUFUNC(op_e108_31), 57608 }, /* LSL */
{ CPUFUNC(op_e110_31), 57616 }, /* ROXL */
{ CPUFUNC(op_e118_31), 57624 }, /* ROL */
{ CPUFUNC(op_e120_31), 57632 }, /* ASL */
{ CPUFUNC(op_e128_31), 57640 }, /* LSL */
{ CPUFUNC(op_e130_31), 57648 }, /* ROXL */
{ CPUFUNC(op_e138_31), 57656 }, /* ROL */
{ CPUFUNC(op_e140_31), 57664 }, /* ASL */
{ CPUFUNC(op_e148_31), 57672 }, /* LSL */
{ CPUFUNC(op_e150_31), 57680 }, /* ROXL */
{ CPUFUNC(op_e158_31), 57688 }, /* ROL */
{ CPUFUNC(op_e160_31), 57696 }, /* ASL */
{ CPUFUNC(op_e168_31), 57704 }, /* LSL */
{ CPUFUNC(op_e170_31), 57712 }, /* ROXL */
{ CPUFUNC(op_e178_31), 57720 }, /* ROL */
{ CPUFUNC(op_e180_31), 57728 }, /* ASL */
{ CPUFUNC(op_e188_31), 57736 }, /* LSL */
{ CPUFUNC(op_e190_31), 57744 }, /* ROXL */
{ CPUFUNC(op_e198_31), 57752 }, /* ROL */
{ CPUFUNC(op_e1a0_31), 57760 }, /* ASL */
{ CPUFUNC(op_e1a8_31), 57768 }, /* LSL */
{ CPUFUNC(op_e1b0_31), 57776 }, /* ROXL */
{ CPUFUNC(op_e1b8_31), 57784 }, /* ROL */
{ CPUFUNC(op_e1d0_31), 57808 }, /* ASLW */
{ CPUFUNC(op_e1d8_31), 57816 }, /* ASLW */
{ CPUFUNC(op_e1e0_31), 57824 }, /* ASLW */
{ CPUFUNC(op_e1e8_31), 57832 }, /* ASLW */
{ CPUFUNC(op_e1f0_31), 57840 }, /* ASLW */
{ CPUFUNC(op_e1f8_31), 57848 }, /* ASLW */
{ CPUFUNC(op_e1f9_31), 57849 }, /* ASLW */
{ CPUFUNC(op_e2d0_31), 58064 }, /* LSRW */
{ CPUFUNC(op_e2d8_31), 58072 }, /* LSRW */
{ CPUFUNC(op_e2e0_31), 58080 }, /* LSRW */
{ CPUFUNC(op_e2e8_31), 58088 }, /* LSRW */
{ CPUFUNC(op_e2f0_31), 58096 }, /* LSRW */
{ CPUFUNC(op_e2f8_31), 58104 }, /* LSRW */
{ CPUFUNC(op_e2f9_31), 58105 }, /* LSRW */
{ CPUFUNC(op_e3d0_31), 58320 }, /* LSLW */
{ CPUFUNC(op_e3d8_31), 58328 }, /* LSLW */
{ CPUFUNC(op_e3e0_31), 58336 }, /* LSLW */
{ CPUFUNC(op_e3e8_31), 58344 }, /* LSLW */
{ CPUFUNC(op_e3f0_31), 58352 }, /* LSLW */
{ CPUFUNC(op_e3f8_31), 58360 }, /* LSLW */
{ CPUFUNC(op_e3f9_31), 58361 }, /* LSLW */
{ CPUFUNC(op_e4d0_31), 58576 }, /* ROXRW */
{ CPUFUNC(op_e4d8_31), 58584 }, /* ROXRW */
{ CPUFUNC(op_e4e0_31), 58592 }, /* ROXRW */
{ CPUFUNC(op_e4e8_31), 58600 }, /* ROXRW */
{ CPUFUNC(op_e4f0_31), 58608 }, /* ROXRW */
{ CPUFUNC(op_e4f8_31), 58616 }, /* ROXRW */
{ CPUFUNC(op_e4f9_31), 58617 }, /* ROXRW */
{ CPUFUNC(op_e5d0_31), 58832 }, /* ROXLW */
{ CPUFUNC(op_e5d8_31), 58840 }, /* ROXLW */
{ CPUFUNC(op_e5e0_31), 58848 }, /* ROXLW */
{ CPUFUNC(op_e5e8_31), 58856 }, /* ROXLW */
{ CPUFUNC(op_e5f0_31), 58864 }, /* ROXLW */
{ CPUFUNC(op_e5f8_31), 58872 }, /* ROXLW */
{ CPUFUNC(op_e5f9_31), 58873 }, /* ROXLW */
{ CPUFUNC(op_e6d0_31), 59088 }, /* RORW */
{ CPUFUNC(op_e6d8_31), 59096 }, /* RORW */
{ CPUFUNC(op_e6e0_31), 59104 }, /* RORW */
{ CPUFUNC(op_e6e8_31), 59112 }, /* RORW */
{ CPUFUNC(op_e6f0_31), 59120 }, /* RORW */
{ CPUFUNC(op_e6f8_31), 59128 }, /* RORW */
{ CPUFUNC(op_e6f9_31), 59129 }, /* RORW */
{ CPUFUNC(op_e7d0_31), 59344 }, /* ROLW */
{ CPUFUNC(op_e7d8_31), 59352 }, /* ROLW */
{ CPUFUNC(op_e7e0_31), 59360 }, /* ROLW */
{ CPUFUNC(op_e7e8_31), 59368 }, /* ROLW */
{ CPUFUNC(op_e7f0_31), 59376 }, /* ROLW */
{ CPUFUNC(op_e7f8_31), 59384 }, /* ROLW */
{ CPUFUNC(op_e7f9_31), 59385 }, /* ROLW */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e8c0_31), 59584 }, /* BFTST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e8d0_31), 59600 }, /* BFTST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e8e8_31), 59624 }, /* BFTST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e8f0_31), 59632 }, /* BFTST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e8f8_31), 59640 }, /* BFTST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e8f9_31), 59641 }, /* BFTST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e8fa_31), 59642 }, /* BFTST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e8fb_31), 59643 }, /* BFTST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e9c0_31), 59840 }, /* BFEXTU */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e9d0_31), 59856 }, /* BFEXTU */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e9e8_31), 59880 }, /* BFEXTU */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e9f0_31), 59888 }, /* BFEXTU */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e9f8_31), 59896 }, /* BFEXTU */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e9f9_31), 59897 }, /* BFEXTU */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e9fa_31), 59898 }, /* BFEXTU */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e9fb_31), 59899 }, /* BFEXTU */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eac0_31), 60096 }, /* BFCHG */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ead0_31), 60112 }, /* BFCHG */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eae8_31), 60136 }, /* BFCHG */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eaf0_31), 60144 }, /* BFCHG */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eaf8_31), 60152 }, /* BFCHG */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eaf9_31), 60153 }, /* BFCHG */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ebc0_31), 60352 }, /* BFEXTS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ebd0_31), 60368 }, /* BFEXTS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ebe8_31), 60392 }, /* BFEXTS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ebf0_31), 60400 }, /* BFEXTS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ebf8_31), 60408 }, /* BFEXTS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ebf9_31), 60409 }, /* BFEXTS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ebfa_31), 60410 }, /* BFEXTS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ebfb_31), 60411 }, /* BFEXTS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ecc0_31), 60608 }, /* BFCLR */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ecd0_31), 60624 }, /* BFCLR */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ece8_31), 60648 }, /* BFCLR */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ecf0_31), 60656 }, /* BFCLR */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ecf8_31), 60664 }, /* BFCLR */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ecf9_31), 60665 }, /* BFCLR */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_edc0_31), 60864 }, /* BFFFO */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_edd0_31), 60880 }, /* BFFFO */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ede8_31), 60904 }, /* BFFFO */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_edf0_31), 60912 }, /* BFFFO */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_edf8_31), 60920 }, /* BFFFO */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_edf9_31), 60921 }, /* BFFFO */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_edfa_31), 60922 }, /* BFFFO */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_edfb_31), 60923 }, /* BFFFO */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eec0_31), 61120 }, /* BFSET */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eed0_31), 61136 }, /* BFSET */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eee8_31), 61160 }, /* BFSET */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eef0_31), 61168 }, /* BFSET */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eef8_31), 61176 }, /* BFSET */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eef9_31), 61177 }, /* BFSET */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_efc0_31), 61376 }, /* BFINS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_efd0_31), 61392 }, /* BFINS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_efe8_31), 61416 }, /* BFINS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eff0_31), 61424 }, /* BFINS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eff8_31), 61432 }, /* BFINS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eff9_31), 61433 }, /* BFINS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f000_31), 61440 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f008_31), 61448 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f010_31), 61456 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f018_31), 61464 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f020_31), 61472 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f028_31), 61480 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f030_31), 61488 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f038_31), 61496 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f039_31), 61497 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f200_31), 61952 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f208_31), 61960 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f210_31), 61968 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f218_31), 61976 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f220_31), 61984 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f228_31), 61992 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f230_31), 62000 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f238_31), 62008 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f239_31), 62009 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f23a_31), 62010 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f23b_31), 62011 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f23c_31), 62012 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f240_31), 62016 }, /* FScc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f248_31), 62024 }, /* FDBcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f250_31), 62032 }, /* FScc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f258_31), 62040 }, /* FScc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f260_31), 62048 }, /* FScc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f268_31), 62056 }, /* FScc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f270_31), 62064 }, /* FScc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f278_31), 62072 }, /* FScc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f279_31), 62073 }, /* FScc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f27a_31), 62074 }, /* FTRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f27b_31), 62075 }, /* FTRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f27c_31), 62076 }, /* FTRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f280_31), 62080 }, /* FBcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f2c0_31), 62144 }, /* FBcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f310_31), 62224 }, /* FSAVE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f320_31), 62240 }, /* FSAVE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f328_31), 62248 }, /* FSAVE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f330_31), 62256 }, /* FSAVE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f338_31), 62264 }, /* FSAVE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f339_31), 62265 }, /* FSAVE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f350_31), 62288 }, /* FRESTORE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f358_31), 62296 }, /* FRESTORE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f368_31), 62312 }, /* FRESTORE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f370_31), 62320 }, /* FRESTORE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f378_31), 62328 }, /* FRESTORE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f379_31), 62329 }, /* FRESTORE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f37a_31), 62330 }, /* FRESTORE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f37b_31), 62331 }, /* FRESTORE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f408_31), 62472 }, /* CINVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f410_31), 62480 }, /* CINVP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f418_31), 62488 }, /* CINVA */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f419_31), 62489 }, /* CINVA */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f41a_31), 62490 }, /* CINVA */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f41b_31), 62491 }, /* CINVA */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f41c_31), 62492 }, /* CINVA */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f41d_31), 62493 }, /* CINVA */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f41e_31), 62494 }, /* CINVA */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f41f_31), 62495 }, /* CINVA */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f428_31), 62504 }, /* CPUSHL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f430_31), 62512 }, /* CPUSHP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f438_31), 62520 }, /* CPUSHA */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f439_31), 62521 }, /* CPUSHA */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f43a_31), 62522 }, /* CPUSHA */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f43b_31), 62523 }, /* CPUSHA */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f43c_31), 62524 }, /* CPUSHA */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f43d_31), 62525 }, /* CPUSHA */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f43e_31), 62526 }, /* CPUSHA */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f43f_31), 62527 }, /* CPUSHA */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f500_31), 62720 }, /* PFLUSHN */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f508_31), 62728 }, /* PFLUSH */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f510_31), 62736 }, /* PFLUSHAN */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f518_31), 62744 }, /* PFLUSHA */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f548_31), 62792 }, /* PTESTW */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f568_31), 62824 }, /* PTESTR */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f600_31), 62976 }, /* MOVE16 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f608_31), 62984 }, /* MOVE16 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f610_31), 62992 }, /* MOVE16 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f618_31), 63000 }, /* MOVE16 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f620_31), 63008 }, /* MOVE16 */
#endif
{ 0, 0 }};
#endif /* CPUEMU_68000_ONLY */
#endif /* CPUEMU_31 */
#ifdef CPUEMU_32
#ifndef CPUEMU_68000_ONLY
const struct cputbl CPUFUNC(op_smalltbl_32)[] = {
{ CPUFUNC(op_0000_32), 0 }, /* OR */
{ CPUFUNC(op_0010_32), 16 }, /* OR */
{ CPUFUNC(op_0018_32), 24 }, /* OR */
{ CPUFUNC(op_0020_32), 32 }, /* OR */
{ CPUFUNC(op_0028_32), 40 }, /* OR */
{ CPUFUNC(op_0030_32), 48 }, /* OR */
{ CPUFUNC(op_0038_32), 56 }, /* OR */
{ CPUFUNC(op_0039_32), 57 }, /* OR */
{ CPUFUNC(op_003c_32), 60 }, /* ORSR */
{ CPUFUNC(op_0040_32), 64 }, /* OR */
{ CPUFUNC(op_0050_32), 80 }, /* OR */
{ CPUFUNC(op_0058_32), 88 }, /* OR */
{ CPUFUNC(op_0060_32), 96 }, /* OR */
{ CPUFUNC(op_0068_32), 104 }, /* OR */
{ CPUFUNC(op_0070_32), 112 }, /* OR */
{ CPUFUNC(op_0078_32), 120 }, /* OR */
{ CPUFUNC(op_0079_32), 121 }, /* OR */
{ CPUFUNC(op_007c_32), 124 }, /* ORSR */
{ CPUFUNC(op_0080_32), 128 }, /* OR */
{ CPUFUNC(op_0090_32), 144 }, /* OR */
{ CPUFUNC(op_0098_32), 152 }, /* OR */
{ CPUFUNC(op_00a0_32), 160 }, /* OR */
{ CPUFUNC(op_00a8_32), 168 }, /* OR */
{ CPUFUNC(op_00b0_32), 176 }, /* OR */
{ CPUFUNC(op_00b8_32), 184 }, /* OR */
{ CPUFUNC(op_00b9_32), 185 }, /* OR */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_00d0_32), 208 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_00e8_32), 232 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_00f0_32), 240 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_00f8_32), 248 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_00f9_32), 249 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_00fa_32), 250 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_00fb_32), 251 }, /* CHK2 */
#endif
{ CPUFUNC(op_0100_32), 256 }, /* BTST */
{ CPUFUNC(op_0108_32), 264 }, /* MVPMR */
{ CPUFUNC(op_0110_32), 272 }, /* BTST */
{ CPUFUNC(op_0118_32), 280 }, /* BTST */
{ CPUFUNC(op_0120_32), 288 }, /* BTST */
{ CPUFUNC(op_0128_32), 296 }, /* BTST */
{ CPUFUNC(op_0130_32), 304 }, /* BTST */
{ CPUFUNC(op_0138_32), 312 }, /* BTST */
{ CPUFUNC(op_0139_32), 313 }, /* BTST */
{ CPUFUNC(op_013a_32), 314 }, /* BTST */
{ CPUFUNC(op_013b_32), 315 }, /* BTST */
{ CPUFUNC(op_013c_32), 316 }, /* BTST */
{ CPUFUNC(op_0140_32), 320 }, /* BCHG */
{ CPUFUNC(op_0148_32), 328 }, /* MVPMR */
{ CPUFUNC(op_0150_32), 336 }, /* BCHG */
{ CPUFUNC(op_0158_32), 344 }, /* BCHG */
{ CPUFUNC(op_0160_32), 352 }, /* BCHG */
{ CPUFUNC(op_0168_32), 360 }, /* BCHG */
{ CPUFUNC(op_0170_32), 368 }, /* BCHG */
{ CPUFUNC(op_0178_32), 376 }, /* BCHG */
{ CPUFUNC(op_0179_32), 377 }, /* BCHG */
{ CPUFUNC(op_0180_32), 384 }, /* BCLR */
{ CPUFUNC(op_0188_32), 392 }, /* MVPRM */
{ CPUFUNC(op_0190_32), 400 }, /* BCLR */
{ CPUFUNC(op_0198_32), 408 }, /* BCLR */
{ CPUFUNC(op_01a0_32), 416 }, /* BCLR */
{ CPUFUNC(op_01a8_32), 424 }, /* BCLR */
{ CPUFUNC(op_01b0_32), 432 }, /* BCLR */
{ CPUFUNC(op_01b8_32), 440 }, /* BCLR */
{ CPUFUNC(op_01b9_32), 441 }, /* BCLR */
{ CPUFUNC(op_01c0_32), 448 }, /* BSET */
{ CPUFUNC(op_01c8_32), 456 }, /* MVPRM */
{ CPUFUNC(op_01d0_32), 464 }, /* BSET */
{ CPUFUNC(op_01d8_32), 472 }, /* BSET */
{ CPUFUNC(op_01e0_32), 480 }, /* BSET */
{ CPUFUNC(op_01e8_32), 488 }, /* BSET */
{ CPUFUNC(op_01f0_32), 496 }, /* BSET */
{ CPUFUNC(op_01f8_32), 504 }, /* BSET */
{ CPUFUNC(op_01f9_32), 505 }, /* BSET */
{ CPUFUNC(op_0200_32), 512 }, /* AND */
{ CPUFUNC(op_0210_32), 528 }, /* AND */
{ CPUFUNC(op_0218_32), 536 }, /* AND */
{ CPUFUNC(op_0220_32), 544 }, /* AND */
{ CPUFUNC(op_0228_32), 552 }, /* AND */
{ CPUFUNC(op_0230_32), 560 }, /* AND */
{ CPUFUNC(op_0238_32), 568 }, /* AND */
{ CPUFUNC(op_0239_32), 569 }, /* AND */
{ CPUFUNC(op_023c_32), 572 }, /* ANDSR */
{ CPUFUNC(op_0240_32), 576 }, /* AND */
{ CPUFUNC(op_0250_32), 592 }, /* AND */
{ CPUFUNC(op_0258_32), 600 }, /* AND */
{ CPUFUNC(op_0260_32), 608 }, /* AND */
{ CPUFUNC(op_0268_32), 616 }, /* AND */
{ CPUFUNC(op_0270_32), 624 }, /* AND */
{ CPUFUNC(op_0278_32), 632 }, /* AND */
{ CPUFUNC(op_0279_32), 633 }, /* AND */
{ CPUFUNC(op_027c_32), 636 }, /* ANDSR */
{ CPUFUNC(op_0280_32), 640 }, /* AND */
{ CPUFUNC(op_0290_32), 656 }, /* AND */
{ CPUFUNC(op_0298_32), 664 }, /* AND */
{ CPUFUNC(op_02a0_32), 672 }, /* AND */
{ CPUFUNC(op_02a8_32), 680 }, /* AND */
{ CPUFUNC(op_02b0_32), 688 }, /* AND */
{ CPUFUNC(op_02b8_32), 696 }, /* AND */
{ CPUFUNC(op_02b9_32), 697 }, /* AND */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_02d0_32), 720 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_02e8_32), 744 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_02f0_32), 752 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_02f8_32), 760 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_02f9_32), 761 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_02fa_32), 762 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_02fb_32), 763 }, /* CHK2 */
#endif
{ CPUFUNC(op_0400_32), 1024 }, /* SUB */
{ CPUFUNC(op_0410_32), 1040 }, /* SUB */
{ CPUFUNC(op_0418_32), 1048 }, /* SUB */
{ CPUFUNC(op_0420_32), 1056 }, /* SUB */
{ CPUFUNC(op_0428_32), 1064 }, /* SUB */
{ CPUFUNC(op_0430_32), 1072 }, /* SUB */
{ CPUFUNC(op_0438_32), 1080 }, /* SUB */
{ CPUFUNC(op_0439_32), 1081 }, /* SUB */
{ CPUFUNC(op_0440_32), 1088 }, /* SUB */
{ CPUFUNC(op_0450_32), 1104 }, /* SUB */
{ CPUFUNC(op_0458_32), 1112 }, /* SUB */
{ CPUFUNC(op_0460_32), 1120 }, /* SUB */
{ CPUFUNC(op_0468_32), 1128 }, /* SUB */
{ CPUFUNC(op_0470_32), 1136 }, /* SUB */
{ CPUFUNC(op_0478_32), 1144 }, /* SUB */
{ CPUFUNC(op_0479_32), 1145 }, /* SUB */
{ CPUFUNC(op_0480_32), 1152 }, /* SUB */
{ CPUFUNC(op_0490_32), 1168 }, /* SUB */
{ CPUFUNC(op_0498_32), 1176 }, /* SUB */
{ CPUFUNC(op_04a0_32), 1184 }, /* SUB */
{ CPUFUNC(op_04a8_32), 1192 }, /* SUB */
{ CPUFUNC(op_04b0_32), 1200 }, /* SUB */
{ CPUFUNC(op_04b8_32), 1208 }, /* SUB */
{ CPUFUNC(op_04b9_32), 1209 }, /* SUB */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_04d0_32), 1232 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_04e8_32), 1256 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_04f0_32), 1264 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_04f8_32), 1272 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_04f9_32), 1273 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_04fa_32), 1274 }, /* CHK2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_04fb_32), 1275 }, /* CHK2 */
#endif
{ CPUFUNC(op_0600_32), 1536 }, /* ADD */
{ CPUFUNC(op_0610_32), 1552 }, /* ADD */
{ CPUFUNC(op_0618_32), 1560 }, /* ADD */
{ CPUFUNC(op_0620_32), 1568 }, /* ADD */
{ CPUFUNC(op_0628_32), 1576 }, /* ADD */
{ CPUFUNC(op_0630_32), 1584 }, /* ADD */
{ CPUFUNC(op_0638_32), 1592 }, /* ADD */
{ CPUFUNC(op_0639_32), 1593 }, /* ADD */
{ CPUFUNC(op_0640_32), 1600 }, /* ADD */
{ CPUFUNC(op_0650_32), 1616 }, /* ADD */
{ CPUFUNC(op_0658_32), 1624 }, /* ADD */
{ CPUFUNC(op_0660_32), 1632 }, /* ADD */
{ CPUFUNC(op_0668_32), 1640 }, /* ADD */
{ CPUFUNC(op_0670_32), 1648 }, /* ADD */
{ CPUFUNC(op_0678_32), 1656 }, /* ADD */
{ CPUFUNC(op_0679_32), 1657 }, /* ADD */
{ CPUFUNC(op_0680_32), 1664 }, /* ADD */
{ CPUFUNC(op_0690_32), 1680 }, /* ADD */
{ CPUFUNC(op_0698_32), 1688 }, /* ADD */
{ CPUFUNC(op_06a0_32), 1696 }, /* ADD */
{ CPUFUNC(op_06a8_32), 1704 }, /* ADD */
{ CPUFUNC(op_06b0_32), 1712 }, /* ADD */
{ CPUFUNC(op_06b8_32), 1720 }, /* ADD */
{ CPUFUNC(op_06b9_32), 1721 }, /* ADD */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06c0_32), 1728 }, /* RTM */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06c8_32), 1736 }, /* RTM */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06d0_32), 1744 }, /* CALLM */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06e8_32), 1768 }, /* CALLM */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06f0_32), 1776 }, /* CALLM */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06f8_32), 1784 }, /* CALLM */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06f9_32), 1785 }, /* CALLM */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06fa_32), 1786 }, /* CALLM */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_06fb_32), 1787 }, /* CALLM */
#endif
{ CPUFUNC(op_0800_32), 2048 }, /* BTST */
{ CPUFUNC(op_0810_32), 2064 }, /* BTST */
{ CPUFUNC(op_0818_32), 2072 }, /* BTST */
{ CPUFUNC(op_0820_32), 2080 }, /* BTST */
{ CPUFUNC(op_0828_32), 2088 }, /* BTST */
{ CPUFUNC(op_0830_32), 2096 }, /* BTST */
{ CPUFUNC(op_0838_32), 2104 }, /* BTST */
{ CPUFUNC(op_0839_32), 2105 }, /* BTST */
{ CPUFUNC(op_083a_32), 2106 }, /* BTST */
{ CPUFUNC(op_083b_32), 2107 }, /* BTST */
{ CPUFUNC(op_0840_32), 2112 }, /* BCHG */
{ CPUFUNC(op_0850_32), 2128 }, /* BCHG */
{ CPUFUNC(op_0858_32), 2136 }, /* BCHG */
{ CPUFUNC(op_0860_32), 2144 }, /* BCHG */
{ CPUFUNC(op_0868_32), 2152 }, /* BCHG */
{ CPUFUNC(op_0870_32), 2160 }, /* BCHG */
{ CPUFUNC(op_0878_32), 2168 }, /* BCHG */
{ CPUFUNC(op_0879_32), 2169 }, /* BCHG */
{ CPUFUNC(op_0880_32), 2176 }, /* BCLR */
{ CPUFUNC(op_0890_32), 2192 }, /* BCLR */
{ CPUFUNC(op_0898_32), 2200 }, /* BCLR */
{ CPUFUNC(op_08a0_32), 2208 }, /* BCLR */
{ CPUFUNC(op_08a8_32), 2216 }, /* BCLR */
{ CPUFUNC(op_08b0_32), 2224 }, /* BCLR */
{ CPUFUNC(op_08b8_32), 2232 }, /* BCLR */
{ CPUFUNC(op_08b9_32), 2233 }, /* BCLR */
{ CPUFUNC(op_08c0_32), 2240 }, /* BSET */
{ CPUFUNC(op_08d0_32), 2256 }, /* BSET */
{ CPUFUNC(op_08d8_32), 2264 }, /* BSET */
{ CPUFUNC(op_08e0_32), 2272 }, /* BSET */
{ CPUFUNC(op_08e8_32), 2280 }, /* BSET */
{ CPUFUNC(op_08f0_32), 2288 }, /* BSET */
{ CPUFUNC(op_08f8_32), 2296 }, /* BSET */
{ CPUFUNC(op_08f9_32), 2297 }, /* BSET */
{ CPUFUNC(op_0a00_32), 2560 }, /* EOR */
{ CPUFUNC(op_0a10_32), 2576 }, /* EOR */
{ CPUFUNC(op_0a18_32), 2584 }, /* EOR */
{ CPUFUNC(op_0a20_32), 2592 }, /* EOR */
{ CPUFUNC(op_0a28_32), 2600 }, /* EOR */
{ CPUFUNC(op_0a30_32), 2608 }, /* EOR */
{ CPUFUNC(op_0a38_32), 2616 }, /* EOR */
{ CPUFUNC(op_0a39_32), 2617 }, /* EOR */
{ CPUFUNC(op_0a3c_32), 2620 }, /* EORSR */
{ CPUFUNC(op_0a40_32), 2624 }, /* EOR */
{ CPUFUNC(op_0a50_32), 2640 }, /* EOR */
{ CPUFUNC(op_0a58_32), 2648 }, /* EOR */
{ CPUFUNC(op_0a60_32), 2656 }, /* EOR */
{ CPUFUNC(op_0a68_32), 2664 }, /* EOR */
{ CPUFUNC(op_0a70_32), 2672 }, /* EOR */
{ CPUFUNC(op_0a78_32), 2680 }, /* EOR */
{ CPUFUNC(op_0a79_32), 2681 }, /* EOR */
{ CPUFUNC(op_0a7c_32), 2684 }, /* EORSR */
{ CPUFUNC(op_0a80_32), 2688 }, /* EOR */
{ CPUFUNC(op_0a90_32), 2704 }, /* EOR */
{ CPUFUNC(op_0a98_32), 2712 }, /* EOR */
{ CPUFUNC(op_0aa0_32), 2720 }, /* EOR */
{ CPUFUNC(op_0aa8_32), 2728 }, /* EOR */
{ CPUFUNC(op_0ab0_32), 2736 }, /* EOR */
{ CPUFUNC(op_0ab8_32), 2744 }, /* EOR */
{ CPUFUNC(op_0ab9_32), 2745 }, /* EOR */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ad0_32), 2768 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ad8_32), 2776 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ae0_32), 2784 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ae8_32), 2792 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0af0_32), 2800 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0af8_32), 2808 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0af9_32), 2809 }, /* CAS */
#endif
{ CPUFUNC(op_0c00_32), 3072 }, /* CMP */
{ CPUFUNC(op_0c10_32), 3088 }, /* CMP */
{ CPUFUNC(op_0c18_32), 3096 }, /* CMP */
{ CPUFUNC(op_0c20_32), 3104 }, /* CMP */
{ CPUFUNC(op_0c28_32), 3112 }, /* CMP */
{ CPUFUNC(op_0c30_32), 3120 }, /* CMP */
{ CPUFUNC(op_0c38_32), 3128 }, /* CMP */
{ CPUFUNC(op_0c39_32), 3129 }, /* CMP */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0c3a_32), 3130 }, /* CMP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0c3b_32), 3131 }, /* CMP */
#endif
{ CPUFUNC(op_0c40_32), 3136 }, /* CMP */
{ CPUFUNC(op_0c50_32), 3152 }, /* CMP */
{ CPUFUNC(op_0c58_32), 3160 }, /* CMP */
{ CPUFUNC(op_0c60_32), 3168 }, /* CMP */
{ CPUFUNC(op_0c68_32), 3176 }, /* CMP */
{ CPUFUNC(op_0c70_32), 3184 }, /* CMP */
{ CPUFUNC(op_0c78_32), 3192 }, /* CMP */
{ CPUFUNC(op_0c79_32), 3193 }, /* CMP */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0c7a_32), 3194 }, /* CMP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0c7b_32), 3195 }, /* CMP */
#endif
{ CPUFUNC(op_0c80_32), 3200 }, /* CMP */
{ CPUFUNC(op_0c90_32), 3216 }, /* CMP */
{ CPUFUNC(op_0c98_32), 3224 }, /* CMP */
{ CPUFUNC(op_0ca0_32), 3232 }, /* CMP */
{ CPUFUNC(op_0ca8_32), 3240 }, /* CMP */
{ CPUFUNC(op_0cb0_32), 3248 }, /* CMP */
{ CPUFUNC(op_0cb8_32), 3256 }, /* CMP */
{ CPUFUNC(op_0cb9_32), 3257 }, /* CMP */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0cba_32), 3258 }, /* CMP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0cbb_32), 3259 }, /* CMP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0cd0_32), 3280 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0cd8_32), 3288 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ce0_32), 3296 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ce8_32), 3304 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0cf0_32), 3312 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0cf8_32), 3320 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0cf9_32), 3321 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0cfc_32), 3324 }, /* CAS2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e10_32), 3600 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e18_32), 3608 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e20_32), 3616 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e28_32), 3624 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e30_32), 3632 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e38_32), 3640 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e39_32), 3641 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e50_32), 3664 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e58_32), 3672 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e60_32), 3680 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e68_32), 3688 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e70_32), 3696 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e78_32), 3704 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e79_32), 3705 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e90_32), 3728 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0e98_32), 3736 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ea0_32), 3744 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ea8_32), 3752 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0eb0_32), 3760 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0eb8_32), 3768 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0eb9_32), 3769 }, /* MOVES */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ed0_32), 3792 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ed8_32), 3800 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ee0_32), 3808 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ee8_32), 3816 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ef0_32), 3824 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ef8_32), 3832 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0ef9_32), 3833 }, /* CAS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_0efc_32), 3836 }, /* CAS2 */
#endif
{ CPUFUNC(op_1000_32), 4096 }, /* MOVE */
{ CPUFUNC(op_1010_32), 4112 }, /* MOVE */
{ CPUFUNC(op_1018_32), 4120 }, /* MOVE */
{ CPUFUNC(op_1020_32), 4128 }, /* MOVE */
{ CPUFUNC(op_1028_32), 4136 }, /* MOVE */
{ CPUFUNC(op_1030_32), 4144 }, /* MOVE */
{ CPUFUNC(op_1038_32), 4152 }, /* MOVE */
{ CPUFUNC(op_1039_32), 4153 }, /* MOVE */
{ CPUFUNC(op_103a_32), 4154 }, /* MOVE */
{ CPUFUNC(op_103b_32), 4155 }, /* MOVE */
{ CPUFUNC(op_103c_32), 4156 }, /* MOVE */
{ CPUFUNC(op_1080_32), 4224 }, /* MOVE */
{ CPUFUNC(op_1090_32), 4240 }, /* MOVE */
{ CPUFUNC(op_1098_32), 4248 }, /* MOVE */
{ CPUFUNC(op_10a0_32), 4256 }, /* MOVE */
{ CPUFUNC(op_10a8_32), 4264 }, /* MOVE */
{ CPUFUNC(op_10b0_32), 4272 }, /* MOVE */
{ CPUFUNC(op_10b8_32), 4280 }, /* MOVE */
{ CPUFUNC(op_10b9_32), 4281 }, /* MOVE */
{ CPUFUNC(op_10ba_32), 4282 }, /* MOVE */
{ CPUFUNC(op_10bb_32), 4283 }, /* MOVE */
{ CPUFUNC(op_10bc_32), 4284 }, /* MOVE */
{ CPUFUNC(op_10c0_32), 4288 }, /* MOVE */
{ CPUFUNC(op_10d0_32), 4304 }, /* MOVE */
{ CPUFUNC(op_10d8_32), 4312 }, /* MOVE */
{ CPUFUNC(op_10e0_32), 4320 }, /* MOVE */
{ CPUFUNC(op_10e8_32), 4328 }, /* MOVE */
{ CPUFUNC(op_10f0_32), 4336 }, /* MOVE */
{ CPUFUNC(op_10f8_32), 4344 }, /* MOVE */
{ CPUFUNC(op_10f9_32), 4345 }, /* MOVE */
{ CPUFUNC(op_10fa_32), 4346 }, /* MOVE */
{ CPUFUNC(op_10fb_32), 4347 }, /* MOVE */
{ CPUFUNC(op_10fc_32), 4348 }, /* MOVE */
{ CPUFUNC(op_1100_32), 4352 }, /* MOVE */
{ CPUFUNC(op_1110_32), 4368 }, /* MOVE */
{ CPUFUNC(op_1118_32), 4376 }, /* MOVE */
{ CPUFUNC(op_1120_32), 4384 }, /* MOVE */
{ CPUFUNC(op_1128_32), 4392 }, /* MOVE */
{ CPUFUNC(op_1130_32), 4400 }, /* MOVE */
{ CPUFUNC(op_1138_32), 4408 }, /* MOVE */
{ CPUFUNC(op_1139_32), 4409 }, /* MOVE */
{ CPUFUNC(op_113a_32), 4410 }, /* MOVE */
{ CPUFUNC(op_113b_32), 4411 }, /* MOVE */
{ CPUFUNC(op_113c_32), 4412 }, /* MOVE */
{ CPUFUNC(op_1140_32), 4416 }, /* MOVE */
{ CPUFUNC(op_1150_32), 4432 }, /* MOVE */
{ CPUFUNC(op_1158_32), 4440 }, /* MOVE */
{ CPUFUNC(op_1160_32), 4448 }, /* MOVE */
{ CPUFUNC(op_1168_32), 4456 }, /* MOVE */
{ CPUFUNC(op_1170_32), 4464 }, /* MOVE */
{ CPUFUNC(op_1178_32), 4472 }, /* MOVE */
{ CPUFUNC(op_1179_32), 4473 }, /* MOVE */
{ CPUFUNC(op_117a_32), 4474 }, /* MOVE */
{ CPUFUNC(op_117b_32), 4475 }, /* MOVE */
{ CPUFUNC(op_117c_32), 4476 }, /* MOVE */
{ CPUFUNC(op_1180_32), 4480 }, /* MOVE */
{ CPUFUNC(op_1190_32), 4496 }, /* MOVE */
{ CPUFUNC(op_1198_32), 4504 }, /* MOVE */
{ CPUFUNC(op_11a0_32), 4512 }, /* MOVE */
{ CPUFUNC(op_11a8_32), 4520 }, /* MOVE */
{ CPUFUNC(op_11b0_32), 4528 }, /* MOVE */
{ CPUFUNC(op_11b8_32), 4536 }, /* MOVE */
{ CPUFUNC(op_11b9_32), 4537 }, /* MOVE */
{ CPUFUNC(op_11ba_32), 4538 }, /* MOVE */
{ CPUFUNC(op_11bb_32), 4539 }, /* MOVE */
{ CPUFUNC(op_11bc_32), 4540 }, /* MOVE */
{ CPUFUNC(op_11c0_32), 4544 }, /* MOVE */
{ CPUFUNC(op_11d0_32), 4560 }, /* MOVE */
{ CPUFUNC(op_11d8_32), 4568 }, /* MOVE */
{ CPUFUNC(op_11e0_32), 4576 }, /* MOVE */
{ CPUFUNC(op_11e8_32), 4584 }, /* MOVE */
{ CPUFUNC(op_11f0_32), 4592 }, /* MOVE */
{ CPUFUNC(op_11f8_32), 4600 }, /* MOVE */
{ CPUFUNC(op_11f9_32), 4601 }, /* MOVE */
{ CPUFUNC(op_11fa_32), 4602 }, /* MOVE */
{ CPUFUNC(op_11fb_32), 4603 }, /* MOVE */
{ CPUFUNC(op_11fc_32), 4604 }, /* MOVE */
{ CPUFUNC(op_13c0_32), 5056 }, /* MOVE */
{ CPUFUNC(op_13d0_32), 5072 }, /* MOVE */
{ CPUFUNC(op_13d8_32), 5080 }, /* MOVE */
{ CPUFUNC(op_13e0_32), 5088 }, /* MOVE */
{ CPUFUNC(op_13e8_32), 5096 }, /* MOVE */
{ CPUFUNC(op_13f0_32), 5104 }, /* MOVE */
{ CPUFUNC(op_13f8_32), 5112 }, /* MOVE */
{ CPUFUNC(op_13f9_32), 5113 }, /* MOVE */
{ CPUFUNC(op_13fa_32), 5114 }, /* MOVE */
{ CPUFUNC(op_13fb_32), 5115 }, /* MOVE */
{ CPUFUNC(op_13fc_32), 5116 }, /* MOVE */
{ CPUFUNC(op_2000_32), 8192 }, /* MOVE */
{ CPUFUNC(op_2008_32), 8200 }, /* MOVE */
{ CPUFUNC(op_2010_32), 8208 }, /* MOVE */
{ CPUFUNC(op_2018_32), 8216 }, /* MOVE */
{ CPUFUNC(op_2020_32), 8224 }, /* MOVE */
{ CPUFUNC(op_2028_32), 8232 }, /* MOVE */
{ CPUFUNC(op_2030_32), 8240 }, /* MOVE */
{ CPUFUNC(op_2038_32), 8248 }, /* MOVE */
{ CPUFUNC(op_2039_32), 8249 }, /* MOVE */
{ CPUFUNC(op_203a_32), 8250 }, /* MOVE */
{ CPUFUNC(op_203b_32), 8251 }, /* MOVE */
{ CPUFUNC(op_203c_32), 8252 }, /* MOVE */
{ CPUFUNC(op_2040_32), 8256 }, /* MOVEA */
{ CPUFUNC(op_2048_32), 8264 }, /* MOVEA */
{ CPUFUNC(op_2050_32), 8272 }, /* MOVEA */
{ CPUFUNC(op_2058_32), 8280 }, /* MOVEA */
{ CPUFUNC(op_2060_32), 8288 }, /* MOVEA */
{ CPUFUNC(op_2068_32), 8296 }, /* MOVEA */
{ CPUFUNC(op_2070_32), 8304 }, /* MOVEA */
{ CPUFUNC(op_2078_32), 8312 }, /* MOVEA */
{ CPUFUNC(op_2079_32), 8313 }, /* MOVEA */
{ CPUFUNC(op_207a_32), 8314 }, /* MOVEA */
{ CPUFUNC(op_207b_32), 8315 }, /* MOVEA */
{ CPUFUNC(op_207c_32), 8316 }, /* MOVEA */
{ CPUFUNC(op_2080_32), 8320 }, /* MOVE */
{ CPUFUNC(op_2088_32), 8328 }, /* MOVE */
{ CPUFUNC(op_2090_32), 8336 }, /* MOVE */
{ CPUFUNC(op_2098_32), 8344 }, /* MOVE */
{ CPUFUNC(op_20a0_32), 8352 }, /* MOVE */
{ CPUFUNC(op_20a8_32), 8360 }, /* MOVE */
{ CPUFUNC(op_20b0_32), 8368 }, /* MOVE */
{ CPUFUNC(op_20b8_32), 8376 }, /* MOVE */
{ CPUFUNC(op_20b9_32), 8377 }, /* MOVE */
{ CPUFUNC(op_20ba_32), 8378 }, /* MOVE */
{ CPUFUNC(op_20bb_32), 8379 }, /* MOVE */
{ CPUFUNC(op_20bc_32), 8380 }, /* MOVE */
{ CPUFUNC(op_20c0_32), 8384 }, /* MOVE */
{ CPUFUNC(op_20c8_32), 8392 }, /* MOVE */
{ CPUFUNC(op_20d0_32), 8400 }, /* MOVE */
{ CPUFUNC(op_20d8_32), 8408 }, /* MOVE */
{ CPUFUNC(op_20e0_32), 8416 }, /* MOVE */
{ CPUFUNC(op_20e8_32), 8424 }, /* MOVE */
{ CPUFUNC(op_20f0_32), 8432 }, /* MOVE */
{ CPUFUNC(op_20f8_32), 8440 }, /* MOVE */
{ CPUFUNC(op_20f9_32), 8441 }, /* MOVE */
{ CPUFUNC(op_20fa_32), 8442 }, /* MOVE */
{ CPUFUNC(op_20fb_32), 8443 }, /* MOVE */
{ CPUFUNC(op_20fc_32), 8444 }, /* MOVE */
{ CPUFUNC(op_2100_32), 8448 }, /* MOVE */
{ CPUFUNC(op_2108_32), 8456 }, /* MOVE */
{ CPUFUNC(op_2110_32), 8464 }, /* MOVE */
{ CPUFUNC(op_2118_32), 8472 }, /* MOVE */
{ CPUFUNC(op_2120_32), 8480 }, /* MOVE */
{ CPUFUNC(op_2128_32), 8488 }, /* MOVE */
{ CPUFUNC(op_2130_32), 8496 }, /* MOVE */
{ CPUFUNC(op_2138_32), 8504 }, /* MOVE */
{ CPUFUNC(op_2139_32), 8505 }, /* MOVE */
{ CPUFUNC(op_213a_32), 8506 }, /* MOVE */
{ CPUFUNC(op_213b_32), 8507 }, /* MOVE */
{ CPUFUNC(op_213c_32), 8508 }, /* MOVE */
{ CPUFUNC(op_2140_32), 8512 }, /* MOVE */
{ CPUFUNC(op_2148_32), 8520 }, /* MOVE */
{ CPUFUNC(op_2150_32), 8528 }, /* MOVE */
{ CPUFUNC(op_2158_32), 8536 }, /* MOVE */
{ CPUFUNC(op_2160_32), 8544 }, /* MOVE */
{ CPUFUNC(op_2168_32), 8552 }, /* MOVE */
{ CPUFUNC(op_2170_32), 8560 }, /* MOVE */
{ CPUFUNC(op_2178_32), 8568 }, /* MOVE */
{ CPUFUNC(op_2179_32), 8569 }, /* MOVE */
{ CPUFUNC(op_217a_32), 8570 }, /* MOVE */
{ CPUFUNC(op_217b_32), 8571 }, /* MOVE */
{ CPUFUNC(op_217c_32), 8572 }, /* MOVE */
{ CPUFUNC(op_2180_32), 8576 }, /* MOVE */
{ CPUFUNC(op_2188_32), 8584 }, /* MOVE */
{ CPUFUNC(op_2190_32), 8592 }, /* MOVE */
{ CPUFUNC(op_2198_32), 8600 }, /* MOVE */
{ CPUFUNC(op_21a0_32), 8608 }, /* MOVE */
{ CPUFUNC(op_21a8_32), 8616 }, /* MOVE */
{ CPUFUNC(op_21b0_32), 8624 }, /* MOVE */
{ CPUFUNC(op_21b8_32), 8632 }, /* MOVE */
{ CPUFUNC(op_21b9_32), 8633 }, /* MOVE */
{ CPUFUNC(op_21ba_32), 8634 }, /* MOVE */
{ CPUFUNC(op_21bb_32), 8635 }, /* MOVE */
{ CPUFUNC(op_21bc_32), 8636 }, /* MOVE */
{ CPUFUNC(op_21c0_32), 8640 }, /* MOVE */
{ CPUFUNC(op_21c8_32), 8648 }, /* MOVE */
{ CPUFUNC(op_21d0_32), 8656 }, /* MOVE */
{ CPUFUNC(op_21d8_32), 8664 }, /* MOVE */
{ CPUFUNC(op_21e0_32), 8672 }, /* MOVE */
{ CPUFUNC(op_21e8_32), 8680 }, /* MOVE */
{ CPUFUNC(op_21f0_32), 8688 }, /* MOVE */
{ CPUFUNC(op_21f8_32), 8696 }, /* MOVE */
{ CPUFUNC(op_21f9_32), 8697 }, /* MOVE */
{ CPUFUNC(op_21fa_32), 8698 }, /* MOVE */
{ CPUFUNC(op_21fb_32), 8699 }, /* MOVE */
{ CPUFUNC(op_21fc_32), 8700 }, /* MOVE */
{ CPUFUNC(op_23c0_32), 9152 }, /* MOVE */
{ CPUFUNC(op_23c8_32), 9160 }, /* MOVE */
{ CPUFUNC(op_23d0_32), 9168 }, /* MOVE */
{ CPUFUNC(op_23d8_32), 9176 }, /* MOVE */
{ CPUFUNC(op_23e0_32), 9184 }, /* MOVE */
{ CPUFUNC(op_23e8_32), 9192 }, /* MOVE */
{ CPUFUNC(op_23f0_32), 9200 }, /* MOVE */
{ CPUFUNC(op_23f8_32), 9208 }, /* MOVE */
{ CPUFUNC(op_23f9_32), 9209 }, /* MOVE */
{ CPUFUNC(op_23fa_32), 9210 }, /* MOVE */
{ CPUFUNC(op_23fb_32), 9211 }, /* MOVE */
{ CPUFUNC(op_23fc_32), 9212 }, /* MOVE */
{ CPUFUNC(op_3000_32), 12288 }, /* MOVE */
{ CPUFUNC(op_3008_32), 12296 }, /* MOVE */
{ CPUFUNC(op_3010_32), 12304 }, /* MOVE */
{ CPUFUNC(op_3018_32), 12312 }, /* MOVE */
{ CPUFUNC(op_3020_32), 12320 }, /* MOVE */
{ CPUFUNC(op_3028_32), 12328 }, /* MOVE */
{ CPUFUNC(op_3030_32), 12336 }, /* MOVE */
{ CPUFUNC(op_3038_32), 12344 }, /* MOVE */
{ CPUFUNC(op_3039_32), 12345 }, /* MOVE */
{ CPUFUNC(op_303a_32), 12346 }, /* MOVE */
{ CPUFUNC(op_303b_32), 12347 }, /* MOVE */
{ CPUFUNC(op_303c_32), 12348 }, /* MOVE */
{ CPUFUNC(op_3040_32), 12352 }, /* MOVEA */
{ CPUFUNC(op_3048_32), 12360 }, /* MOVEA */
{ CPUFUNC(op_3050_32), 12368 }, /* MOVEA */
{ CPUFUNC(op_3058_32), 12376 }, /* MOVEA */
{ CPUFUNC(op_3060_32), 12384 }, /* MOVEA */
{ CPUFUNC(op_3068_32), 12392 }, /* MOVEA */
{ CPUFUNC(op_3070_32), 12400 }, /* MOVEA */
{ CPUFUNC(op_3078_32), 12408 }, /* MOVEA */
{ CPUFUNC(op_3079_32), 12409 }, /* MOVEA */
{ CPUFUNC(op_307a_32), 12410 }, /* MOVEA */
{ CPUFUNC(op_307b_32), 12411 }, /* MOVEA */
{ CPUFUNC(op_307c_32), 12412 }, /* MOVEA */
{ CPUFUNC(op_3080_32), 12416 }, /* MOVE */
{ CPUFUNC(op_3088_32), 12424 }, /* MOVE */
{ CPUFUNC(op_3090_32), 12432 }, /* MOVE */
{ CPUFUNC(op_3098_32), 12440 }, /* MOVE */
{ CPUFUNC(op_30a0_32), 12448 }, /* MOVE */
{ CPUFUNC(op_30a8_32), 12456 }, /* MOVE */
{ CPUFUNC(op_30b0_32), 12464 }, /* MOVE */
{ CPUFUNC(op_30b8_32), 12472 }, /* MOVE */
{ CPUFUNC(op_30b9_32), 12473 }, /* MOVE */
{ CPUFUNC(op_30ba_32), 12474 }, /* MOVE */
{ CPUFUNC(op_30bb_32), 12475 }, /* MOVE */
{ CPUFUNC(op_30bc_32), 12476 }, /* MOVE */
{ CPUFUNC(op_30c0_32), 12480 }, /* MOVE */
{ CPUFUNC(op_30c8_32), 12488 }, /* MOVE */
{ CPUFUNC(op_30d0_32), 12496 }, /* MOVE */
{ CPUFUNC(op_30d8_32), 12504 }, /* MOVE */
{ CPUFUNC(op_30e0_32), 12512 }, /* MOVE */
{ CPUFUNC(op_30e8_32), 12520 }, /* MOVE */
{ CPUFUNC(op_30f0_32), 12528 }, /* MOVE */
{ CPUFUNC(op_30f8_32), 12536 }, /* MOVE */
{ CPUFUNC(op_30f9_32), 12537 }, /* MOVE */
{ CPUFUNC(op_30fa_32), 12538 }, /* MOVE */
{ CPUFUNC(op_30fb_32), 12539 }, /* MOVE */
{ CPUFUNC(op_30fc_32), 12540 }, /* MOVE */
{ CPUFUNC(op_3100_32), 12544 }, /* MOVE */
{ CPUFUNC(op_3108_32), 12552 }, /* MOVE */
{ CPUFUNC(op_3110_32), 12560 }, /* MOVE */
{ CPUFUNC(op_3118_32), 12568 }, /* MOVE */
{ CPUFUNC(op_3120_32), 12576 }, /* MOVE */
{ CPUFUNC(op_3128_32), 12584 }, /* MOVE */
{ CPUFUNC(op_3130_32), 12592 }, /* MOVE */
{ CPUFUNC(op_3138_32), 12600 }, /* MOVE */
{ CPUFUNC(op_3139_32), 12601 }, /* MOVE */
{ CPUFUNC(op_313a_32), 12602 }, /* MOVE */
{ CPUFUNC(op_313b_32), 12603 }, /* MOVE */
{ CPUFUNC(op_313c_32), 12604 }, /* MOVE */
{ CPUFUNC(op_3140_32), 12608 }, /* MOVE */
{ CPUFUNC(op_3148_32), 12616 }, /* MOVE */
{ CPUFUNC(op_3150_32), 12624 }, /* MOVE */
{ CPUFUNC(op_3158_32), 12632 }, /* MOVE */
{ CPUFUNC(op_3160_32), 12640 }, /* MOVE */
{ CPUFUNC(op_3168_32), 12648 }, /* MOVE */
{ CPUFUNC(op_3170_32), 12656 }, /* MOVE */
{ CPUFUNC(op_3178_32), 12664 }, /* MOVE */
{ CPUFUNC(op_3179_32), 12665 }, /* MOVE */
{ CPUFUNC(op_317a_32), 12666 }, /* MOVE */
{ CPUFUNC(op_317b_32), 12667 }, /* MOVE */
{ CPUFUNC(op_317c_32), 12668 }, /* MOVE */
{ CPUFUNC(op_3180_32), 12672 }, /* MOVE */
{ CPUFUNC(op_3188_32), 12680 }, /* MOVE */
{ CPUFUNC(op_3190_32), 12688 }, /* MOVE */
{ CPUFUNC(op_3198_32), 12696 }, /* MOVE */
{ CPUFUNC(op_31a0_32), 12704 }, /* MOVE */
{ CPUFUNC(op_31a8_32), 12712 }, /* MOVE */
{ CPUFUNC(op_31b0_32), 12720 }, /* MOVE */
{ CPUFUNC(op_31b8_32), 12728 }, /* MOVE */
{ CPUFUNC(op_31b9_32), 12729 }, /* MOVE */
{ CPUFUNC(op_31ba_32), 12730 }, /* MOVE */
{ CPUFUNC(op_31bb_32), 12731 }, /* MOVE */
{ CPUFUNC(op_31bc_32), 12732 }, /* MOVE */
{ CPUFUNC(op_31c0_32), 12736 }, /* MOVE */
{ CPUFUNC(op_31c8_32), 12744 }, /* MOVE */
{ CPUFUNC(op_31d0_32), 12752 }, /* MOVE */
{ CPUFUNC(op_31d8_32), 12760 }, /* MOVE */
{ CPUFUNC(op_31e0_32), 12768 }, /* MOVE */
{ CPUFUNC(op_31e8_32), 12776 }, /* MOVE */
{ CPUFUNC(op_31f0_32), 12784 }, /* MOVE */
{ CPUFUNC(op_31f8_32), 12792 }, /* MOVE */
{ CPUFUNC(op_31f9_32), 12793 }, /* MOVE */
{ CPUFUNC(op_31fa_32), 12794 }, /* MOVE */
{ CPUFUNC(op_31fb_32), 12795 }, /* MOVE */
{ CPUFUNC(op_31fc_32), 12796 }, /* MOVE */
{ CPUFUNC(op_33c0_32), 13248 }, /* MOVE */
{ CPUFUNC(op_33c8_32), 13256 }, /* MOVE */
{ CPUFUNC(op_33d0_32), 13264 }, /* MOVE */
{ CPUFUNC(op_33d8_32), 13272 }, /* MOVE */
{ CPUFUNC(op_33e0_32), 13280 }, /* MOVE */
{ CPUFUNC(op_33e8_32), 13288 }, /* MOVE */
{ CPUFUNC(op_33f0_32), 13296 }, /* MOVE */
{ CPUFUNC(op_33f8_32), 13304 }, /* MOVE */
{ CPUFUNC(op_33f9_32), 13305 }, /* MOVE */
{ CPUFUNC(op_33fa_32), 13306 }, /* MOVE */
{ CPUFUNC(op_33fb_32), 13307 }, /* MOVE */
{ CPUFUNC(op_33fc_32), 13308 }, /* MOVE */
{ CPUFUNC(op_4000_32), 16384 }, /* NEGX */
{ CPUFUNC(op_4010_32), 16400 }, /* NEGX */
{ CPUFUNC(op_4018_32), 16408 }, /* NEGX */
{ CPUFUNC(op_4020_32), 16416 }, /* NEGX */
{ CPUFUNC(op_4028_32), 16424 }, /* NEGX */
{ CPUFUNC(op_4030_32), 16432 }, /* NEGX */
{ CPUFUNC(op_4038_32), 16440 }, /* NEGX */
{ CPUFUNC(op_4039_32), 16441 }, /* NEGX */
{ CPUFUNC(op_4040_32), 16448 }, /* NEGX */
{ CPUFUNC(op_4050_32), 16464 }, /* NEGX */
{ CPUFUNC(op_4058_32), 16472 }, /* NEGX */
{ CPUFUNC(op_4060_32), 16480 }, /* NEGX */
{ CPUFUNC(op_4068_32), 16488 }, /* NEGX */
{ CPUFUNC(op_4070_32), 16496 }, /* NEGX */
{ CPUFUNC(op_4078_32), 16504 }, /* NEGX */
{ CPUFUNC(op_4079_32), 16505 }, /* NEGX */
{ CPUFUNC(op_4080_32), 16512 }, /* NEGX */
{ CPUFUNC(op_4090_32), 16528 }, /* NEGX */
{ CPUFUNC(op_4098_32), 16536 }, /* NEGX */
{ CPUFUNC(op_40a0_32), 16544 }, /* NEGX */
{ CPUFUNC(op_40a8_32), 16552 }, /* NEGX */
{ CPUFUNC(op_40b0_32), 16560 }, /* NEGX */
{ CPUFUNC(op_40b8_32), 16568 }, /* NEGX */
{ CPUFUNC(op_40b9_32), 16569 }, /* NEGX */
{ CPUFUNC(op_40c0_32), 16576 }, /* MVSR2 */
{ CPUFUNC(op_40d0_32), 16592 }, /* MVSR2 */
{ CPUFUNC(op_40d8_32), 16600 }, /* MVSR2 */
{ CPUFUNC(op_40e0_32), 16608 }, /* MVSR2 */
{ CPUFUNC(op_40e8_32), 16616 }, /* MVSR2 */
{ CPUFUNC(op_40f0_32), 16624 }, /* MVSR2 */
{ CPUFUNC(op_40f8_32), 16632 }, /* MVSR2 */
{ CPUFUNC(op_40f9_32), 16633 }, /* MVSR2 */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4100_32), 16640 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4110_32), 16656 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4118_32), 16664 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4120_32), 16672 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4128_32), 16680 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4130_32), 16688 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4138_32), 16696 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4139_32), 16697 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_413a_32), 16698 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_413b_32), 16699 }, /* CHK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_413c_32), 16700 }, /* CHK */
#endif
{ CPUFUNC(op_4180_32), 16768 }, /* CHK */
{ CPUFUNC(op_4190_32), 16784 }, /* CHK */
{ CPUFUNC(op_4198_32), 16792 }, /* CHK */
{ CPUFUNC(op_41a0_32), 16800 }, /* CHK */
{ CPUFUNC(op_41a8_32), 16808 }, /* CHK */
{ CPUFUNC(op_41b0_32), 16816 }, /* CHK */
{ CPUFUNC(op_41b8_32), 16824 }, /* CHK */
{ CPUFUNC(op_41b9_32), 16825 }, /* CHK */
{ CPUFUNC(op_41ba_32), 16826 }, /* CHK */
{ CPUFUNC(op_41bb_32), 16827 }, /* CHK */
{ CPUFUNC(op_41bc_32), 16828 }, /* CHK */
{ CPUFUNC(op_41d0_32), 16848 }, /* LEA */
{ CPUFUNC(op_41e8_32), 16872 }, /* LEA */
{ CPUFUNC(op_41f0_32), 16880 }, /* LEA */
{ CPUFUNC(op_41f8_32), 16888 }, /* LEA */
{ CPUFUNC(op_41f9_32), 16889 }, /* LEA */
{ CPUFUNC(op_41fa_32), 16890 }, /* LEA */
{ CPUFUNC(op_41fb_32), 16891 }, /* LEA */
{ CPUFUNC(op_4200_32), 16896 }, /* CLR */
{ CPUFUNC(op_4210_32), 16912 }, /* CLR */
{ CPUFUNC(op_4218_32), 16920 }, /* CLR */
{ CPUFUNC(op_4220_32), 16928 }, /* CLR */
{ CPUFUNC(op_4228_32), 16936 }, /* CLR */
{ CPUFUNC(op_4230_32), 16944 }, /* CLR */
{ CPUFUNC(op_4238_32), 16952 }, /* CLR */
{ CPUFUNC(op_4239_32), 16953 }, /* CLR */
{ CPUFUNC(op_4240_32), 16960 }, /* CLR */
{ CPUFUNC(op_4250_32), 16976 }, /* CLR */
{ CPUFUNC(op_4258_32), 16984 }, /* CLR */
{ CPUFUNC(op_4260_32), 16992 }, /* CLR */
{ CPUFUNC(op_4268_32), 17000 }, /* CLR */
{ CPUFUNC(op_4270_32), 17008 }, /* CLR */
{ CPUFUNC(op_4278_32), 17016 }, /* CLR */
{ CPUFUNC(op_4279_32), 17017 }, /* CLR */
{ CPUFUNC(op_4280_32), 17024 }, /* CLR */
{ CPUFUNC(op_4290_32), 17040 }, /* CLR */
{ CPUFUNC(op_4298_32), 17048 }, /* CLR */
{ CPUFUNC(op_42a0_32), 17056 }, /* CLR */
{ CPUFUNC(op_42a8_32), 17064 }, /* CLR */
{ CPUFUNC(op_42b0_32), 17072 }, /* CLR */
{ CPUFUNC(op_42b8_32), 17080 }, /* CLR */
{ CPUFUNC(op_42b9_32), 17081 }, /* CLR */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_42c0_32), 17088 }, /* MVSR2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_42d0_32), 17104 }, /* MVSR2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_42d8_32), 17112 }, /* MVSR2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_42e0_32), 17120 }, /* MVSR2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_42e8_32), 17128 }, /* MVSR2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_42f0_32), 17136 }, /* MVSR2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_42f8_32), 17144 }, /* MVSR2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_42f9_32), 17145 }, /* MVSR2 */
#endif
{ CPUFUNC(op_4400_32), 17408 }, /* NEG */
{ CPUFUNC(op_4410_32), 17424 }, /* NEG */
{ CPUFUNC(op_4418_32), 17432 }, /* NEG */
{ CPUFUNC(op_4420_32), 17440 }, /* NEG */
{ CPUFUNC(op_4428_32), 17448 }, /* NEG */
{ CPUFUNC(op_4430_32), 17456 }, /* NEG */
{ CPUFUNC(op_4438_32), 17464 }, /* NEG */
{ CPUFUNC(op_4439_32), 17465 }, /* NEG */
{ CPUFUNC(op_4440_32), 17472 }, /* NEG */
{ CPUFUNC(op_4450_32), 17488 }, /* NEG */
{ CPUFUNC(op_4458_32), 17496 }, /* NEG */
{ CPUFUNC(op_4460_32), 17504 }, /* NEG */
{ CPUFUNC(op_4468_32), 17512 }, /* NEG */
{ CPUFUNC(op_4470_32), 17520 }, /* NEG */
{ CPUFUNC(op_4478_32), 17528 }, /* NEG */
{ CPUFUNC(op_4479_32), 17529 }, /* NEG */
{ CPUFUNC(op_4480_32), 17536 }, /* NEG */
{ CPUFUNC(op_4490_32), 17552 }, /* NEG */
{ CPUFUNC(op_4498_32), 17560 }, /* NEG */
{ CPUFUNC(op_44a0_32), 17568 }, /* NEG */
{ CPUFUNC(op_44a8_32), 17576 }, /* NEG */
{ CPUFUNC(op_44b0_32), 17584 }, /* NEG */
{ CPUFUNC(op_44b8_32), 17592 }, /* NEG */
{ CPUFUNC(op_44b9_32), 17593 }, /* NEG */
{ CPUFUNC(op_44c0_32), 17600 }, /* MV2SR */
{ CPUFUNC(op_44d0_32), 17616 }, /* MV2SR */
{ CPUFUNC(op_44d8_32), 17624 }, /* MV2SR */
{ CPUFUNC(op_44e0_32), 17632 }, /* MV2SR */
{ CPUFUNC(op_44e8_32), 17640 }, /* MV2SR */
{ CPUFUNC(op_44f0_32), 17648 }, /* MV2SR */
{ CPUFUNC(op_44f8_32), 17656 }, /* MV2SR */
{ CPUFUNC(op_44f9_32), 17657 }, /* MV2SR */
{ CPUFUNC(op_44fa_32), 17658 }, /* MV2SR */
{ CPUFUNC(op_44fb_32), 17659 }, /* MV2SR */
{ CPUFUNC(op_44fc_32), 17660 }, /* MV2SR */
{ CPUFUNC(op_4600_32), 17920 }, /* NOT */
{ CPUFUNC(op_4610_32), 17936 }, /* NOT */
{ CPUFUNC(op_4618_32), 17944 }, /* NOT */
{ CPUFUNC(op_4620_32), 17952 }, /* NOT */
{ CPUFUNC(op_4628_32), 17960 }, /* NOT */
{ CPUFUNC(op_4630_32), 17968 }, /* NOT */
{ CPUFUNC(op_4638_32), 17976 }, /* NOT */
{ CPUFUNC(op_4639_32), 17977 }, /* NOT */
{ CPUFUNC(op_4640_32), 17984 }, /* NOT */
{ CPUFUNC(op_4650_32), 18000 }, /* NOT */
{ CPUFUNC(op_4658_32), 18008 }, /* NOT */
{ CPUFUNC(op_4660_32), 18016 }, /* NOT */
{ CPUFUNC(op_4668_32), 18024 }, /* NOT */
{ CPUFUNC(op_4670_32), 18032 }, /* NOT */
{ CPUFUNC(op_4678_32), 18040 }, /* NOT */
{ CPUFUNC(op_4679_32), 18041 }, /* NOT */
{ CPUFUNC(op_4680_32), 18048 }, /* NOT */
{ CPUFUNC(op_4690_32), 18064 }, /* NOT */
{ CPUFUNC(op_4698_32), 18072 }, /* NOT */
{ CPUFUNC(op_46a0_32), 18080 }, /* NOT */
{ CPUFUNC(op_46a8_32), 18088 }, /* NOT */
{ CPUFUNC(op_46b0_32), 18096 }, /* NOT */
{ CPUFUNC(op_46b8_32), 18104 }, /* NOT */
{ CPUFUNC(op_46b9_32), 18105 }, /* NOT */
{ CPUFUNC(op_46c0_32), 18112 }, /* MV2SR */
{ CPUFUNC(op_46d0_32), 18128 }, /* MV2SR */
{ CPUFUNC(op_46d8_32), 18136 }, /* MV2SR */
{ CPUFUNC(op_46e0_32), 18144 }, /* MV2SR */
{ CPUFUNC(op_46e8_32), 18152 }, /* MV2SR */
{ CPUFUNC(op_46f0_32), 18160 }, /* MV2SR */
{ CPUFUNC(op_46f8_32), 18168 }, /* MV2SR */
{ CPUFUNC(op_46f9_32), 18169 }, /* MV2SR */
{ CPUFUNC(op_46fa_32), 18170 }, /* MV2SR */
{ CPUFUNC(op_46fb_32), 18171 }, /* MV2SR */
{ CPUFUNC(op_46fc_32), 18172 }, /* MV2SR */
{ CPUFUNC(op_4800_32), 18432 }, /* NBCD */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4808_32), 18440 }, /* LINK */
#endif
{ CPUFUNC(op_4810_32), 18448 }, /* NBCD */
{ CPUFUNC(op_4818_32), 18456 }, /* NBCD */
{ CPUFUNC(op_4820_32), 18464 }, /* NBCD */
{ CPUFUNC(op_4828_32), 18472 }, /* NBCD */
{ CPUFUNC(op_4830_32), 18480 }, /* NBCD */
{ CPUFUNC(op_4838_32), 18488 }, /* NBCD */
{ CPUFUNC(op_4839_32), 18489 }, /* NBCD */
{ CPUFUNC(op_4840_32), 18496 }, /* SWAP */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4848_32), 18504 }, /* BKPT */
#endif
{ CPUFUNC(op_4850_32), 18512 }, /* PEA */
{ CPUFUNC(op_4868_32), 18536 }, /* PEA */
{ CPUFUNC(op_4870_32), 18544 }, /* PEA */
{ CPUFUNC(op_4878_32), 18552 }, /* PEA */
{ CPUFUNC(op_4879_32), 18553 }, /* PEA */
{ CPUFUNC(op_487a_32), 18554 }, /* PEA */
{ CPUFUNC(op_487b_32), 18555 }, /* PEA */
{ CPUFUNC(op_4880_32), 18560 }, /* EXT */
{ CPUFUNC(op_4890_32), 18576 }, /* MVMLE */
{ CPUFUNC(op_48a0_32), 18592 }, /* MVMLE */
{ CPUFUNC(op_48a8_32), 18600 }, /* MVMLE */
{ CPUFUNC(op_48b0_32), 18608 }, /* MVMLE */
{ CPUFUNC(op_48b8_32), 18616 }, /* MVMLE */
{ CPUFUNC(op_48b9_32), 18617 }, /* MVMLE */
{ CPUFUNC(op_48c0_32), 18624 }, /* EXT */
{ CPUFUNC(op_48d0_32), 18640 }, /* MVMLE */
{ CPUFUNC(op_48e0_32), 18656 }, /* MVMLE */
{ CPUFUNC(op_48e8_32), 18664 }, /* MVMLE */
{ CPUFUNC(op_48f0_32), 18672 }, /* MVMLE */
{ CPUFUNC(op_48f8_32), 18680 }, /* MVMLE */
{ CPUFUNC(op_48f9_32), 18681 }, /* MVMLE */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_49c0_32), 18880 }, /* EXT */
#endif
{ CPUFUNC(op_4a00_32), 18944 }, /* TST */
{ CPUFUNC(op_4a10_32), 18960 }, /* TST */
{ CPUFUNC(op_4a18_32), 18968 }, /* TST */
{ CPUFUNC(op_4a20_32), 18976 }, /* TST */
{ CPUFUNC(op_4a28_32), 18984 }, /* TST */
{ CPUFUNC(op_4a30_32), 18992 }, /* TST */
{ CPUFUNC(op_4a38_32), 19000 }, /* TST */
{ CPUFUNC(op_4a39_32), 19001 }, /* TST */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4a3a_32), 19002 }, /* TST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4a3b_32), 19003 }, /* TST */
#endif
{ CPUFUNC(op_4a40_32), 19008 }, /* TST */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4a48_32), 19016 }, /* TST */
#endif
{ CPUFUNC(op_4a50_32), 19024 }, /* TST */
{ CPUFUNC(op_4a58_32), 19032 }, /* TST */
{ CPUFUNC(op_4a60_32), 19040 }, /* TST */
{ CPUFUNC(op_4a68_32), 19048 }, /* TST */
{ CPUFUNC(op_4a70_32), 19056 }, /* TST */
{ CPUFUNC(op_4a78_32), 19064 }, /* TST */
{ CPUFUNC(op_4a79_32), 19065 }, /* TST */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4a7a_32), 19066 }, /* TST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4a7b_32), 19067 }, /* TST */
#endif
{ CPUFUNC(op_4a80_32), 19072 }, /* TST */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4a88_32), 19080 }, /* TST */
#endif
{ CPUFUNC(op_4a90_32), 19088 }, /* TST */
{ CPUFUNC(op_4a98_32), 19096 }, /* TST */
{ CPUFUNC(op_4aa0_32), 19104 }, /* TST */
{ CPUFUNC(op_4aa8_32), 19112 }, /* TST */
{ CPUFUNC(op_4ab0_32), 19120 }, /* TST */
{ CPUFUNC(op_4ab8_32), 19128 }, /* TST */
{ CPUFUNC(op_4ab9_32), 19129 }, /* TST */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4aba_32), 19130 }, /* TST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4abb_32), 19131 }, /* TST */
#endif
{ CPUFUNC(op_4ac0_32), 19136 }, /* TAS */
{ CPUFUNC(op_4ad0_32), 19152 }, /* TAS */
{ CPUFUNC(op_4ad8_32), 19160 }, /* TAS */
{ CPUFUNC(op_4ae0_32), 19168 }, /* TAS */
{ CPUFUNC(op_4ae8_32), 19176 }, /* TAS */
{ CPUFUNC(op_4af0_32), 19184 }, /* TAS */
{ CPUFUNC(op_4af8_32), 19192 }, /* TAS */
{ CPUFUNC(op_4af9_32), 19193 }, /* TAS */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c00_32), 19456 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c10_32), 19472 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c18_32), 19480 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c20_32), 19488 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c28_32), 19496 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c30_32), 19504 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c38_32), 19512 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c39_32), 19513 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c3a_32), 19514 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c3b_32), 19515 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c3c_32), 19516 }, /* MULL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c40_32), 19520 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c50_32), 19536 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c58_32), 19544 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c60_32), 19552 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c68_32), 19560 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c70_32), 19568 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c78_32), 19576 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c79_32), 19577 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c7a_32), 19578 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c7b_32), 19579 }, /* DIVL */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4c7c_32), 19580 }, /* DIVL */
#endif
{ CPUFUNC(op_4c90_32), 19600 }, /* MVMEL */
{ CPUFUNC(op_4c98_32), 19608 }, /* MVMEL */
{ CPUFUNC(op_4ca8_32), 19624 }, /* MVMEL */
{ CPUFUNC(op_4cb0_32), 19632 }, /* MVMEL */
{ CPUFUNC(op_4cb8_32), 19640 }, /* MVMEL */
{ CPUFUNC(op_4cb9_32), 19641 }, /* MVMEL */
{ CPUFUNC(op_4cba_32), 19642 }, /* MVMEL */
{ CPUFUNC(op_4cbb_32), 19643 }, /* MVMEL */
{ CPUFUNC(op_4cd0_32), 19664 }, /* MVMEL */
{ CPUFUNC(op_4cd8_32), 19672 }, /* MVMEL */
{ CPUFUNC(op_4ce8_32), 19688 }, /* MVMEL */
{ CPUFUNC(op_4cf0_32), 19696 }, /* MVMEL */
{ CPUFUNC(op_4cf8_32), 19704 }, /* MVMEL */
{ CPUFUNC(op_4cf9_32), 19705 }, /* MVMEL */
{ CPUFUNC(op_4cfa_32), 19706 }, /* MVMEL */
{ CPUFUNC(op_4cfb_32), 19707 }, /* MVMEL */
{ CPUFUNC(op_4e40_32), 20032 }, /* TRAP */
{ CPUFUNC(op_4e50_32), 20048 }, /* LINK */
{ CPUFUNC(op_4e58_32), 20056 }, /* UNLK */
{ CPUFUNC(op_4e60_32), 20064 }, /* MVR2USP */
{ CPUFUNC(op_4e68_32), 20072 }, /* MVUSP2R */
{ CPUFUNC(op_4e70_32), 20080 }, /* RESET */
{ CPUFUNC(op_4e71_32), 20081 }, /* NOP */
{ CPUFUNC(op_4e72_32), 20082 }, /* STOP */
{ CPUFUNC(op_4e73_32), 20083 }, /* RTE */
{ CPUFUNC(op_4e74_32), 20084 }, /* RTD */
{ CPUFUNC(op_4e75_32), 20085 }, /* RTS */
{ CPUFUNC(op_4e76_32), 20086 }, /* TRAPV */
{ CPUFUNC(op_4e77_32), 20087 }, /* RTR */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4e7a_32), 20090 }, /* MOVEC2 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_4e7b_32), 20091 }, /* MOVE2C */
#endif
{ CPUFUNC(op_4e90_32), 20112 }, /* JSR */
{ CPUFUNC(op_4ea8_32), 20136 }, /* JSR */
{ CPUFUNC(op_4eb0_32), 20144 }, /* JSR */
{ CPUFUNC(op_4eb8_32), 20152 }, /* JSR */
{ CPUFUNC(op_4eb9_32), 20153 }, /* JSR */
{ CPUFUNC(op_4eba_32), 20154 }, /* JSR */
{ CPUFUNC(op_4ebb_32), 20155 }, /* JSR */
{ CPUFUNC(op_4ed0_32), 20176 }, /* JMP */
{ CPUFUNC(op_4ee8_32), 20200 }, /* JMP */
{ CPUFUNC(op_4ef0_32), 20208 }, /* JMP */
{ CPUFUNC(op_4ef8_32), 20216 }, /* JMP */
{ CPUFUNC(op_4ef9_32), 20217 }, /* JMP */
{ CPUFUNC(op_4efa_32), 20218 }, /* JMP */
{ CPUFUNC(op_4efb_32), 20219 }, /* JMP */
{ CPUFUNC(op_5000_32), 20480 }, /* ADD */
{ CPUFUNC(op_5010_32), 20496 }, /* ADD */
{ CPUFUNC(op_5018_32), 20504 }, /* ADD */
{ CPUFUNC(op_5020_32), 20512 }, /* ADD */
{ CPUFUNC(op_5028_32), 20520 }, /* ADD */
{ CPUFUNC(op_5030_32), 20528 }, /* ADD */
{ CPUFUNC(op_5038_32), 20536 }, /* ADD */
{ CPUFUNC(op_5039_32), 20537 }, /* ADD */
{ CPUFUNC(op_5040_32), 20544 }, /* ADD */
{ CPUFUNC(op_5048_32), 20552 }, /* ADDA */
{ CPUFUNC(op_5050_32), 20560 }, /* ADD */
{ CPUFUNC(op_5058_32), 20568 }, /* ADD */
{ CPUFUNC(op_5060_32), 20576 }, /* ADD */
{ CPUFUNC(op_5068_32), 20584 }, /* ADD */
{ CPUFUNC(op_5070_32), 20592 }, /* ADD */
{ CPUFUNC(op_5078_32), 20600 }, /* ADD */
{ CPUFUNC(op_5079_32), 20601 }, /* ADD */
{ CPUFUNC(op_5080_32), 20608 }, /* ADD */
{ CPUFUNC(op_5088_32), 20616 }, /* ADDA */
{ CPUFUNC(op_5090_32), 20624 }, /* ADD */
{ CPUFUNC(op_5098_32), 20632 }, /* ADD */
{ CPUFUNC(op_50a0_32), 20640 }, /* ADD */
{ CPUFUNC(op_50a8_32), 20648 }, /* ADD */
{ CPUFUNC(op_50b0_32), 20656 }, /* ADD */
{ CPUFUNC(op_50b8_32), 20664 }, /* ADD */
{ CPUFUNC(op_50b9_32), 20665 }, /* ADD */
{ CPUFUNC(op_50c0_32), 20672 }, /* Scc */
{ CPUFUNC(op_50c8_32), 20680 }, /* DBcc */
{ CPUFUNC(op_50d0_32), 20688 }, /* Scc */
{ CPUFUNC(op_50d8_32), 20696 }, /* Scc */
{ CPUFUNC(op_50e0_32), 20704 }, /* Scc */
{ CPUFUNC(op_50e8_32), 20712 }, /* Scc */
{ CPUFUNC(op_50f0_32), 20720 }, /* Scc */
{ CPUFUNC(op_50f8_32), 20728 }, /* Scc */
{ CPUFUNC(op_50f9_32), 20729 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_50fa_32), 20730 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_50fb_32), 20731 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_50fc_32), 20732 }, /* TRAPcc */
#endif
{ CPUFUNC(op_5100_32), 20736 }, /* SUB */
{ CPUFUNC(op_5110_32), 20752 }, /* SUB */
{ CPUFUNC(op_5118_32), 20760 }, /* SUB */
{ CPUFUNC(op_5120_32), 20768 }, /* SUB */
{ CPUFUNC(op_5128_32), 20776 }, /* SUB */
{ CPUFUNC(op_5130_32), 20784 }, /* SUB */
{ CPUFUNC(op_5138_32), 20792 }, /* SUB */
{ CPUFUNC(op_5139_32), 20793 }, /* SUB */
{ CPUFUNC(op_5140_32), 20800 }, /* SUB */
{ CPUFUNC(op_5148_32), 20808 }, /* SUBA */
{ CPUFUNC(op_5150_32), 20816 }, /* SUB */
{ CPUFUNC(op_5158_32), 20824 }, /* SUB */
{ CPUFUNC(op_5160_32), 20832 }, /* SUB */
{ CPUFUNC(op_5168_32), 20840 }, /* SUB */
{ CPUFUNC(op_5170_32), 20848 }, /* SUB */
{ CPUFUNC(op_5178_32), 20856 }, /* SUB */
{ CPUFUNC(op_5179_32), 20857 }, /* SUB */
{ CPUFUNC(op_5180_32), 20864 }, /* SUB */
{ CPUFUNC(op_5188_32), 20872 }, /* SUBA */
{ CPUFUNC(op_5190_32), 20880 }, /* SUB */
{ CPUFUNC(op_5198_32), 20888 }, /* SUB */
{ CPUFUNC(op_51a0_32), 20896 }, /* SUB */
{ CPUFUNC(op_51a8_32), 20904 }, /* SUB */
{ CPUFUNC(op_51b0_32), 20912 }, /* SUB */
{ CPUFUNC(op_51b8_32), 20920 }, /* SUB */
{ CPUFUNC(op_51b9_32), 20921 }, /* SUB */
{ CPUFUNC(op_51c0_32), 20928 }, /* Scc */
{ CPUFUNC(op_51c8_32), 20936 }, /* DBcc */
{ CPUFUNC(op_51d0_32), 20944 }, /* Scc */
{ CPUFUNC(op_51d8_32), 20952 }, /* Scc */
{ CPUFUNC(op_51e0_32), 20960 }, /* Scc */
{ CPUFUNC(op_51e8_32), 20968 }, /* Scc */
{ CPUFUNC(op_51f0_32), 20976 }, /* Scc */
{ CPUFUNC(op_51f8_32), 20984 }, /* Scc */
{ CPUFUNC(op_51f9_32), 20985 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_51fa_32), 20986 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_51fb_32), 20987 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_51fc_32), 20988 }, /* TRAPcc */
#endif
{ CPUFUNC(op_52c0_32), 21184 }, /* Scc */
{ CPUFUNC(op_52c8_32), 21192 }, /* DBcc */
{ CPUFUNC(op_52d0_32), 21200 }, /* Scc */
{ CPUFUNC(op_52d8_32), 21208 }, /* Scc */
{ CPUFUNC(op_52e0_32), 21216 }, /* Scc */
{ CPUFUNC(op_52e8_32), 21224 }, /* Scc */
{ CPUFUNC(op_52f0_32), 21232 }, /* Scc */
{ CPUFUNC(op_52f8_32), 21240 }, /* Scc */
{ CPUFUNC(op_52f9_32), 21241 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_52fa_32), 21242 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_52fb_32), 21243 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_52fc_32), 21244 }, /* TRAPcc */
#endif
{ CPUFUNC(op_53c0_32), 21440 }, /* Scc */
{ CPUFUNC(op_53c8_32), 21448 }, /* DBcc */
{ CPUFUNC(op_53d0_32), 21456 }, /* Scc */
{ CPUFUNC(op_53d8_32), 21464 }, /* Scc */
{ CPUFUNC(op_53e0_32), 21472 }, /* Scc */
{ CPUFUNC(op_53e8_32), 21480 }, /* Scc */
{ CPUFUNC(op_53f0_32), 21488 }, /* Scc */
{ CPUFUNC(op_53f8_32), 21496 }, /* Scc */
{ CPUFUNC(op_53f9_32), 21497 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_53fa_32), 21498 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_53fb_32), 21499 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_53fc_32), 21500 }, /* TRAPcc */
#endif
{ CPUFUNC(op_54c0_32), 21696 }, /* Scc */
{ CPUFUNC(op_54c8_32), 21704 }, /* DBcc */
{ CPUFUNC(op_54d0_32), 21712 }, /* Scc */
{ CPUFUNC(op_54d8_32), 21720 }, /* Scc */
{ CPUFUNC(op_54e0_32), 21728 }, /* Scc */
{ CPUFUNC(op_54e8_32), 21736 }, /* Scc */
{ CPUFUNC(op_54f0_32), 21744 }, /* Scc */
{ CPUFUNC(op_54f8_32), 21752 }, /* Scc */
{ CPUFUNC(op_54f9_32), 21753 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_54fa_32), 21754 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_54fb_32), 21755 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_54fc_32), 21756 }, /* TRAPcc */
#endif
{ CPUFUNC(op_55c0_32), 21952 }, /* Scc */
{ CPUFUNC(op_55c8_32), 21960 }, /* DBcc */
{ CPUFUNC(op_55d0_32), 21968 }, /* Scc */
{ CPUFUNC(op_55d8_32), 21976 }, /* Scc */
{ CPUFUNC(op_55e0_32), 21984 }, /* Scc */
{ CPUFUNC(op_55e8_32), 21992 }, /* Scc */
{ CPUFUNC(op_55f0_32), 22000 }, /* Scc */
{ CPUFUNC(op_55f8_32), 22008 }, /* Scc */
{ CPUFUNC(op_55f9_32), 22009 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_55fa_32), 22010 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_55fb_32), 22011 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_55fc_32), 22012 }, /* TRAPcc */
#endif
{ CPUFUNC(op_56c0_32), 22208 }, /* Scc */
{ CPUFUNC(op_56c8_32), 22216 }, /* DBcc */
{ CPUFUNC(op_56d0_32), 22224 }, /* Scc */
{ CPUFUNC(op_56d8_32), 22232 }, /* Scc */
{ CPUFUNC(op_56e0_32), 22240 }, /* Scc */
{ CPUFUNC(op_56e8_32), 22248 }, /* Scc */
{ CPUFUNC(op_56f0_32), 22256 }, /* Scc */
{ CPUFUNC(op_56f8_32), 22264 }, /* Scc */
{ CPUFUNC(op_56f9_32), 22265 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_56fa_32), 22266 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_56fb_32), 22267 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_56fc_32), 22268 }, /* TRAPcc */
#endif
{ CPUFUNC(op_57c0_32), 22464 }, /* Scc */
{ CPUFUNC(op_57c8_32), 22472 }, /* DBcc */
{ CPUFUNC(op_57d0_32), 22480 }, /* Scc */
{ CPUFUNC(op_57d8_32), 22488 }, /* Scc */
{ CPUFUNC(op_57e0_32), 22496 }, /* Scc */
{ CPUFUNC(op_57e8_32), 22504 }, /* Scc */
{ CPUFUNC(op_57f0_32), 22512 }, /* Scc */
{ CPUFUNC(op_57f8_32), 22520 }, /* Scc */
{ CPUFUNC(op_57f9_32), 22521 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_57fa_32), 22522 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_57fb_32), 22523 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_57fc_32), 22524 }, /* TRAPcc */
#endif
{ CPUFUNC(op_58c0_32), 22720 }, /* Scc */
{ CPUFUNC(op_58c8_32), 22728 }, /* DBcc */
{ CPUFUNC(op_58d0_32), 22736 }, /* Scc */
{ CPUFUNC(op_58d8_32), 22744 }, /* Scc */
{ CPUFUNC(op_58e0_32), 22752 }, /* Scc */
{ CPUFUNC(op_58e8_32), 22760 }, /* Scc */
{ CPUFUNC(op_58f0_32), 22768 }, /* Scc */
{ CPUFUNC(op_58f8_32), 22776 }, /* Scc */
{ CPUFUNC(op_58f9_32), 22777 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_58fa_32), 22778 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_58fb_32), 22779 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_58fc_32), 22780 }, /* TRAPcc */
#endif
{ CPUFUNC(op_59c0_32), 22976 }, /* Scc */
{ CPUFUNC(op_59c8_32), 22984 }, /* DBcc */
{ CPUFUNC(op_59d0_32), 22992 }, /* Scc */
{ CPUFUNC(op_59d8_32), 23000 }, /* Scc */
{ CPUFUNC(op_59e0_32), 23008 }, /* Scc */
{ CPUFUNC(op_59e8_32), 23016 }, /* Scc */
{ CPUFUNC(op_59f0_32), 23024 }, /* Scc */
{ CPUFUNC(op_59f8_32), 23032 }, /* Scc */
{ CPUFUNC(op_59f9_32), 23033 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_59fa_32), 23034 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_59fb_32), 23035 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_59fc_32), 23036 }, /* TRAPcc */
#endif
{ CPUFUNC(op_5ac0_32), 23232 }, /* Scc */
{ CPUFUNC(op_5ac8_32), 23240 }, /* DBcc */
{ CPUFUNC(op_5ad0_32), 23248 }, /* Scc */
{ CPUFUNC(op_5ad8_32), 23256 }, /* Scc */
{ CPUFUNC(op_5ae0_32), 23264 }, /* Scc */
{ CPUFUNC(op_5ae8_32), 23272 }, /* Scc */
{ CPUFUNC(op_5af0_32), 23280 }, /* Scc */
{ CPUFUNC(op_5af8_32), 23288 }, /* Scc */
{ CPUFUNC(op_5af9_32), 23289 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5afa_32), 23290 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5afb_32), 23291 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5afc_32), 23292 }, /* TRAPcc */
#endif
{ CPUFUNC(op_5bc0_32), 23488 }, /* Scc */
{ CPUFUNC(op_5bc8_32), 23496 }, /* DBcc */
{ CPUFUNC(op_5bd0_32), 23504 }, /* Scc */
{ CPUFUNC(op_5bd8_32), 23512 }, /* Scc */
{ CPUFUNC(op_5be0_32), 23520 }, /* Scc */
{ CPUFUNC(op_5be8_32), 23528 }, /* Scc */
{ CPUFUNC(op_5bf0_32), 23536 }, /* Scc */
{ CPUFUNC(op_5bf8_32), 23544 }, /* Scc */
{ CPUFUNC(op_5bf9_32), 23545 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5bfa_32), 23546 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5bfb_32), 23547 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5bfc_32), 23548 }, /* TRAPcc */
#endif
{ CPUFUNC(op_5cc0_32), 23744 }, /* Scc */
{ CPUFUNC(op_5cc8_32), 23752 }, /* DBcc */
{ CPUFUNC(op_5cd0_32), 23760 }, /* Scc */
{ CPUFUNC(op_5cd8_32), 23768 }, /* Scc */
{ CPUFUNC(op_5ce0_32), 23776 }, /* Scc */
{ CPUFUNC(op_5ce8_32), 23784 }, /* Scc */
{ CPUFUNC(op_5cf0_32), 23792 }, /* Scc */
{ CPUFUNC(op_5cf8_32), 23800 }, /* Scc */
{ CPUFUNC(op_5cf9_32), 23801 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5cfa_32), 23802 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5cfb_32), 23803 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5cfc_32), 23804 }, /* TRAPcc */
#endif
{ CPUFUNC(op_5dc0_32), 24000 }, /* Scc */
{ CPUFUNC(op_5dc8_32), 24008 }, /* DBcc */
{ CPUFUNC(op_5dd0_32), 24016 }, /* Scc */
{ CPUFUNC(op_5dd8_32), 24024 }, /* Scc */
{ CPUFUNC(op_5de0_32), 24032 }, /* Scc */
{ CPUFUNC(op_5de8_32), 24040 }, /* Scc */
{ CPUFUNC(op_5df0_32), 24048 }, /* Scc */
{ CPUFUNC(op_5df8_32), 24056 }, /* Scc */
{ CPUFUNC(op_5df9_32), 24057 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5dfa_32), 24058 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5dfb_32), 24059 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5dfc_32), 24060 }, /* TRAPcc */
#endif
{ CPUFUNC(op_5ec0_32), 24256 }, /* Scc */
{ CPUFUNC(op_5ec8_32), 24264 }, /* DBcc */
{ CPUFUNC(op_5ed0_32), 24272 }, /* Scc */
{ CPUFUNC(op_5ed8_32), 24280 }, /* Scc */
{ CPUFUNC(op_5ee0_32), 24288 }, /* Scc */
{ CPUFUNC(op_5ee8_32), 24296 }, /* Scc */
{ CPUFUNC(op_5ef0_32), 24304 }, /* Scc */
{ CPUFUNC(op_5ef8_32), 24312 }, /* Scc */
{ CPUFUNC(op_5ef9_32), 24313 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5efa_32), 24314 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5efb_32), 24315 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5efc_32), 24316 }, /* TRAPcc */
#endif
{ CPUFUNC(op_5fc0_32), 24512 }, /* Scc */
{ CPUFUNC(op_5fc8_32), 24520 }, /* DBcc */
{ CPUFUNC(op_5fd0_32), 24528 }, /* Scc */
{ CPUFUNC(op_5fd8_32), 24536 }, /* Scc */
{ CPUFUNC(op_5fe0_32), 24544 }, /* Scc */
{ CPUFUNC(op_5fe8_32), 24552 }, /* Scc */
{ CPUFUNC(op_5ff0_32), 24560 }, /* Scc */
{ CPUFUNC(op_5ff8_32), 24568 }, /* Scc */
{ CPUFUNC(op_5ff9_32), 24569 }, /* Scc */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5ffa_32), 24570 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5ffb_32), 24571 }, /* TRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_5ffc_32), 24572 }, /* TRAPcc */
#endif
{ CPUFUNC(op_6000_32), 24576 }, /* Bcc */
{ CPUFUNC(op_6001_32), 24577 }, /* Bcc */
{ CPUFUNC(op_60ff_32), 24831 }, /* Bcc */
{ CPUFUNC(op_6100_32), 24832 }, /* BSR */
{ CPUFUNC(op_6101_32), 24833 }, /* BSR */
{ CPUFUNC(op_61ff_32), 25087 }, /* BSR */
{ CPUFUNC(op_6200_32), 25088 }, /* Bcc */
{ CPUFUNC(op_6201_32), 25089 }, /* Bcc */
{ CPUFUNC(op_62ff_32), 25343 }, /* Bcc */
{ CPUFUNC(op_6300_32), 25344 }, /* Bcc */
{ CPUFUNC(op_6301_32), 25345 }, /* Bcc */
{ CPUFUNC(op_63ff_32), 25599 }, /* Bcc */
{ CPUFUNC(op_6400_32), 25600 }, /* Bcc */
{ CPUFUNC(op_6401_32), 25601 }, /* Bcc */
{ CPUFUNC(op_64ff_32), 25855 }, /* Bcc */
{ CPUFUNC(op_6500_32), 25856 }, /* Bcc */
{ CPUFUNC(op_6501_32), 25857 }, /* Bcc */
{ CPUFUNC(op_65ff_32), 26111 }, /* Bcc */
{ CPUFUNC(op_6600_32), 26112 }, /* Bcc */
{ CPUFUNC(op_6601_32), 26113 }, /* Bcc */
{ CPUFUNC(op_66ff_32), 26367 }, /* Bcc */
{ CPUFUNC(op_6700_32), 26368 }, /* Bcc */
{ CPUFUNC(op_6701_32), 26369 }, /* Bcc */
{ CPUFUNC(op_67ff_32), 26623 }, /* Bcc */
{ CPUFUNC(op_6800_32), 26624 }, /* Bcc */
{ CPUFUNC(op_6801_32), 26625 }, /* Bcc */
{ CPUFUNC(op_68ff_32), 26879 }, /* Bcc */
{ CPUFUNC(op_6900_32), 26880 }, /* Bcc */
{ CPUFUNC(op_6901_32), 26881 }, /* Bcc */
{ CPUFUNC(op_69ff_32), 27135 }, /* Bcc */
{ CPUFUNC(op_6a00_32), 27136 }, /* Bcc */
{ CPUFUNC(op_6a01_32), 27137 }, /* Bcc */
{ CPUFUNC(op_6aff_32), 27391 }, /* Bcc */
{ CPUFUNC(op_6b00_32), 27392 }, /* Bcc */
{ CPUFUNC(op_6b01_32), 27393 }, /* Bcc */
{ CPUFUNC(op_6bff_32), 27647 }, /* Bcc */
{ CPUFUNC(op_6c00_32), 27648 }, /* Bcc */
{ CPUFUNC(op_6c01_32), 27649 }, /* Bcc */
{ CPUFUNC(op_6cff_32), 27903 }, /* Bcc */
{ CPUFUNC(op_6d00_32), 27904 }, /* Bcc */
{ CPUFUNC(op_6d01_32), 27905 }, /* Bcc */
{ CPUFUNC(op_6dff_32), 28159 }, /* Bcc */
{ CPUFUNC(op_6e00_32), 28160 }, /* Bcc */
{ CPUFUNC(op_6e01_32), 28161 }, /* Bcc */
{ CPUFUNC(op_6eff_32), 28415 }, /* Bcc */
{ CPUFUNC(op_6f00_32), 28416 }, /* Bcc */
{ CPUFUNC(op_6f01_32), 28417 }, /* Bcc */
{ CPUFUNC(op_6fff_32), 28671 }, /* Bcc */
{ CPUFUNC(op_7000_32), 28672 }, /* MOVE */
{ CPUFUNC(op_8000_32), 32768 }, /* OR */
{ CPUFUNC(op_8010_32), 32784 }, /* OR */
{ CPUFUNC(op_8018_32), 32792 }, /* OR */
{ CPUFUNC(op_8020_32), 32800 }, /* OR */
{ CPUFUNC(op_8028_32), 32808 }, /* OR */
{ CPUFUNC(op_8030_32), 32816 }, /* OR */
{ CPUFUNC(op_8038_32), 32824 }, /* OR */
{ CPUFUNC(op_8039_32), 32825 }, /* OR */
{ CPUFUNC(op_803a_32), 32826 }, /* OR */
{ CPUFUNC(op_803b_32), 32827 }, /* OR */
{ CPUFUNC(op_803c_32), 32828 }, /* OR */
{ CPUFUNC(op_8040_32), 32832 }, /* OR */
{ CPUFUNC(op_8050_32), 32848 }, /* OR */
{ CPUFUNC(op_8058_32), 32856 }, /* OR */
{ CPUFUNC(op_8060_32), 32864 }, /* OR */
{ CPUFUNC(op_8068_32), 32872 }, /* OR */
{ CPUFUNC(op_8070_32), 32880 }, /* OR */
{ CPUFUNC(op_8078_32), 32888 }, /* OR */
{ CPUFUNC(op_8079_32), 32889 }, /* OR */
{ CPUFUNC(op_807a_32), 32890 }, /* OR */
{ CPUFUNC(op_807b_32), 32891 }, /* OR */
{ CPUFUNC(op_807c_32), 32892 }, /* OR */
{ CPUFUNC(op_8080_32), 32896 }, /* OR */
{ CPUFUNC(op_8090_32), 32912 }, /* OR */
{ CPUFUNC(op_8098_32), 32920 }, /* OR */
{ CPUFUNC(op_80a0_32), 32928 }, /* OR */
{ CPUFUNC(op_80a8_32), 32936 }, /* OR */
{ CPUFUNC(op_80b0_32), 32944 }, /* OR */
{ CPUFUNC(op_80b8_32), 32952 }, /* OR */
{ CPUFUNC(op_80b9_32), 32953 }, /* OR */
{ CPUFUNC(op_80ba_32), 32954 }, /* OR */
{ CPUFUNC(op_80bb_32), 32955 }, /* OR */
{ CPUFUNC(op_80bc_32), 32956 }, /* OR */
{ CPUFUNC(op_80c0_32), 32960 }, /* DIVU */
{ CPUFUNC(op_80d0_32), 32976 }, /* DIVU */
{ CPUFUNC(op_80d8_32), 32984 }, /* DIVU */
{ CPUFUNC(op_80e0_32), 32992 }, /* DIVU */
{ CPUFUNC(op_80e8_32), 33000 }, /* DIVU */
{ CPUFUNC(op_80f0_32), 33008 }, /* DIVU */
{ CPUFUNC(op_80f8_32), 33016 }, /* DIVU */
{ CPUFUNC(op_80f9_32), 33017 }, /* DIVU */
{ CPUFUNC(op_80fa_32), 33018 }, /* DIVU */
{ CPUFUNC(op_80fb_32), 33019 }, /* DIVU */
{ CPUFUNC(op_80fc_32), 33020 }, /* DIVU */
{ CPUFUNC(op_8100_32), 33024 }, /* SBCD */
{ CPUFUNC(op_8108_32), 33032 }, /* SBCD */
{ CPUFUNC(op_8110_32), 33040 }, /* OR */
{ CPUFUNC(op_8118_32), 33048 }, /* OR */
{ CPUFUNC(op_8120_32), 33056 }, /* OR */
{ CPUFUNC(op_8128_32), 33064 }, /* OR */
{ CPUFUNC(op_8130_32), 33072 }, /* OR */
{ CPUFUNC(op_8138_32), 33080 }, /* OR */
{ CPUFUNC(op_8139_32), 33081 }, /* OR */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_8140_32), 33088 }, /* PACK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_8148_32), 33096 }, /* PACK */
#endif
{ CPUFUNC(op_8150_32), 33104 }, /* OR */
{ CPUFUNC(op_8158_32), 33112 }, /* OR */
{ CPUFUNC(op_8160_32), 33120 }, /* OR */
{ CPUFUNC(op_8168_32), 33128 }, /* OR */
{ CPUFUNC(op_8170_32), 33136 }, /* OR */
{ CPUFUNC(op_8178_32), 33144 }, /* OR */
{ CPUFUNC(op_8179_32), 33145 }, /* OR */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_8180_32), 33152 }, /* UNPK */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_8188_32), 33160 }, /* UNPK */
#endif
{ CPUFUNC(op_8190_32), 33168 }, /* OR */
{ CPUFUNC(op_8198_32), 33176 }, /* OR */
{ CPUFUNC(op_81a0_32), 33184 }, /* OR */
{ CPUFUNC(op_81a8_32), 33192 }, /* OR */
{ CPUFUNC(op_81b0_32), 33200 }, /* OR */
{ CPUFUNC(op_81b8_32), 33208 }, /* OR */
{ CPUFUNC(op_81b9_32), 33209 }, /* OR */
{ CPUFUNC(op_81c0_32), 33216 }, /* DIVS */
{ CPUFUNC(op_81d0_32), 33232 }, /* DIVS */
{ CPUFUNC(op_81d8_32), 33240 }, /* DIVS */
{ CPUFUNC(op_81e0_32), 33248 }, /* DIVS */
{ CPUFUNC(op_81e8_32), 33256 }, /* DIVS */
{ CPUFUNC(op_81f0_32), 33264 }, /* DIVS */
{ CPUFUNC(op_81f8_32), 33272 }, /* DIVS */
{ CPUFUNC(op_81f9_32), 33273 }, /* DIVS */
{ CPUFUNC(op_81fa_32), 33274 }, /* DIVS */
{ CPUFUNC(op_81fb_32), 33275 }, /* DIVS */
{ CPUFUNC(op_81fc_32), 33276 }, /* DIVS */
{ CPUFUNC(op_9000_32), 36864 }, /* SUB */
{ CPUFUNC(op_9010_32), 36880 }, /* SUB */
{ CPUFUNC(op_9018_32), 36888 }, /* SUB */
{ CPUFUNC(op_9020_32), 36896 }, /* SUB */
{ CPUFUNC(op_9028_32), 36904 }, /* SUB */
{ CPUFUNC(op_9030_32), 36912 }, /* SUB */
{ CPUFUNC(op_9038_32), 36920 }, /* SUB */
{ CPUFUNC(op_9039_32), 36921 }, /* SUB */
{ CPUFUNC(op_903a_32), 36922 }, /* SUB */
{ CPUFUNC(op_903b_32), 36923 }, /* SUB */
{ CPUFUNC(op_903c_32), 36924 }, /* SUB */
{ CPUFUNC(op_9040_32), 36928 }, /* SUB */
{ CPUFUNC(op_9048_32), 36936 }, /* SUB */
{ CPUFUNC(op_9050_32), 36944 }, /* SUB */
{ CPUFUNC(op_9058_32), 36952 }, /* SUB */
{ CPUFUNC(op_9060_32), 36960 }, /* SUB */
{ CPUFUNC(op_9068_32), 36968 }, /* SUB */
{ CPUFUNC(op_9070_32), 36976 }, /* SUB */
{ CPUFUNC(op_9078_32), 36984 }, /* SUB */
{ CPUFUNC(op_9079_32), 36985 }, /* SUB */
{ CPUFUNC(op_907a_32), 36986 }, /* SUB */
{ CPUFUNC(op_907b_32), 36987 }, /* SUB */
{ CPUFUNC(op_907c_32), 36988 }, /* SUB */
{ CPUFUNC(op_9080_32), 36992 }, /* SUB */
{ CPUFUNC(op_9088_32), 37000 }, /* SUB */
{ CPUFUNC(op_9090_32), 37008 }, /* SUB */
{ CPUFUNC(op_9098_32), 37016 }, /* SUB */
{ CPUFUNC(op_90a0_32), 37024 }, /* SUB */
{ CPUFUNC(op_90a8_32), 37032 }, /* SUB */
{ CPUFUNC(op_90b0_32), 37040 }, /* SUB */
{ CPUFUNC(op_90b8_32), 37048 }, /* SUB */
{ CPUFUNC(op_90b9_32), 37049 }, /* SUB */
{ CPUFUNC(op_90ba_32), 37050 }, /* SUB */
{ CPUFUNC(op_90bb_32), 37051 }, /* SUB */
{ CPUFUNC(op_90bc_32), 37052 }, /* SUB */
{ CPUFUNC(op_90c0_32), 37056 }, /* SUBA */
{ CPUFUNC(op_90c8_32), 37064 }, /* SUBA */
{ CPUFUNC(op_90d0_32), 37072 }, /* SUBA */
{ CPUFUNC(op_90d8_32), 37080 }, /* SUBA */
{ CPUFUNC(op_90e0_32), 37088 }, /* SUBA */
{ CPUFUNC(op_90e8_32), 37096 }, /* SUBA */
{ CPUFUNC(op_90f0_32), 37104 }, /* SUBA */
{ CPUFUNC(op_90f8_32), 37112 }, /* SUBA */
{ CPUFUNC(op_90f9_32), 37113 }, /* SUBA */
{ CPUFUNC(op_90fa_32), 37114 }, /* SUBA */
{ CPUFUNC(op_90fb_32), 37115 }, /* SUBA */
{ CPUFUNC(op_90fc_32), 37116 }, /* SUBA */
{ CPUFUNC(op_9100_32), 37120 }, /* SUBX */
{ CPUFUNC(op_9108_32), 37128 }, /* SUBX */
{ CPUFUNC(op_9110_32), 37136 }, /* SUB */
{ CPUFUNC(op_9118_32), 37144 }, /* SUB */
{ CPUFUNC(op_9120_32), 37152 }, /* SUB */
{ CPUFUNC(op_9128_32), 37160 }, /* SUB */
{ CPUFUNC(op_9130_32), 37168 }, /* SUB */
{ CPUFUNC(op_9138_32), 37176 }, /* SUB */
{ CPUFUNC(op_9139_32), 37177 }, /* SUB */
{ CPUFUNC(op_9140_32), 37184 }, /* SUBX */
{ CPUFUNC(op_9148_32), 37192 }, /* SUBX */
{ CPUFUNC(op_9150_32), 37200 }, /* SUB */
{ CPUFUNC(op_9158_32), 37208 }, /* SUB */
{ CPUFUNC(op_9160_32), 37216 }, /* SUB */
{ CPUFUNC(op_9168_32), 37224 }, /* SUB */
{ CPUFUNC(op_9170_32), 37232 }, /* SUB */
{ CPUFUNC(op_9178_32), 37240 }, /* SUB */
{ CPUFUNC(op_9179_32), 37241 }, /* SUB */
{ CPUFUNC(op_9180_32), 37248 }, /* SUBX */
{ CPUFUNC(op_9188_32), 37256 }, /* SUBX */
{ CPUFUNC(op_9190_32), 37264 }, /* SUB */
{ CPUFUNC(op_9198_32), 37272 }, /* SUB */
{ CPUFUNC(op_91a0_32), 37280 }, /* SUB */
{ CPUFUNC(op_91a8_32), 37288 }, /* SUB */
{ CPUFUNC(op_91b0_32), 37296 }, /* SUB */
{ CPUFUNC(op_91b8_32), 37304 }, /* SUB */
{ CPUFUNC(op_91b9_32), 37305 }, /* SUB */
{ CPUFUNC(op_91c0_32), 37312 }, /* SUBA */
{ CPUFUNC(op_91c8_32), 37320 }, /* SUBA */
{ CPUFUNC(op_91d0_32), 37328 }, /* SUBA */
{ CPUFUNC(op_91d8_32), 37336 }, /* SUBA */
{ CPUFUNC(op_91e0_32), 37344 }, /* SUBA */
{ CPUFUNC(op_91e8_32), 37352 }, /* SUBA */
{ CPUFUNC(op_91f0_32), 37360 }, /* SUBA */
{ CPUFUNC(op_91f8_32), 37368 }, /* SUBA */
{ CPUFUNC(op_91f9_32), 37369 }, /* SUBA */
{ CPUFUNC(op_91fa_32), 37370 }, /* SUBA */
{ CPUFUNC(op_91fb_32), 37371 }, /* SUBA */
{ CPUFUNC(op_91fc_32), 37372 }, /* SUBA */
{ CPUFUNC(op_b000_32), 45056 }, /* CMP */
{ CPUFUNC(op_b010_32), 45072 }, /* CMP */
{ CPUFUNC(op_b018_32), 45080 }, /* CMP */
{ CPUFUNC(op_b020_32), 45088 }, /* CMP */
{ CPUFUNC(op_b028_32), 45096 }, /* CMP */
{ CPUFUNC(op_b030_32), 45104 }, /* CMP */
{ CPUFUNC(op_b038_32), 45112 }, /* CMP */
{ CPUFUNC(op_b039_32), 45113 }, /* CMP */
{ CPUFUNC(op_b03a_32), 45114 }, /* CMP */
{ CPUFUNC(op_b03b_32), 45115 }, /* CMP */
{ CPUFUNC(op_b03c_32), 45116 }, /* CMP */
{ CPUFUNC(op_b040_32), 45120 }, /* CMP */
{ CPUFUNC(op_b048_32), 45128 }, /* CMP */
{ CPUFUNC(op_b050_32), 45136 }, /* CMP */
{ CPUFUNC(op_b058_32), 45144 }, /* CMP */
{ CPUFUNC(op_b060_32), 45152 }, /* CMP */
{ CPUFUNC(op_b068_32), 45160 }, /* CMP */
{ CPUFUNC(op_b070_32), 45168 }, /* CMP */
{ CPUFUNC(op_b078_32), 45176 }, /* CMP */
{ CPUFUNC(op_b079_32), 45177 }, /* CMP */
{ CPUFUNC(op_b07a_32), 45178 }, /* CMP */
{ CPUFUNC(op_b07b_32), 45179 }, /* CMP */
{ CPUFUNC(op_b07c_32), 45180 }, /* CMP */
{ CPUFUNC(op_b080_32), 45184 }, /* CMP */
{ CPUFUNC(op_b088_32), 45192 }, /* CMP */
{ CPUFUNC(op_b090_32), 45200 }, /* CMP */
{ CPUFUNC(op_b098_32), 45208 }, /* CMP */
{ CPUFUNC(op_b0a0_32), 45216 }, /* CMP */
{ CPUFUNC(op_b0a8_32), 45224 }, /* CMP */
{ CPUFUNC(op_b0b0_32), 45232 }, /* CMP */
{ CPUFUNC(op_b0b8_32), 45240 }, /* CMP */
{ CPUFUNC(op_b0b9_32), 45241 }, /* CMP */
{ CPUFUNC(op_b0ba_32), 45242 }, /* CMP */
{ CPUFUNC(op_b0bb_32), 45243 }, /* CMP */
{ CPUFUNC(op_b0bc_32), 45244 }, /* CMP */
{ CPUFUNC(op_b0c0_32), 45248 }, /* CMPA */
{ CPUFUNC(op_b0c8_32), 45256 }, /* CMPA */
{ CPUFUNC(op_b0d0_32), 45264 }, /* CMPA */
{ CPUFUNC(op_b0d8_32), 45272 }, /* CMPA */
{ CPUFUNC(op_b0e0_32), 45280 }, /* CMPA */
{ CPUFUNC(op_b0e8_32), 45288 }, /* CMPA */
{ CPUFUNC(op_b0f0_32), 45296 }, /* CMPA */
{ CPUFUNC(op_b0f8_32), 45304 }, /* CMPA */
{ CPUFUNC(op_b0f9_32), 45305 }, /* CMPA */
{ CPUFUNC(op_b0fa_32), 45306 }, /* CMPA */
{ CPUFUNC(op_b0fb_32), 45307 }, /* CMPA */
{ CPUFUNC(op_b0fc_32), 45308 }, /* CMPA */
{ CPUFUNC(op_b100_32), 45312 }, /* EOR */
{ CPUFUNC(op_b108_32), 45320 }, /* CMPM */
{ CPUFUNC(op_b110_32), 45328 }, /* EOR */
{ CPUFUNC(op_b118_32), 45336 }, /* EOR */
{ CPUFUNC(op_b120_32), 45344 }, /* EOR */
{ CPUFUNC(op_b128_32), 45352 }, /* EOR */
{ CPUFUNC(op_b130_32), 45360 }, /* EOR */
{ CPUFUNC(op_b138_32), 45368 }, /* EOR */
{ CPUFUNC(op_b139_32), 45369 }, /* EOR */
{ CPUFUNC(op_b140_32), 45376 }, /* EOR */
{ CPUFUNC(op_b148_32), 45384 }, /* CMPM */
{ CPUFUNC(op_b150_32), 45392 }, /* EOR */
{ CPUFUNC(op_b158_32), 45400 }, /* EOR */
{ CPUFUNC(op_b160_32), 45408 }, /* EOR */
{ CPUFUNC(op_b168_32), 45416 }, /* EOR */
{ CPUFUNC(op_b170_32), 45424 }, /* EOR */
{ CPUFUNC(op_b178_32), 45432 }, /* EOR */
{ CPUFUNC(op_b179_32), 45433 }, /* EOR */
{ CPUFUNC(op_b180_32), 45440 }, /* EOR */
{ CPUFUNC(op_b188_32), 45448 }, /* CMPM */
{ CPUFUNC(op_b190_32), 45456 }, /* EOR */
{ CPUFUNC(op_b198_32), 45464 }, /* EOR */
{ CPUFUNC(op_b1a0_32), 45472 }, /* EOR */
{ CPUFUNC(op_b1a8_32), 45480 }, /* EOR */
{ CPUFUNC(op_b1b0_32), 45488 }, /* EOR */
{ CPUFUNC(op_b1b8_32), 45496 }, /* EOR */
{ CPUFUNC(op_b1b9_32), 45497 }, /* EOR */
{ CPUFUNC(op_b1c0_32), 45504 }, /* CMPA */
{ CPUFUNC(op_b1c8_32), 45512 }, /* CMPA */
{ CPUFUNC(op_b1d0_32), 45520 }, /* CMPA */
{ CPUFUNC(op_b1d8_32), 45528 }, /* CMPA */
{ CPUFUNC(op_b1e0_32), 45536 }, /* CMPA */
{ CPUFUNC(op_b1e8_32), 45544 }, /* CMPA */
{ CPUFUNC(op_b1f0_32), 45552 }, /* CMPA */
{ CPUFUNC(op_b1f8_32), 45560 }, /* CMPA */
{ CPUFUNC(op_b1f9_32), 45561 }, /* CMPA */
{ CPUFUNC(op_b1fa_32), 45562 }, /* CMPA */
{ CPUFUNC(op_b1fb_32), 45563 }, /* CMPA */
{ CPUFUNC(op_b1fc_32), 45564 }, /* CMPA */
{ CPUFUNC(op_c000_32), 49152 }, /* AND */
{ CPUFUNC(op_c010_32), 49168 }, /* AND */
{ CPUFUNC(op_c018_32), 49176 }, /* AND */
{ CPUFUNC(op_c020_32), 49184 }, /* AND */
{ CPUFUNC(op_c028_32), 49192 }, /* AND */
{ CPUFUNC(op_c030_32), 49200 }, /* AND */
{ CPUFUNC(op_c038_32), 49208 }, /* AND */
{ CPUFUNC(op_c039_32), 49209 }, /* AND */
{ CPUFUNC(op_c03a_32), 49210 }, /* AND */
{ CPUFUNC(op_c03b_32), 49211 }, /* AND */
{ CPUFUNC(op_c03c_32), 49212 }, /* AND */
{ CPUFUNC(op_c040_32), 49216 }, /* AND */
{ CPUFUNC(op_c050_32), 49232 }, /* AND */
{ CPUFUNC(op_c058_32), 49240 }, /* AND */
{ CPUFUNC(op_c060_32), 49248 }, /* AND */
{ CPUFUNC(op_c068_32), 49256 }, /* AND */
{ CPUFUNC(op_c070_32), 49264 }, /* AND */
{ CPUFUNC(op_c078_32), 49272 }, /* AND */
{ CPUFUNC(op_c079_32), 49273 }, /* AND */
{ CPUFUNC(op_c07a_32), 49274 }, /* AND */
{ CPUFUNC(op_c07b_32), 49275 }, /* AND */
{ CPUFUNC(op_c07c_32), 49276 }, /* AND */
{ CPUFUNC(op_c080_32), 49280 }, /* AND */
{ CPUFUNC(op_c090_32), 49296 }, /* AND */
{ CPUFUNC(op_c098_32), 49304 }, /* AND */
{ CPUFUNC(op_c0a0_32), 49312 }, /* AND */
{ CPUFUNC(op_c0a8_32), 49320 }, /* AND */
{ CPUFUNC(op_c0b0_32), 49328 }, /* AND */
{ CPUFUNC(op_c0b8_32), 49336 }, /* AND */
{ CPUFUNC(op_c0b9_32), 49337 }, /* AND */
{ CPUFUNC(op_c0ba_32), 49338 }, /* AND */
{ CPUFUNC(op_c0bb_32), 49339 }, /* AND */
{ CPUFUNC(op_c0bc_32), 49340 }, /* AND */
{ CPUFUNC(op_c0c0_32), 49344 }, /* MULU */
{ CPUFUNC(op_c0d0_32), 49360 }, /* MULU */
{ CPUFUNC(op_c0d8_32), 49368 }, /* MULU */
{ CPUFUNC(op_c0e0_32), 49376 }, /* MULU */
{ CPUFUNC(op_c0e8_32), 49384 }, /* MULU */
{ CPUFUNC(op_c0f0_32), 49392 }, /* MULU */
{ CPUFUNC(op_c0f8_32), 49400 }, /* MULU */
{ CPUFUNC(op_c0f9_32), 49401 }, /* MULU */
{ CPUFUNC(op_c0fa_32), 49402 }, /* MULU */
{ CPUFUNC(op_c0fb_32), 49403 }, /* MULU */
{ CPUFUNC(op_c0fc_32), 49404 }, /* MULU */
{ CPUFUNC(op_c100_32), 49408 }, /* ABCD */
{ CPUFUNC(op_c108_32), 49416 }, /* ABCD */
{ CPUFUNC(op_c110_32), 49424 }, /* AND */
{ CPUFUNC(op_c118_32), 49432 }, /* AND */
{ CPUFUNC(op_c120_32), 49440 }, /* AND */
{ CPUFUNC(op_c128_32), 49448 }, /* AND */
{ CPUFUNC(op_c130_32), 49456 }, /* AND */
{ CPUFUNC(op_c138_32), 49464 }, /* AND */
{ CPUFUNC(op_c139_32), 49465 }, /* AND */
{ CPUFUNC(op_c140_32), 49472 }, /* EXG */
{ CPUFUNC(op_c148_32), 49480 }, /* EXG */
{ CPUFUNC(op_c150_32), 49488 }, /* AND */
{ CPUFUNC(op_c158_32), 49496 }, /* AND */
{ CPUFUNC(op_c160_32), 49504 }, /* AND */
{ CPUFUNC(op_c168_32), 49512 }, /* AND */
{ CPUFUNC(op_c170_32), 49520 }, /* AND */
{ CPUFUNC(op_c178_32), 49528 }, /* AND */
{ CPUFUNC(op_c179_32), 49529 }, /* AND */
{ CPUFUNC(op_c188_32), 49544 }, /* EXG */
{ CPUFUNC(op_c190_32), 49552 }, /* AND */
{ CPUFUNC(op_c198_32), 49560 }, /* AND */
{ CPUFUNC(op_c1a0_32), 49568 }, /* AND */
{ CPUFUNC(op_c1a8_32), 49576 }, /* AND */
{ CPUFUNC(op_c1b0_32), 49584 }, /* AND */
{ CPUFUNC(op_c1b8_32), 49592 }, /* AND */
{ CPUFUNC(op_c1b9_32), 49593 }, /* AND */
{ CPUFUNC(op_c1c0_32), 49600 }, /* MULS */
{ CPUFUNC(op_c1d0_32), 49616 }, /* MULS */
{ CPUFUNC(op_c1d8_32), 49624 }, /* MULS */
{ CPUFUNC(op_c1e0_32), 49632 }, /* MULS */
{ CPUFUNC(op_c1e8_32), 49640 }, /* MULS */
{ CPUFUNC(op_c1f0_32), 49648 }, /* MULS */
{ CPUFUNC(op_c1f8_32), 49656 }, /* MULS */
{ CPUFUNC(op_c1f9_32), 49657 }, /* MULS */
{ CPUFUNC(op_c1fa_32), 49658 }, /* MULS */
{ CPUFUNC(op_c1fb_32), 49659 }, /* MULS */
{ CPUFUNC(op_c1fc_32), 49660 }, /* MULS */
{ CPUFUNC(op_d000_32), 53248 }, /* ADD */
{ CPUFUNC(op_d010_32), 53264 }, /* ADD */
{ CPUFUNC(op_d018_32), 53272 }, /* ADD */
{ CPUFUNC(op_d020_32), 53280 }, /* ADD */
{ CPUFUNC(op_d028_32), 53288 }, /* ADD */
{ CPUFUNC(op_d030_32), 53296 }, /* ADD */
{ CPUFUNC(op_d038_32), 53304 }, /* ADD */
{ CPUFUNC(op_d039_32), 53305 }, /* ADD */
{ CPUFUNC(op_d03a_32), 53306 }, /* ADD */
{ CPUFUNC(op_d03b_32), 53307 }, /* ADD */
{ CPUFUNC(op_d03c_32), 53308 }, /* ADD */
{ CPUFUNC(op_d040_32), 53312 }, /* ADD */
{ CPUFUNC(op_d048_32), 53320 }, /* ADD */
{ CPUFUNC(op_d050_32), 53328 }, /* ADD */
{ CPUFUNC(op_d058_32), 53336 }, /* ADD */
{ CPUFUNC(op_d060_32), 53344 }, /* ADD */
{ CPUFUNC(op_d068_32), 53352 }, /* ADD */
{ CPUFUNC(op_d070_32), 53360 }, /* ADD */
{ CPUFUNC(op_d078_32), 53368 }, /* ADD */
{ CPUFUNC(op_d079_32), 53369 }, /* ADD */
{ CPUFUNC(op_d07a_32), 53370 }, /* ADD */
{ CPUFUNC(op_d07b_32), 53371 }, /* ADD */
{ CPUFUNC(op_d07c_32), 53372 }, /* ADD */
{ CPUFUNC(op_d080_32), 53376 }, /* ADD */
{ CPUFUNC(op_d088_32), 53384 }, /* ADD */
{ CPUFUNC(op_d090_32), 53392 }, /* ADD */
{ CPUFUNC(op_d098_32), 53400 }, /* ADD */
{ CPUFUNC(op_d0a0_32), 53408 }, /* ADD */
{ CPUFUNC(op_d0a8_32), 53416 }, /* ADD */
{ CPUFUNC(op_d0b0_32), 53424 }, /* ADD */
{ CPUFUNC(op_d0b8_32), 53432 }, /* ADD */
{ CPUFUNC(op_d0b9_32), 53433 }, /* ADD */
{ CPUFUNC(op_d0ba_32), 53434 }, /* ADD */
{ CPUFUNC(op_d0bb_32), 53435 }, /* ADD */
{ CPUFUNC(op_d0bc_32), 53436 }, /* ADD */
{ CPUFUNC(op_d0c0_32), 53440 }, /* ADDA */
{ CPUFUNC(op_d0c8_32), 53448 }, /* ADDA */
{ CPUFUNC(op_d0d0_32), 53456 }, /* ADDA */
{ CPUFUNC(op_d0d8_32), 53464 }, /* ADDA */
{ CPUFUNC(op_d0e0_32), 53472 }, /* ADDA */
{ CPUFUNC(op_d0e8_32), 53480 }, /* ADDA */
{ CPUFUNC(op_d0f0_32), 53488 }, /* ADDA */
{ CPUFUNC(op_d0f8_32), 53496 }, /* ADDA */
{ CPUFUNC(op_d0f9_32), 53497 }, /* ADDA */
{ CPUFUNC(op_d0fa_32), 53498 }, /* ADDA */
{ CPUFUNC(op_d0fb_32), 53499 }, /* ADDA */
{ CPUFUNC(op_d0fc_32), 53500 }, /* ADDA */
{ CPUFUNC(op_d100_32), 53504 }, /* ADDX */
{ CPUFUNC(op_d108_32), 53512 }, /* ADDX */
{ CPUFUNC(op_d110_32), 53520 }, /* ADD */
{ CPUFUNC(op_d118_32), 53528 }, /* ADD */
{ CPUFUNC(op_d120_32), 53536 }, /* ADD */
{ CPUFUNC(op_d128_32), 53544 }, /* ADD */
{ CPUFUNC(op_d130_32), 53552 }, /* ADD */
{ CPUFUNC(op_d138_32), 53560 }, /* ADD */
{ CPUFUNC(op_d139_32), 53561 }, /* ADD */
{ CPUFUNC(op_d140_32), 53568 }, /* ADDX */
{ CPUFUNC(op_d148_32), 53576 }, /* ADDX */
{ CPUFUNC(op_d150_32), 53584 }, /* ADD */
{ CPUFUNC(op_d158_32), 53592 }, /* ADD */
{ CPUFUNC(op_d160_32), 53600 }, /* ADD */
{ CPUFUNC(op_d168_32), 53608 }, /* ADD */
{ CPUFUNC(op_d170_32), 53616 }, /* ADD */
{ CPUFUNC(op_d178_32), 53624 }, /* ADD */
{ CPUFUNC(op_d179_32), 53625 }, /* ADD */
{ CPUFUNC(op_d180_32), 53632 }, /* ADDX */
{ CPUFUNC(op_d188_32), 53640 }, /* ADDX */
{ CPUFUNC(op_d190_32), 53648 }, /* ADD */
{ CPUFUNC(op_d198_32), 53656 }, /* ADD */
{ CPUFUNC(op_d1a0_32), 53664 }, /* ADD */
{ CPUFUNC(op_d1a8_32), 53672 }, /* ADD */
{ CPUFUNC(op_d1b0_32), 53680 }, /* ADD */
{ CPUFUNC(op_d1b8_32), 53688 }, /* ADD */
{ CPUFUNC(op_d1b9_32), 53689 }, /* ADD */
{ CPUFUNC(op_d1c0_32), 53696 }, /* ADDA */
{ CPUFUNC(op_d1c8_32), 53704 }, /* ADDA */
{ CPUFUNC(op_d1d0_32), 53712 }, /* ADDA */
{ CPUFUNC(op_d1d8_32), 53720 }, /* ADDA */
{ CPUFUNC(op_d1e0_32), 53728 }, /* ADDA */
{ CPUFUNC(op_d1e8_32), 53736 }, /* ADDA */
{ CPUFUNC(op_d1f0_32), 53744 }, /* ADDA */
{ CPUFUNC(op_d1f8_32), 53752 }, /* ADDA */
{ CPUFUNC(op_d1f9_32), 53753 }, /* ADDA */
{ CPUFUNC(op_d1fa_32), 53754 }, /* ADDA */
{ CPUFUNC(op_d1fb_32), 53755 }, /* ADDA */
{ CPUFUNC(op_d1fc_32), 53756 }, /* ADDA */
{ CPUFUNC(op_e000_32), 57344 }, /* ASR */
{ CPUFUNC(op_e008_32), 57352 }, /* LSR */
{ CPUFUNC(op_e010_32), 57360 }, /* ROXR */
{ CPUFUNC(op_e018_32), 57368 }, /* ROR */
{ CPUFUNC(op_e020_32), 57376 }, /* ASR */
{ CPUFUNC(op_e028_32), 57384 }, /* LSR */
{ CPUFUNC(op_e030_32), 57392 }, /* ROXR */
{ CPUFUNC(op_e038_32), 57400 }, /* ROR */
{ CPUFUNC(op_e040_32), 57408 }, /* ASR */
{ CPUFUNC(op_e048_32), 57416 }, /* LSR */
{ CPUFUNC(op_e050_32), 57424 }, /* ROXR */
{ CPUFUNC(op_e058_32), 57432 }, /* ROR */
{ CPUFUNC(op_e060_32), 57440 }, /* ASR */
{ CPUFUNC(op_e068_32), 57448 }, /* LSR */
{ CPUFUNC(op_e070_32), 57456 }, /* ROXR */
{ CPUFUNC(op_e078_32), 57464 }, /* ROR */
{ CPUFUNC(op_e080_32), 57472 }, /* ASR */
{ CPUFUNC(op_e088_32), 57480 }, /* LSR */
{ CPUFUNC(op_e090_32), 57488 }, /* ROXR */
{ CPUFUNC(op_e098_32), 57496 }, /* ROR */
{ CPUFUNC(op_e0a0_32), 57504 }, /* ASR */
{ CPUFUNC(op_e0a8_32), 57512 }, /* LSR */
{ CPUFUNC(op_e0b0_32), 57520 }, /* ROXR */
{ CPUFUNC(op_e0b8_32), 57528 }, /* ROR */
{ CPUFUNC(op_e0d0_32), 57552 }, /* ASRW */
{ CPUFUNC(op_e0d8_32), 57560 }, /* ASRW */
{ CPUFUNC(op_e0e0_32), 57568 }, /* ASRW */
{ CPUFUNC(op_e0e8_32), 57576 }, /* ASRW */
{ CPUFUNC(op_e0f0_32), 57584 }, /* ASRW */
{ CPUFUNC(op_e0f8_32), 57592 }, /* ASRW */
{ CPUFUNC(op_e0f9_32), 57593 }, /* ASRW */
{ CPUFUNC(op_e100_32), 57600 }, /* ASL */
{ CPUFUNC(op_e108_32), 57608 }, /* LSL */
{ CPUFUNC(op_e110_32), 57616 }, /* ROXL */
{ CPUFUNC(op_e118_32), 57624 }, /* ROL */
{ CPUFUNC(op_e120_32), 57632 }, /* ASL */
{ CPUFUNC(op_e128_32), 57640 }, /* LSL */
{ CPUFUNC(op_e130_32), 57648 }, /* ROXL */
{ CPUFUNC(op_e138_32), 57656 }, /* ROL */
{ CPUFUNC(op_e140_32), 57664 }, /* ASL */
{ CPUFUNC(op_e148_32), 57672 }, /* LSL */
{ CPUFUNC(op_e150_32), 57680 }, /* ROXL */
{ CPUFUNC(op_e158_32), 57688 }, /* ROL */
{ CPUFUNC(op_e160_32), 57696 }, /* ASL */
{ CPUFUNC(op_e168_32), 57704 }, /* LSL */
{ CPUFUNC(op_e170_32), 57712 }, /* ROXL */
{ CPUFUNC(op_e178_32), 57720 }, /* ROL */
{ CPUFUNC(op_e180_32), 57728 }, /* ASL */
{ CPUFUNC(op_e188_32), 57736 }, /* LSL */
{ CPUFUNC(op_e190_32), 57744 }, /* ROXL */
{ CPUFUNC(op_e198_32), 57752 }, /* ROL */
{ CPUFUNC(op_e1a0_32), 57760 }, /* ASL */
{ CPUFUNC(op_e1a8_32), 57768 }, /* LSL */
{ CPUFUNC(op_e1b0_32), 57776 }, /* ROXL */
{ CPUFUNC(op_e1b8_32), 57784 }, /* ROL */
{ CPUFUNC(op_e1d0_32), 57808 }, /* ASLW */
{ CPUFUNC(op_e1d8_32), 57816 }, /* ASLW */
{ CPUFUNC(op_e1e0_32), 57824 }, /* ASLW */
{ CPUFUNC(op_e1e8_32), 57832 }, /* ASLW */
{ CPUFUNC(op_e1f0_32), 57840 }, /* ASLW */
{ CPUFUNC(op_e1f8_32), 57848 }, /* ASLW */
{ CPUFUNC(op_e1f9_32), 57849 }, /* ASLW */
{ CPUFUNC(op_e2d0_32), 58064 }, /* LSRW */
{ CPUFUNC(op_e2d8_32), 58072 }, /* LSRW */
{ CPUFUNC(op_e2e0_32), 58080 }, /* LSRW */
{ CPUFUNC(op_e2e8_32), 58088 }, /* LSRW */
{ CPUFUNC(op_e2f0_32), 58096 }, /* LSRW */
{ CPUFUNC(op_e2f8_32), 58104 }, /* LSRW */
{ CPUFUNC(op_e2f9_32), 58105 }, /* LSRW */
{ CPUFUNC(op_e3d0_32), 58320 }, /* LSLW */
{ CPUFUNC(op_e3d8_32), 58328 }, /* LSLW */
{ CPUFUNC(op_e3e0_32), 58336 }, /* LSLW */
{ CPUFUNC(op_e3e8_32), 58344 }, /* LSLW */
{ CPUFUNC(op_e3f0_32), 58352 }, /* LSLW */
{ CPUFUNC(op_e3f8_32), 58360 }, /* LSLW */
{ CPUFUNC(op_e3f9_32), 58361 }, /* LSLW */
{ CPUFUNC(op_e4d0_32), 58576 }, /* ROXRW */
{ CPUFUNC(op_e4d8_32), 58584 }, /* ROXRW */
{ CPUFUNC(op_e4e0_32), 58592 }, /* ROXRW */
{ CPUFUNC(op_e4e8_32), 58600 }, /* ROXRW */
{ CPUFUNC(op_e4f0_32), 58608 }, /* ROXRW */
{ CPUFUNC(op_e4f8_32), 58616 }, /* ROXRW */
{ CPUFUNC(op_e4f9_32), 58617 }, /* ROXRW */
{ CPUFUNC(op_e5d0_32), 58832 }, /* ROXLW */
{ CPUFUNC(op_e5d8_32), 58840 }, /* ROXLW */
{ CPUFUNC(op_e5e0_32), 58848 }, /* ROXLW */
{ CPUFUNC(op_e5e8_32), 58856 }, /* ROXLW */
{ CPUFUNC(op_e5f0_32), 58864 }, /* ROXLW */
{ CPUFUNC(op_e5f8_32), 58872 }, /* ROXLW */
{ CPUFUNC(op_e5f9_32), 58873 }, /* ROXLW */
{ CPUFUNC(op_e6d0_32), 59088 }, /* RORW */
{ CPUFUNC(op_e6d8_32), 59096 }, /* RORW */
{ CPUFUNC(op_e6e0_32), 59104 }, /* RORW */
{ CPUFUNC(op_e6e8_32), 59112 }, /* RORW */
{ CPUFUNC(op_e6f0_32), 59120 }, /* RORW */
{ CPUFUNC(op_e6f8_32), 59128 }, /* RORW */
{ CPUFUNC(op_e6f9_32), 59129 }, /* RORW */
{ CPUFUNC(op_e7d0_32), 59344 }, /* ROLW */
{ CPUFUNC(op_e7d8_32), 59352 }, /* ROLW */
{ CPUFUNC(op_e7e0_32), 59360 }, /* ROLW */
{ CPUFUNC(op_e7e8_32), 59368 }, /* ROLW */
{ CPUFUNC(op_e7f0_32), 59376 }, /* ROLW */
{ CPUFUNC(op_e7f8_32), 59384 }, /* ROLW */
{ CPUFUNC(op_e7f9_32), 59385 }, /* ROLW */
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e8c0_32), 59584 }, /* BFTST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e8d0_32), 59600 }, /* BFTST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e8e8_32), 59624 }, /* BFTST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e8f0_32), 59632 }, /* BFTST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e8f8_32), 59640 }, /* BFTST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e8f9_32), 59641 }, /* BFTST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e8fa_32), 59642 }, /* BFTST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e8fb_32), 59643 }, /* BFTST */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e9c0_32), 59840 }, /* BFEXTU */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e9d0_32), 59856 }, /* BFEXTU */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e9e8_32), 59880 }, /* BFEXTU */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e9f0_32), 59888 }, /* BFEXTU */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e9f8_32), 59896 }, /* BFEXTU */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e9f9_32), 59897 }, /* BFEXTU */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e9fa_32), 59898 }, /* BFEXTU */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_e9fb_32), 59899 }, /* BFEXTU */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eac0_32), 60096 }, /* BFCHG */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ead0_32), 60112 }, /* BFCHG */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eae8_32), 60136 }, /* BFCHG */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eaf0_32), 60144 }, /* BFCHG */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eaf8_32), 60152 }, /* BFCHG */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eaf9_32), 60153 }, /* BFCHG */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ebc0_32), 60352 }, /* BFEXTS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ebd0_32), 60368 }, /* BFEXTS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ebe8_32), 60392 }, /* BFEXTS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ebf0_32), 60400 }, /* BFEXTS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ebf8_32), 60408 }, /* BFEXTS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ebf9_32), 60409 }, /* BFEXTS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ebfa_32), 60410 }, /* BFEXTS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ebfb_32), 60411 }, /* BFEXTS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ecc0_32), 60608 }, /* BFCLR */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ecd0_32), 60624 }, /* BFCLR */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ece8_32), 60648 }, /* BFCLR */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ecf0_32), 60656 }, /* BFCLR */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ecf8_32), 60664 }, /* BFCLR */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ecf9_32), 60665 }, /* BFCLR */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_edc0_32), 60864 }, /* BFFFO */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_edd0_32), 60880 }, /* BFFFO */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_ede8_32), 60904 }, /* BFFFO */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_edf0_32), 60912 }, /* BFFFO */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_edf8_32), 60920 }, /* BFFFO */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_edf9_32), 60921 }, /* BFFFO */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_edfa_32), 60922 }, /* BFFFO */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_edfb_32), 60923 }, /* BFFFO */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eec0_32), 61120 }, /* BFSET */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eed0_32), 61136 }, /* BFSET */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eee8_32), 61160 }, /* BFSET */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eef0_32), 61168 }, /* BFSET */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eef8_32), 61176 }, /* BFSET */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eef9_32), 61177 }, /* BFSET */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_efc0_32), 61376 }, /* BFINS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_efd0_32), 61392 }, /* BFINS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_efe8_32), 61416 }, /* BFINS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eff0_32), 61424 }, /* BFINS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eff8_32), 61432 }, /* BFINS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_eff9_32), 61433 }, /* BFINS */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f000_32), 61440 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f008_32), 61448 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f010_32), 61456 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f018_32), 61464 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f020_32), 61472 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f028_32), 61480 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f030_32), 61488 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f038_32), 61496 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f039_32), 61497 }, /* MMUOP030 */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f200_32), 61952 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f208_32), 61960 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f210_32), 61968 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f218_32), 61976 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f220_32), 61984 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f228_32), 61992 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f230_32), 62000 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f238_32), 62008 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f239_32), 62009 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f23a_32), 62010 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f23b_32), 62011 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f23c_32), 62012 }, /* FPP */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f240_32), 62016 }, /* FScc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f248_32), 62024 }, /* FDBcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f250_32), 62032 }, /* FScc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f258_32), 62040 }, /* FScc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f260_32), 62048 }, /* FScc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f268_32), 62056 }, /* FScc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f270_32), 62064 }, /* FScc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f278_32), 62072 }, /* FScc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f279_32), 62073 }, /* FScc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f27a_32), 62074 }, /* FTRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f27b_32), 62075 }, /* FTRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f27c_32), 62076 }, /* FTRAPcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f280_32), 62080 }, /* FBcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f2c0_32), 62144 }, /* FBcc */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f310_32), 62224 }, /* FSAVE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f320_32), 62240 }, /* FSAVE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f328_32), 62248 }, /* FSAVE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f330_32), 62256 }, /* FSAVE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f338_32), 62264 }, /* FSAVE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f339_32), 62265 }, /* FSAVE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f350_32), 62288 }, /* FRESTORE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f358_32), 62296 }, /* FRESTORE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f368_32), 62312 }, /* FRESTORE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f370_32), 62320 }, /* FRESTORE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f378_32), 62328 }, /* FRESTORE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f379_32), 62329 }, /* FRESTORE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f37a_32), 62330 }, /* FRESTORE */
#endif
#ifndef CPUEMU_68000_ONLY
{ CPUFUNC(op_f37b_32), 62331 }, /* FRESTORE */
#endif
{ 0, 0 }};
#endif /* CPUEMU_68000_ONLY */
#endif /* CPUEMU_32 */
