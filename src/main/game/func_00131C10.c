#include "types.h"
typedef struct { __int128 q[4]; } M31C10_;
typedef struct { char pad[0x10]; M31C10_ m; } S31C10_;
#pragma peephole off
void func_00131C10(S31C10_* dst, M31C10_* src)
{
    M31C10_* d = &dst->m;
    __int128 qa, qb;
    qa = src->q[0]; qb = src->q[1];
    d->q[0] = qa; qa = src->q[2];
    d->q[1] = qb; qb = src->q[3];
    d->q[2] = qa;
    d->q[3] = qb;
}
#pragma peephole reset