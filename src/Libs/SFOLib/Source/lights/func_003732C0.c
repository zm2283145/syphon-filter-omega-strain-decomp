#include "types.h"

/* Busy-waits until bit 8 of the hardware register 0x1000D400 clears. */
void FASTDMA_Wait_ToSPR(void)
{
    while (*(volatile int*)0x1000D400 & 0x100)
        ;
}
