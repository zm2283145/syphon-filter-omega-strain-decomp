#include "types.h"

/* Busy-waits until bit 8 of the hardware register 0x1000D400 clears. */
void func_003732C0(void)
{
    while (*(volatile int*)0x1000D400 & 0x100)
        ;
}
