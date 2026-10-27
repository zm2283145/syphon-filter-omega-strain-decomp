#include "types.h"

/* Retail code re-materializes each register address (no common-subexpression elimination). */
#pragma opt_common_subs off

#define DMAC_ENABLER (*(volatile unsigned int*)0x1000F520)
#define DMAC_ENABLEW (*(volatile unsigned int*)0x1000F590)
#define D4_CHCR      (*(volatile unsigned int*)0x1000B400)
#define D4_MADR      (*(volatile unsigned int*)0x1000B410)
#define D4_QWC       (*(volatile unsigned int*)0x1000B420)
#define D4_TADR      (*(volatile unsigned int*)0x1000B430)

typedef struct { char pad[0x40]; int sema; } Dev40;
extern void DIntr(void); /* DI */
extern void EIntr(void); /* EI */
extern void DeleteSema(int sema);

/* Stops DMA channel 4 (with the DMAC suspended), clears its registers and signals the semaphore. */
int viBufDelete(Dev40* self)
{
    DIntr();
    DMAC_ENABLEW = DMAC_ENABLER | 0x10000;
    D4_CHCR = 5;
    DMAC_ENABLEW = DMAC_ENABLER & ~0x10000;
    EIntr();
    D4_QWC = 0;
    D4_MADR = 0;
    D4_TADR = 0;
    DeleteSema(self->sema);
    return 1;
}
