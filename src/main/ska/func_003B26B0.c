#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void Vec3_LerpKeepW(V4* a, V4* b, V4* c, V4* d, V4* e) {
    asm {
        lqc2 vf1, 0x0(c)
        lqc2 vf2, 0x0(d)
        lqc2 vf3, 0x0(e)
        vmulax.xyz ACC, vf2, vf3x
        vmaddy.xyz vf4, vf1, vf3y
        vaddx.w vf4, vf1, vf0x
        sqc2 vf4, 0x0(b)
    }
}
