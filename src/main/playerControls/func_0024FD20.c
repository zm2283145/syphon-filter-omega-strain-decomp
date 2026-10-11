#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void func_0024FD20(V4* a, V4* b, V4* c) {
    asm {
        lqc2 vf8, 0x0(c)
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        sqc2 vf8, 0x0(a)
    }
}
