#include "types.h"
typedef struct { __int128 q[4]; } MBA730_;
typedef struct { char pad[0xD0]; MBA730_ m; } SBA730_;
#pragma peephole off
void SkelNode_SetInverseBind(SBA730_* dst, MBA730_* src)
{
    MBA730_* d = &dst->m;
    __int128 qa, qb;
    qa = src->q[0]; qb = src->q[1];
    d->q[0] = qa; qa = src->q[2];
    d->q[1] = qb; qb = src->q[3];
    d->q[2] = qa;
    d->q[3] = qb;
}
#pragma peephole reset