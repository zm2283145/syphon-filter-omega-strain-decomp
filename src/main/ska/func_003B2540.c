#include "types.h"
typedef struct SkV4 { __int128 q; } SkV4;
typedef struct SkClip { unsigned int type; char p4[0x10]; unsigned char ux, uy, uz; char p17[0x11]; int has; char p2c[4]; SkV4 base; float off[4]; } SkClip;
extern signed char D_004E1D88;
extern SkV4 D_004E1D90;
#pragma peephole off
#pragma opt_propagation off
SkV4 SkaClip_AddBaseline(SkClip* c) {
    if (c->type < 2) {
        if (!D_004E1D88) {
            ((int*)&D_004E1D90)[0] = 0;
            D_004E1D88 = 1;
            ((int*)&D_004E1D90)[1] = 0;
            ((int*)&D_004E1D90)[2] = 0;
            ((int*)&D_004E1D90)[3] = 0;
        }
        return D_004E1D90;
    }
    if (c->type == 2) return c->base;
    {
        SkV4 r; __int128* zp = &r.q; *zp = 0;
        if (c->has) {
            if (c->ux) ((float*)&r)[0] = c->off[0];
            if (c->uy) ((float*)&r)[1] = c->off[1];
            if (c->uz) ((float*)&r)[2] = c->off[2];
        }
        return r;
    }
}
#pragma opt_propagation reset
#pragma peephole reset
