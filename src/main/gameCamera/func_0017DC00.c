#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4 func_0017DC00(V4* b, float s) {
    V4 l0;
    V4* q1 = &l0;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(b)
        mfc1 b, s
        qmtc2.ni b, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(q1)
        .set reorder
    }
    return l0;
}
