#include "types.h"
typedef struct { __int128 q[4]; } M36FFD0;
typedef struct { char pad[0x10]; M36FFD0 m; } S36FFD0;
#pragma peephole off
void cXform_SetMatrix_ParentRelative(S36FFD0* dst, M36FFD0* src)
{
    M36FFD0* d = &dst->m;
    __int128 qa, qb;
    qa = src->q[0]; qb = src->q[1];
    d->q[0] = qa; qa = src->q[2];
    d->q[1] = qb; qb = src->q[3];
    d->q[2] = qa;
    d->q[3] = qb;
}
#pragma peephole reset