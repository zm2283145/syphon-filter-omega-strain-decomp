#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004DAD40[];
}
struct M1EEDC0 { void* vtable; int w4, w8, wC, w10, w14, w18, w1C; char b20; int w24; };
extern "C" M1EEDC0* cFoundLedgeMsg_Clone(M1EEDC0* self)
{
    M1EEDC0* p;
    {
        AllocGuard guard;
        p = (M1EEDC0*)cMemMan_Allocate(0, 0x28, "foundLedgeMsg.hh", 0x21);
    }
    if (p) {
        p->vtable = D_004DFD80;
        p->w4 = self->w4;
        p->w8 = self->w8;
        p->wC = self->wC;
        p->w10 = self->w10;
        p->w14 = self->w14;
        p->w18 = self->w18;
        p->w1C = self->w1C;
        p->b20 = self->b20;
        p->vtable = D_004DAD40;
        p->w24 = self->w24;
    }
    return p;
}