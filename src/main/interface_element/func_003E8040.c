#include "types.h"
typedef struct { __int128 a, b, c, d; } M_8040;
typedef struct { char pad[0x30]; M_8040 m; } S_8040;
#pragma peephole off
void func_003E8040(S_8040* s, M_8040* m)
{
    M_8040* d = &s->m;
    __int128 t0, t1;
    t0 = m->a; t1 = m->b;
    d->a = t0; t0 = m->c;
    d->b = t1; t1 = m->d;
    d->c = t0;
    d->d = t1;
}
#pragma peephole reset