#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004DE260[];
}
union V4_E100 { struct { float x, y, z, w; } f; struct { char c[16]; } s; };
struct Msg2530 { void* vtable; int a, b, c, d, e, f, g; char h; char p1[3]; V4_E100 v; };
extern "C" Msg2530* cNetGeneratorDeleteMsg_Clone(Msg2530* src)
{
    Msg2530* p;
    {
        AllocGuard guard;
        p = (Msg2530*)cMemMan_Allocate(0, 0x34, "NetGeneratorDelete.hh", 0x1A);
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
        p->vtable = D_004DE260;
        p->v = src->v;
    }
    return p;
}