#include "types.h"
typedef struct { float m[3][4]; } R_B160;
typedef struct { __int128 q; } V_B160;
typedef struct { float m[3][4]; V_B160 p; } M_B160;
#pragma peephole off
M_B160* func_0014B160(M_B160* self, R_B160* r, V_B160* p)
{
    self->m[0][0] = r->m[0][0];
    self->m[0][1] = r->m[0][1];
    self->m[0][2] = r->m[0][2];
    self->m[1][0] = r->m[1][0];
    self->m[1][1] = r->m[1][1];
    self->m[1][2] = r->m[1][2];
    self->m[2][0] = r->m[2][0];
    self->m[2][1] = r->m[2][1];
    self->m[2][2] = r->m[2][2];
    self->m[0][3] = r->m[0][3];
    self->m[1][3] = r->m[1][3];
    self->m[2][3] = r->m[2][3];
    self->p = *p;
    return self;
}
#pragma peephole reset