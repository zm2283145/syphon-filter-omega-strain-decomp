#include "types.h"
typedef struct { char pad[0x830]; int unk830; } Ctx;
const unsigned int D_00485F48[10] = { 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1 };
/* Writes the address to the IPU/DMA register 0x10002000 and records the segment entry. */
void _sendIpuCommand(Ctx* c, unsigned int addr)
{
    *(volatile unsigned int*)0x10002000 = addr;
    c->unk830 = ((int*)D_00485F48)[addr >> 28];
}
