#include "types.h"
#include "vu0_addeq.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char p0[0x10]; V4 a; V4 b; char p1[0x10]; V4 c; char p2[0x10]; V4 d; char p3[0x10]; V4 e; } O_0B60;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void func_00180B60(O_0B60* o, V4* v) {
    VU0_ADDEQ1(V4, &o->a, v)
    VU0_ADDEQ2(V4, &o->b, v)
    VU0_ADDEQ2(V4, &o->c, v)
    VU0_ADDEQ1(V4, &o->d, v)
    VU0_ADDEQ1(V4, &o->e, v)
}
#pragma pop