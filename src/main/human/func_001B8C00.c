#include "types.h"
#pragma cplusplus on
struct V4 {
    float x, y, z, w;
    V4 operator*(float s) const {
        V4 r; int t; V4* q = &r; const V4* v = this;
        asm {
            .set noreorder
            lqc2 vf1, 0x0(v)
            mfc1 t, s
            qmtc2.ni t, vf2
            vmulx.xyzw vf1, vf1, vf2x
            sqc2 vf1, 0x0(q)
            .set reorder
        }
        return *q;
    }
    V4& operator-=(const V4& a) {
        V4* d = this; const V4* p = &a;
        asm {
            lqc2 vf1, 0x0(d)
            lqc2 vf2, 0x0(p)
            vsub.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(d)
        }
        return *this;
    }
} __attribute__((aligned(16)));
static inline float Dot3(const V4* a, const V4* b) {
    int t;
    float r;
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, r
    }
    return r;
}
struct Phys { char p0[0x10]; V4 axis; };
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
extern "C" void Physical_RejectMotionAxis(Phys* p, V4* v) {
    float w = v->w; float d; V4* axis = &p->axis;
    d = Dot3(v, axis); *v -= *axis * d;
    v->w = w;
}



