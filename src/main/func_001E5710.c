#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)

/* Placement inverse: out = inverse(in). rot is a quaternion, pos a vector. */

struct V { float x, y, z, w; } __attribute__((aligned(16)));

/* 16-byte quad copy (lq/sq have no C equivalent). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct Plc {
    V rot, pos;
    Plc() {}
    /* The unused xx keeps retail's dead address addiu between the two copies. */
    Plc(const Plc& o) { V* d = &rot; Q16(d, &o.rot); void* xx = this; Q16(&pos, &o.pos); }
    Plc& operator=(const Plc& o) { Q16(&rot, &o.rot); Q16(&pos, &o.pos); return *this; }
};

static inline float Dot4(V* a, V* b) {
    int rv0;
    float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf3w
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
static inline void Neg3(V* v) { asm { lqc2 vf1, 0x0(v); vsub.xyz vf1, vf0, vf1; sqc2 vf1, 0x0(v) } }
/* GCC-style form: keeps retail's re-materialised &pos for the rotate below. */
static inline void NegG(V* v) { __asm__ volatile("lqc2 vf1, 0x0(%0); vsub.xyz vf1, vf0, vf1; sqc2 vf1, 0x0(%0)" : : "r"(v) : "memory"); }
static inline void Scale(V* v, float k) {
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(v)
        mfc1 t, k
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(v)
        .set reorder
    }
}
static inline void QRot(V* v, V* q) {
    asm {
        lqc2 vf1, 0x0(v)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(q)
        vmove.w vf3, vf2
        vsub.xyz vf3, vf0, vf2
        vmul.xyzw vf4, vf2, vf1
        vopmula.xyz ACC, vf2, vf1
        vmaddaw.xyz ACC, vf1, vf2w
        vopmsub.xyz vf5, vf1, vf2
        vsubaz.w ACC, vf4, vf4z
        vmsubay.w ACC, vf0, vf4y
        vmsubx.w vf5, vf0, vf4x
        vopmula.xyz ACC, vf5, vf3
        vmaddaw.xyz ACC, vf5, vf3w
        vmaddaw.xyz ACC, vf3, vf5w
        vopmsub.xyz vf6, vf3, vf5
        sqc2 vf6, 0x0(v)
    }
}

extern "C" void Placement_Invert_1E5710(Plc* o, Plc* in);
void Placement_Invert_1E5710(Plc* o, Plc* in)
{
    Plc t = *in;
    Plc* a = &t;
    float d = Dot4(&a->rot, &a->rot);
    if (d != 0.0f) {
        Neg3(&a->rot);
        __int128 tt = 0; /* dead paddub */
        Scale(&a->rot, 1.0f / d);
    }
    NegG(&a->pos);
    QRot(&a->pos, &a->rot);
    *o = *a;
}
