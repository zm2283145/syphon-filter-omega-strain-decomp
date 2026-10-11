#include "types.h"
typedef struct { float x; float y; unsigned char c; } A_191040;
typedef struct { int p; int q; } B_191040;
typedef struct { A_191040 a; B_191040 b; } P_191040;
P_191040* func_00191040(P_191040* d, A_191040* a, B_191040* b)
{
    A_191040 t;
    t = *a;
    d->a.x = t.x;
    d->a.y = t.y;
    d->a.c = t.c;
    d->b.p = b->p;
    d->b.q = b->q;
    return d;
}