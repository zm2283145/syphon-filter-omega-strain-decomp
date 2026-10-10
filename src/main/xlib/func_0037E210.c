#include "types.h"
typedef unsigned long long u64_f4;
typedef struct { char pad[0x90]; u64_f4 frame; u64_f4 frameNoMask; u64_f4 zbuf; u64_f4 xyoffset; char padB0[0x20]; unsigned char dirty; } GsTarget_f4;
void func_0037E210(GsTarget_f4* t, unsigned int w, unsigned int h, unsigned int psm, unsigned int fbp,
                   unsigned int fbmsk, unsigned int zpsm, unsigned int zbp, unsigned int zmsk, unsigned char field)
{
    unsigned int ofx = (2048 - (w >> 1)) << 4;
    unsigned int ofy = (2048 - (h >> 1)) << 4;
    u64_f4 lo;
    if (field) {
        ofy += (unsigned char)!(int)((*(volatile u64_f4*)0x12001000 >> 13) & 1) << 3;
    }
    lo = (u64_f4)fbp | ((u64_f4)(w >> 6) << 16) | ((u64_f4)psm << 24);
    t->frame = ((u64_f4)fbmsk << 32) | lo;
    t->frameNoMask = lo | ((u64_f4)0xFFFFFF << 32);
    t->zbuf = (u64_f4)zbp | ((u64_f4)zpsm << 24) | ((u64_f4)zmsk << 32);
    t->xyoffset = (u64_f4)ofx | ((u64_f4)ofy << 32);
    t->dirty = 1;
}