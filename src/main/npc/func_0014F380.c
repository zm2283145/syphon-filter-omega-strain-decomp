#pragma cplusplus on
#include "types.h"
typedef struct { __int128 q[4]; } M_F380;
typedef struct { char pad[0x30]; char* p30; } N_F380;
extern "C" void func_00385240(M_F380* out, void* p, unsigned char f);
extern "C" int cNPC_v17(N_F380* self, M_F380* out, int flag)
{
    M_F380 tmp; int r;
    __int128 qa; __int128 qb; M_F380* s;
    /* asm { .set reorder } is an empty barrier that keeps the branchy bool (known trick) */
    { char* p = self->p30; unsigned short f; if (flag) { f = 1; asm { .set reorder } } else f = 0; { char* q = p + 0x60; func_00385240(&tmp, q, f); } }
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