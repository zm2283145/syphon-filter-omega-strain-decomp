#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void func_001ADA90(V4* a, V4* b) {
    asm {
        lqc2 vf1, 0x0(b)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0x0(a)
    }
}
