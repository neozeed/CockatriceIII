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


/**
 * Initialize 680x0 emulation
 */
int Init680x0(void)
{
int processor=0;
int nprocessor=0;
        currprefs.cpu_level = changed_prefs.cpu_level = ConfigureParams.System.nCpuLevel=nprocessor;
        switch (processor) {
                case 0 : currprefs.cpu_model = 68000; break;
                case 1 : currprefs.cpu_model = 68010; break;
                case 2 : currprefs.cpu_model = 68020; break;
                case 3 : currprefs.cpu_model = 68030; break;
                case 4 : currprefs.cpu_model = 68040; break;
                case 5 : currprefs.cpu_model = 68060; break;
                default: fprintf (stderr, "Init680x0() : Error, cpu_level unknown\n");
        }
	printf("processor will be a %d\n",currprefs.cpu_model);

currprefs.fpu_revision = 0;//68881 0x1f; 
        currprefs.cpu_compatible = changed_prefs.cpu_compatible = ConfigureParams.System.bCompatibleCpu=nprocessor;
        currprefs.address_space_24 = changed_prefs.address_space_24 = ConfigureParams.System.bAddressSpace24;
        currprefs.cpu_cycle_exact = changed_prefs.cpu_cycle_exact = ConfigureParams.System.bCycleExactCpu=0;
        currprefs.fpu_strict = changed_prefs.fpu_strict = ConfigureParams.System.bCompatibleFPU=0;
    currprefs.mmu_model = changed_prefs.mmu_model = ConfigureParams.System.bMMU?changed_prefs.cpu_model:1;

        Log_Printf(LOG_WARN,"Init680x0() called\n");

        init_m68k();

        return true;

}

int main(){
memset(&currprefs,0x0,sizeof(currprefs));
memset(&changed_prefs,0x0,sizeof(changed_prefs));
Init680x0();
printf("do nothing!\n");
}
