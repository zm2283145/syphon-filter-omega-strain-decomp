#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x10]; V4 pos; V4 p2; } PS;
static inline void Sub2_(V4* q, V4* a, V4* b) {
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(q)
    }
}
static inline void QCopy_(V4* pd, V4* ps) {
    /* lq into the dead source-pointer register (retail reuses it) */
    asm volatile {
        lq ps, 0(ps)
        sq ps, 0(pd)
    }
}
static inline void AddEq_(V4* x, V4* y) {
    V4* d = x; V4* e = x; V4* p = y;
    asm {
        lqc2 vf1, 0x0(e)
        lqc2 vf2, 0x0(p)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void PhysState_Translate(PS* s, V4* t) {
    V4 u;
    V4 tmp;
    Sub2_(&tmp, t, &s->pos);
    QCopy_(&u, &tmp);
    AddEq_(&s->pos, &u);
    AddEq_(&s->p2, &u);
}
#pragma pop



