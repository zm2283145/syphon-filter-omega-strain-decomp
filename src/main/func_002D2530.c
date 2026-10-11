#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004AD5A8[];
extern char D_004DFD80[];
extern char D_004DE280[];
}
struct Msg2530 { void* vtable; int a, b, c, d, e, f, g; char h; char p1[3]; int i; signed char j; char p2[3]; int k; int l; };
extern "C" Msg2530* func_002D2530(Msg2530* src)
{
    Msg2530* p;
    {
        AllocGuard guard;
        p = (Msg2530*)Mem_Alloc(0, 0x34, D_004AD5A8, 0x2A);
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
        p->vtable = D_004DE280;
        p->i = src->i;
        p->j = src->j;
        p->k = src->k;
        p->l = src->l;
    }
    return p;
}