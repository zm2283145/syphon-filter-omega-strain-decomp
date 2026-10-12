#include "types.h"
typedef struct { __int128 a; __int128 b; signed char f; } Seg_B850;
typedef struct { Seg_B850 s0; Seg_B850 s1; } T_B850;
#pragma push
#pragma peephole off
#pragma opt_propagation off

T_B850* func_001DB850(T_B850* d, T_B850* s)
{
    __int128 q0; __int128 t;
    __int128 *s1, *d1, *s2, *d2, *s3, *d3;
    q0 = s->s0.a;
d1 = &d->s0.b;
s1 = &s->s0.b;
d2 = &d->s1.a; s2 = &s->s1.a; d3 = &d->s1.b; s3 = &s->s1.b;
    d->s0.a = q0;
    t = *s1; *d1 = t;
    d->s0.f = s->s0.f;
    t = *s2; *d2 = t;
    t = *s3; *d3 = t;
    d->s1.f = s->s1.f;
    return d;
}
#pragma pop
