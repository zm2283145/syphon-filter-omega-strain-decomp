#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* func_00132510(V4* a, V4* b) {
    char* pv0 = (char*)a + 0x10;
    asm {
        lqc2 vf1, 0x0(pv0)
        lqc2 vf2, 0x0(b)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(pv0)
    }
    return a;
}
