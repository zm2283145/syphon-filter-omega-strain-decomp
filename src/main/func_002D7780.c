#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004DE510[];
}
union V4_E100 { struct { float x, y, z, w; } f; struct { char c[16]; } s; };
union V2_6250 { struct { float x, y; } f; struct { char c[8]; } s; };
struct Msg2530 { void* vtable; int a, b, c, d, e, f, g; char h; char p1[3]; V2_6250 v; V2_6250 w; unsigned char k; char p2[3]; float x, y, z; };
extern "C" Msg2530* func_002D7780(Msg2530* src)
{
    Msg2530* p;
    {
        AllocGuard guard;
        p = (Msg2530*)Mem_Alloc(0, 0x44, "NetPathMsg.hh", 0x28);
    }
    if (p) {
        p->vtable = D_004DFD80;
        p->a = src->a;
        p->b = src->b;
        p->c = src->c;
        p->d = src->d;
        p->e = src->e;
        p->f = src->f;
        p->g = src->g;
        p->h = src->h;
        p->vtable = D_004DE510;
        p->v = src->v;
        p->w = src->w;
        p->k = src->k;
        p->x = src->x;
        p->y = src->y;
        p->z = src->z;
    }
    return p;
}