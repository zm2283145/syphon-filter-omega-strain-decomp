#include "types.h"
#include "vu0_quat_rot.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
V4* func_001A90D0(V4* v, V4* qp) {
    V4 u; V4 t;
    V4* d1;
    V4* q2;
    V4* c;
    V4* d2;
    d1 = &t; c = &t; *d1 = *qp;
    VU0_NEG3(c, c)
    d2 = &u; q2 = &u; *d2 = *c;
    VU0_QROT(v, q2, v)
    return v;
}
#pragma pop