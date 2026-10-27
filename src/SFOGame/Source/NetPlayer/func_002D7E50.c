#pragma cplusplus on
#include "types.h"
typedef struct { __int128 q[4]; } M_7E50;
typedef struct { char pad[0x4C]; char* p30; } N_7E50;
extern "C" void cMan_GetGunBarrelMatrix(M_7E50* out, void* p, unsigned char f);

extern "C" int func_002D7E50(N_7E50* self, M_7E50* out, int flag)
{
    M_7E50 tmp; int r;
    __int128 qa; __int128 qb; M_7E50* s;
    /* asm { .set reorder } is an empty barrier that keeps the branchy bool (known trick) */
    { unsigned short f; if (flag) { f = 1; asm { .set reorder } } else f = 0; cMan_GetGunBarrelMatrix(&tmp, self->p30 + 0x60, f); }
    s = &tmp; r = 1;
    asm {
        .set noreorder
        lq qa, 0x0(s)
        lq qb, 0x10(s)
        sq qa, 0x0(out)
        lq qa, 0x20(s)
        sq qb, 0x10(out)
        lq qb, 0x30(s)
        sq qa, 0x20(out)
        sq qb, 0x30(out)
        .set reorder
    }
    return r;
}