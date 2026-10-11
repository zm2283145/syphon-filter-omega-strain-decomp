#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_7D20;
typedef struct { float x, y, z; float pad; V4_7D20 q10; V4_7D20 q20; } T_7D20;
static inline V4_7D20 Neg_(V4_7D20* q) {
    V4_7D20 r = *q; V4_7D20* p = &r;
    asm {
        lqc2 vf1, 0x0(p)
        vsub.xyz vf1, vf0, vf1
        sqc2 vf1, 0x0(p)
    }
    return *p;
}
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
T_7D20* func_001D7D20(T_7D20* d, T_7D20* s, V4_7D20* q) {
    d->x = s->x; d->y = s->y; d->z = s->z;
    { V4_7D20* t = &d->q10; *t = *q; }
    { V4_7D20 t; V4_7D20* tp; V4_7D20* dp; t = Neg_(q); dp = &d->q20; tp = &t; *dp = *tp; }
    return d;
}
#pragma pop