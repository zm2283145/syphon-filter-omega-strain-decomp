#include "types.h"

extern char D_00537F80[];
extern unsigned long long* DmaPacket_Reserve(void* q, int a, int b, int c, int d, int e);
extern void Vif1Packet_Kick(void* q, int a);

/* Queues a 64-bit packet built from table[index] | 0x14000000 and flushes it. */
void cVU0Man_RunProg(unsigned int* table, int index) {
    unsigned long long* p = DmaPacket_Reserve(D_00537F80, 0, 1, 0, 0, 1);
    *p = table[index] | 0x14000000;
    Vif1Packet_Kick(D_00537F80, 0);
}
