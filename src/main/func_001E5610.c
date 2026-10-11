#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* Vec4_Add_1E5610(V4* a, V4* b) {
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(a)
    }
    return a;
}
