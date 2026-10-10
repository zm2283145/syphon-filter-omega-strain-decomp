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
extern void func_001161A0(void); /* DI */
extern void func_001161F8(void); /* EI */
extern void func_0010D170(int sema);

/* Stops DMA channel 4 (with the DMAC suspended), clears its registers and signals the semaphore. */
int Dma4_Stop(Dev40* self)
{
    func_001161A0();
    DMAC_ENABLEW = DMAC_ENABLER | 0x10000;
    D4_CHCR = 5;
    DMAC_ENABLEW = DMAC_ENABLER & ~0x10000;
    func_001161F8();
    D4_QWC = 0;
    D4_MADR = 0;
    D4_TADR = 0;
    func_0010D170(self->sema);
    return 1;
}
