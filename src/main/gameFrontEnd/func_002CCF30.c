#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004AD1C8[];
extern char D_004DFD80[];
extern char D_004DE200[];
}
struct MsgCF30 { void* vtable; int a, b, c, d, e, f, g; char h; };
extern "C" MsgCF30* func_002CCF30(MsgCF30* src)
{
    MsgCF30* p;
    {
        AllocGuard guard;
        p = (MsgCF30*)Mem_Alloc(0, 0x24, D_004AD1C8, 0x2D);
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
        p->vtable = D_004DE200;
    }
    return p;
}