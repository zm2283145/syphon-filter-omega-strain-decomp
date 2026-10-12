#pragma cplusplus on
#include "types.h"
typedef struct { __int128 q[4]; } M_46E0;
typedef struct { char pad[0x30]; char* p30; } N_46E0;
extern "C" void Weapon_MuzzleFrame(M_46E0* out, void* p, unsigned char f);

extern "C" int func_002D46E0(N_46E0* self, M_46E0* out, int flag)
{
    M_46E0 tmp; int r;
    __int128 qa; __int128 qb; M_46E0* s;
    /* asm { .set reorder } is an empty barrier that keeps the branchy bool (known trick) */
    { unsigned short f; if (flag) { f = 1; asm { .set reorder } } else f = 0; Weapon_MuzzleFrame(&tmp, self->p30 + 0x60, f); }
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