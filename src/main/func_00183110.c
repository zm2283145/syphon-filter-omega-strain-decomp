#include "types.h"
typedef struct { float x, y, z, r; } __attribute__((aligned(16))) S_3110;
typedef struct { S_3110 a; S_3110 c; } Sp_3110;
int cSphere_Intersects(Sp_3110* a, Sp_3110* b) {
    int t; float d;
    asm {
        lqc2 vf1, 0x10(a)
        lqc2 vf2, 0x10(b)
        vsub.xyzw vf3, vf2, vf1
        lqc2 vf5, 0x0(a)
        lqc2 vf6, 0x0(b)
        vadd.x vf7, vf5, vf6
        vmul.xyz vf4, vf3, vf3
        vaddw.x vf9, vf0, vf0w
        vmul.x vf8, vf7, vf7
        vmulax.x ACC, vf9, vf4x
        vmadday.x ACC, vf9, vf4y
        vmaddaz.x ACC, vf9, vf4z
        vmsubw.x vf10, vf8, vf0w
        qmfc2.ni t, vf10
    }
    asm { mtc1 t, d }
    if (d <= 0.0f) return 1; return 0;
}