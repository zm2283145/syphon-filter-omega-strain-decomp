#pragma peephole off
#include "types.h"
typedef struct { float v[4]; } __attribute__((aligned(16))) V4D4;
typedef struct { float m[3][4]; V4D4 pos; } MtxD4;
MtxD4* Mtx_FromBasisAndPosition(MtxD4* d, MtxD4* b, V4D4* p)
{
    
    d->m[0][0] = b->m[0][0];
    d->m[0][1] = b->m[0][1];
    d->m[0][2] = b->m[0][2];
    d->m[1][0] = b->m[1][0];
    d->m[1][1] = b->m[1][1];
    d->m[1][2] = b->m[1][2];
    d->m[2][0] = b->m[2][0];
    d->m[2][1] = b->m[2][1];
    d->m[2][2] = b->m[2][2];
    d->m[0][3] = b->m[0][3];
    d->m[1][3] = b->m[1][3];
    d->m[2][3] = b->m[2][3];
    d->pos = *p;
    return d;
}
#pragma peephole reset
