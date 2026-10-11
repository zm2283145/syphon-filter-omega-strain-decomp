#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void func_0024FC60(V4* a, V4* b, V4* c) {
    asm {
        lqc2 vf8, 0x0(c)
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        lqc2 vf7, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(a)
    }
}
