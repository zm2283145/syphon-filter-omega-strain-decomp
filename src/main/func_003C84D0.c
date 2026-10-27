#include "types.h"

extern char D_00537F80[];
extern unsigned long long* cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(void* q, int a, int b, int c, int d, int e);
extern void cDmaMan_Kick(void* q, int a);

/* Queues a 64-bit packet built from table[index] | 0x14000000 and flushes it. */
void cVU0Man_RunProg(unsigned int* table, int index) {
    unsigned long long* p = cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(D_00537F80, 0, 1, 0, 0, 1);
    *p = table[index] | 0x14000000;
    cDmaMan_Kick(D_00537F80, 0);
}
