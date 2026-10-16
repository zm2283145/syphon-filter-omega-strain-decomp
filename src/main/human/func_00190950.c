#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma opt_common_subs off
V4 Vec3_LerpKeepW_190950(V4* b, V4* c, float s) {
    V4 l0;
    V4* q1 = &l0;
    int rv1;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        mfc1 rv1, s
        qmtc2.ni rv1, vf3
        vaddax.xyz ACC, vf1, vf0x
        vmaddax.xyz ACC, vf2, vf3x
        vmsubx.xyz vf1, vf1, vf3x
        sqc2 vf1, 0x0(q1)
    }
    return l0;
}
#pragma pop
