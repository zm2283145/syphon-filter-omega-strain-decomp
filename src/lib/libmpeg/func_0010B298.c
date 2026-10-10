#include "types.h"
typedef struct { char pad[0xC8]; int unkC8; char padCC[0xF0 - 0xCC]; unsigned int addr; int width; int height; int size; } Packet;
typedef struct { char pad[0x40]; Packet* packet; } Ctx;
extern void func_0010B690(Ctx* ctx);
/* Fills the transfer packet with an address (| 0x20000000) and a size, then submits it. */
void func_0010B298(Ctx* ctx, unsigned int addr, int size)
{
    Packet* p = ctx->packet;
    p->size = size;
    p->addr = (addr & 0x0FFFFFFF) | 0x20000000;
    p->unkC8 = 0;
    p->height = 0;
    p->width = 0;
    func_0010B690(ctx);
}
