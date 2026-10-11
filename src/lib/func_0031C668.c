#include "types.h"
typedef struct { long magic; char pad08[0x10]; unsigned char state; char pad19[3]; char f1C[0x14]; void* p30; void* p34; } Handle_0031C668;
extern unsigned short D_004E1D4C;
extern void (*D_004E1D38)(void*);
extern void func_00317AC0(void* p);
int func_0031C668(Handle_0031C668** pp)
{
    Handle_0031C668* h;
    if (!pp) return 0x181A;
    if (!*pp || (*pp)->magic != 0xFACE) return 0x17D4;
    if ((*pp)->state != 10) return 0x17E3;
    D_004E1D4C--;
    h = *pp;
    h->magic = 0;
    func_00317AC0(h->f1C);
    if (h->p30) { D_004E1D38(h->p30); h->p30 = 0; }
    if (h->p34) { D_004E1D38(h->p34); h->p34 = 0; }
    D_004E1D38(h);
    *pp = 0;
    return 0;
}
