#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma opt_common_subs off
V4 func_001D3A60(V4* b) {
    V4 l0;
    V4* q1 = &l0;
    asm {
        lqc2 vf1, 0x0(b)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0x0(q1)
    }
    return l0;
}
#pragma pop
