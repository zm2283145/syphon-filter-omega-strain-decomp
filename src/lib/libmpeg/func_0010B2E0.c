#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc), not Metrowerks. */

typedef struct { char pad[0xC8]; int unkC8; char padCC[0xF0 - 0xCC]; unsigned int addr; int width; int height; int size; } Packet;
typedef struct { char pad[0x40]; Packet* packet; } Ctx;
extern void _getpic(Ctx* ctx);

/* Fills the transfer packet (address | 0x20000000, w*16, h*16, w*h) and submits it. */
void sceMpegGetPictureRAW8xy(Ctx* ctx, unsigned int addr, int w, int h)
{
    Packet* p = ctx->packet;
    p->height = h << 4;
    p->addr = (addr & 0x0FFFFFFF) | 0x20000000;
    p->size = w * h;
    p->width = w << 4;
    p->unkC8 = 0;
    _getpic(ctx);
}
