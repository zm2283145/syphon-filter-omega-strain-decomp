#include "types.h"

/* Retail computes each quadword address separately (peephole pass off). */
#pragma peephole off

typedef struct { Vec4 a; Vec4 b; } VecPair;

static inline Vec4* CopyVec(Vec4* d, Vec4* s)
{
    *d = *s;
    return d;
}

/* Copies a pair of 16-byte vectors; returns the destination. */
VecPair* VecPair_Copy(VecPair* dst, VecPair* src)
{
    CopyVec(&dst->a, &src->a);
    CopyVec(&dst->b, &src->b);
    return dst;
}
