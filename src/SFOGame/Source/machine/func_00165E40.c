#include "types.h"

extern long g_TickCounter64;
extern int g_TimerAccum;

/* Resets timer state and the EE timer 0 counter register. */
int cMachine_InitTimers(void)
{
    g_TickCounter64 = 0;
    g_TimerAccum = 0;
    *(volatile int*)0x10000800 = 0;
    return 1;
}
