#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "q4_asm_copy.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_0049CB90[];
extern char D_004DFD80[];
extern char D_004D9DA0[];
}
struct M_7E30 { __int128 r0, r1, r2, r3; };
struct Msg_7E30 { void* vtable; int a, b, c, d, e, f, g; char h; char p1[3]; char k; char p2[11]; M_7E30 m; };
/* clone a message: copy fields, swap vtable, 64-byte matrix via the Q4Copy idiom */
#pragma push
#pragma peephole off
extern "C" Msg_7E30* func_00177E30(Msg_7E30* src)
{
    Msg_7E30* p;
    {
        AllocGuard guard;
        p = (Msg_7E30*)Mem_Alloc(0, 0x70, D_0049CB90, 0x4C);
    }
    if (p) {
        M_7E30* d = &p->m;
        M_7E30* s = &src->m;
        p->vtable = D_004DFD80;
        p->a = src->a; p->b = src->b; p->c = src->c; p->d = src->d;
        p->e = src->e; p->f = src->f; p->g = src->g; p->h = src->h;
        p->vtable = D_004D9DA0;
        p->k = src->k;
        Q4Copy(d, s);
    }
    return p;
}
#pragma pop