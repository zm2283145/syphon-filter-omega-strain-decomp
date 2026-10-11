#include "types.h"
typedef struct { void* p0; int f4; void* p8; unsigned short fC; unsigned short fE; unsigned char f10; char pad11; unsigned short f12; unsigned char f14; } S_00321650;
extern void (*D_004E1D3C)(void* p, int c, int n);
int func_00321650(S_00321650* s)
{
    if (!s) return 0x181A;
    if (!s->p8) return 0x17F2;
    if (!s->p0) return 0x17ED;
    if (!(s->fE < s->fC)) return 0x1801;
    if (!(s->f12 < s->fC)) return 0x1806;
    if (!(s->f10 < 8)) return 0x17F7;
    if (!(s->f14 < 8)) return 0x17FC;
    D_004E1D3C(s->p8, 0, s->fC);
    return 0;
}
