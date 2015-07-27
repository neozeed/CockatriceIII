#include <stdio.h>
#include <stdlib.h>

#include "sysdeps.h"
#include "compat.h"
#include "options_cpu.h"
#include "configuration.h"
#include "log.h"
int nCyclesMainCounter;
int CurrentInstrCycles;
int PendingInterruptCount;
int PendingInterruptFunction(){}
int pendingInterrupts;
int nWaitStateCycles;
int nCpuFreqShift;

struct uae_prefs currprefs;
struct uae_prefs changed_prefs;
CNF_PARAMS ConfigureParams;
DebugCpu_Check()
{}

//Log_Printf(int level,char *message){
void Log_Printf(LOGTYPE nType, const char *psFormat, ...)
{
printf("%s",psFormat);
}

//interrupts
int intlev(){
return 0;
}

void customreset()
{
       pendingInterrupts = 0;
}

//FPU stuff
restore_u16(){}
restore_u32(){}
save_u16(){}
save_u32(){}

//BUS
M68000_BusError(){}

//memory
int Configuration_CheckMemory(){return 1024*64;}
void IoMem_Init(){}
bmap_bget(){}
bmap_bput(){}
bmap_wput(){}
bmap_wget(){}
bmap_lget(){}
bmap_lput(){}


/**
 * Initialize 680x0 emulation
 */
int Init680x0(void)
{
int processor=4;
        currprefs.cpu_level = changed_prefs.cpu_level = ConfigureParams.System.nCpuLevel=processor;
        switch (processor) {
                case 0 : currprefs.cpu_model = 68000; break;
                case 1 : currprefs.cpu_model = 68010; break;
                case 2 : currprefs.cpu_model = 68020; break;
                case 3 : currprefs.cpu_model = 68030; break;
                case 4 : currprefs.cpu_model = 68040; break;
                case 5 : currprefs.cpu_model = 68060; break;
                default: fprintf (stderr, "Init680x0() : Error, cpu_level unknown\n");
        }
	printf("currprefs.cpu_model is  %d\n",currprefs.cpu_model);

    currprefs.fpu_model = changed_prefs.fpu_model = ConfigureParams.System.n_FPUType=68040;
	ConfigureParams.System.bTurbo=0;
printf("Init680x0 currprefs.fpu_model %d\n",currprefs.fpu_model);
    switch (currprefs.fpu_model) {
        case 68881: currprefs.fpu_revision = 0x1f; break;
        case 68882: currprefs.fpu_revision = 0x20; break;
        case 68040:
            if (ConfigureParams.System.bTurbo)
                currprefs.fpu_revision = 0x41;
            else
                currprefs.fpu_revision = 0x40;
            break;
                default: fprintf (stderr, "Init680x0() : Error, fpu_model unknown\n");
    }


        currprefs.cpu_compatible = changed_prefs.cpu_compatible = ConfigureParams.System.bCompatibleCpu;
        currprefs.address_space_24 = changed_prefs.address_space_24 = ConfigureParams.System.bAddressSpace24;
        currprefs.cpu_cycle_exact = changed_prefs.cpu_cycle_exact = ConfigureParams.System.bCycleExactCpu;
        currprefs.fpu_strict = changed_prefs.fpu_strict = ConfigureParams.System.bCompatibleFPU;
    currprefs.mmu_model = changed_prefs.mmu_model = ConfigureParams.System.bMMU?changed_prefs.cpu_model:0;

currprefs.cpu_compatible=1;
currprefs.cpu_level=4;
currprefs.cpu_model=68040;      //JASON hack
changed_prefs.cpu_compatible=1;
changed_prefs.cpu_model=68040;
changed_prefs.cpu_level=4;
currprefs.mmu_model=changed_prefs.mmu_model=currprefs.mmu_model=68040;


        Log_Printf(LOG_WARN,"Init680x0() called\n");

        init_m68k();

        return true;

}

static void M68000_InitPairing ()
{
#if 0
#endif
}

int main(){
memset(&currprefs,0x0,sizeof(currprefs));
memset(&changed_prefs,0x0,sizeof(changed_prefs));
Init680x0();
M68000_InitPairing();
printf("do nothing!\n");
}
