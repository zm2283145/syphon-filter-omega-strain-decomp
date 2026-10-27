#include "types.h"
#include "prio_bitset.h"
PB_DEFINE(PS_1B75B0, 2)
typedef struct { int a; int b; } Pair_1B75B0;
typedef struct { PS_1B75B0 ps; Pair_1B75B0 q; } O_1B75B0;
static inline int* Second_1B75B0(Pair_1B75B0* q) { return &q->b; }

O_1B75B0* func_001B75B0(O_1B75B0* o, int v)
{
    int i;
    PS_1B75B0* p = &o->ps;
    /* (int) cast stops MW folding &o->q + 4 into one addiu (retail keeps both) */
    int* qb = Second_1B75B0((Pair_1B75B0*)(int)&o->q);
    p->w[0] = 0;
    p->w[1] = 0;
    o->q.a = 0;
    o->q.b = 0;
    PS_1B75B0_Set(p, 0);
    for (i = 1; i < 32U; i++) PS_1B75B0_Clr(p, i);
    PS_1B75B0_Set(p, v);
    PB_FIND_TOP(PS_1B75B0, p, i, 32)
    o->q.a = 0;
    *qb = 0;
    return o;
}

