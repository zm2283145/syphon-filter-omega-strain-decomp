#pragma push
#pragma optimization_level 1
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 r[4]; } M4_9E20;
typedef struct { char p[0x1B8]; float nearz; } O_9E20;
/* VU0 clip test against the VU0-memory near plane: hand-scheduled block emitted as written */
int Shadow_ClipCode(O_9E20* o, M4_9E20* m, V4* v) {
    int r; float* vm; float n; float z;
    asm {
        .set noreorder
        lqc2 vf5, 0x0(v)
        lqc2 vf1, 0x0(m)
        lqc2 vf2, 0x10(m)
        lqc2 vf3, 0x20(m)
        lqc2 vf4, 0x30(m)
        vmulax.xyzw ACC, vf1, vf5x
        vmadday.xyzw ACC, vf2, vf5y
        vmaddaz.xyzw ACC, vf3, vf5z
        vmaddw.xyzw vf6, vf4, vf5w
        vnop
        vnop
        vnop
        .word 0x4BC631FF
        vsqi.xyzw vf6, (vi0++)
        vnop
        vnop
        vnop
        cfc2.ni r, vi18
    }
    r &= 0x3F;
    vm = (float*)0x11004000;
    z = o->nearz; n = vm[2]; if (!(n < z)) r |= 0x40;
    return r;
}
#pragma pop
