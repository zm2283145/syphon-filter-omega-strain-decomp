#pragma cplusplus on
#include "types.h"
struct V { float x, y, z, w; } __attribute__((aligned(16)));
struct Phys { char pad[0x10]; V axis; };
static inline float Dot3(V* a, V* b) {
    int rv0;
    float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
static inline void Scale3(V* v, float k) {
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(v)
        mfc1 t, k
        qmtc2.ni t, vf2
        vmulx.xyz vf1, vf1, vf2x
        sqc2 vf1, 0x0(v)
        .set reorder
    }
}
extern "C" void Physical_RetainMotionAxis(Phys* p, V* b);
void Physical_RetainMotionAxis(Phys* p, V* b)
{
    p = (Phys*)&p->axis; V* ax = (V*)p;
    float d = Dot3(b, ax);
    float w = b->w;
    { __int128 q; asm volatile { lq q, 0(ax); sq q, 0(b) } }
    __int128 tt = 0; /* dead: retail's paddub zero */
    b->w = w;
    Scale3(b, d);
}


