#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void Vec4_Scale_1E5920(V4* a, V4* b, float s) {
    int rv1;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(b)
        mfc1 rv1, s
        qmtc2.ni rv1, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(a)
        .set reorder
    }
}
