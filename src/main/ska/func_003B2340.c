#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void Bone_AccumQuat(V4* a, V4* b, float s) {
    int rv1;
    a = (V4*)((char*)a + 0x190);
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        mfc1 rv1, s
        qmtc2.ni rv1, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddx.xyzw vf1, vf2, vf3x
        sqc2 vf1, 0x0(a)
    }
}
