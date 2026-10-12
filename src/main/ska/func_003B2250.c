#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x180]; V4 v180; } B2250;
#pragma push
#pragma opt_common_subs off
#pragma peephole off
void Bone_AccumTranslation(B2250* b, V4* d, float s) {
    V4* p = &b->v180;
    int t;
    /* VU0: p += d * s (xyz) */
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(d)
        mfc1 t, s
        qmtc2.ni t, vf3
        vaddax.xyz ACC, vf1, vf0x
        vmaddx.xyz vf1, vf2, vf3x
        sqc2 vf1, 0(p)
    }
    b->v180.w = 1.0f;
}
#pragma pop
