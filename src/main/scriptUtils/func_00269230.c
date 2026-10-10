#include "types.h"
extern int D_00533870;
extern void func_00127DB8(int seed);
/* Seeds the random generator from the hardware timer plus a global. */
void Global_Randomize(void) { func_00127DB8(*(volatile int*)0x10000800 + D_00533870); }
