#include "types.h"
typedef struct { __int128 a, b, c, d, e, f; } M_62F0;
M_62F0* func_003C62F0(M_62F0* d, M_62F0* m)
{
    __int128 t0, t1;
    t0 = m->a; t1 = m->b;
    d->a = t0; t0 = m->c;
    d->b = t1; t1 = m->d;
    d->c = t0; t0 = m->e;
    d->d = t1; t1 = m->f;
    d->e = t0;
    d->f = t1;
    return d;
}
