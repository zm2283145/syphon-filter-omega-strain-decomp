#include "types.h"
#include "vu0_quat_rot.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 rot; V4 pos; } P_CCB0;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
P_CCB0* Placement_Invert_17CCB0(P_CCB0* p) {
    float d;
    int t;
    asm {
        lqc2 vf1, 0x0(p)
        lqc2 vf2, 0x0(p)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf3w
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, d
    }
    if (d != 0.0f) {
        VU0_NEG3(p, p)
        {
        float inv;
        __int128 q = 0; /* dead init kept by opt_dead_assignments off: retail's paddub v0,zero,zero */
        inv = 1.0f / d;
        asm {
            .set noreorder
            lqc2 vf1, 0x0(p)
            mfc1 q, inv
            qmtc2.ni q, vf2
            vmulx.xyzw vf1, vf1, vf2x
            sqc2 vf1, 0x0(p)
            .set reorder
        }
        }
    }
    { V4* a; a = &p->pos; VU0_NEG3(a, a) }
    { V4* v; v = &p->pos; VU0_QROT(v, p, v) }
    return p;
}
#pragma pop



