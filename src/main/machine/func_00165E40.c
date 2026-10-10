#include "types.h"

extern long D_00533878;
extern int D_00533870;

/* Resets timer state and the EE timer 0 counter register. */
int func_00165E40(void)
{
    D_00533878 = 0;
    D_00533870 = 0;
    *(volatile int*)0x10000800 = 0;
    return 1;
}
