#include "types.h"
typedef struct { char pad[0x830]; int unk830; } Ctx;
extern int D_00485F48[];
/* Writes the address to the IPU/DMA register 0x10002000 and records the segment entry. */
void func_00107718(Ctx* c, unsigned int addr)
{
    *(volatile unsigned int*)0x10002000 = addr;
    c->unk830 = D_00485F48[addr >> 28];
}
