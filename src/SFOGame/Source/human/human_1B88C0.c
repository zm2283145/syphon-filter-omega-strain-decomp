/*
 * main/human: range (10 files, 001B88C0-001B8E40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001B88C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
typedef struct { char pad[0x10]; float f10; } Tgt;
typedef struct {
    char pad0[8];
    float f8;
    float fC;
    float f10;
    char pad14[4];
    char a18[8];
    float f20;
    float f24;
    float f28;
    char pad2C[4];
    Tgt* p30;
    float f34;
} AC;
extern "C" {
extern float D_0048A1B0;
extern char D_0048A1A8;
extern void func_0017CA90(void*, int);
extern void* opNew_uint_voidP(int, void*);
extern void cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_floatR_floatR_etc(void*, float*, float*, float*, void*, float);
}
static inline bool Gt(float a, float b) { return a > b; }
static inline bool Eq(float a, float b) { return a == b; }
static inline void Set2(float* q, float a, float b) { q[0] = a; q[1] = b; }
static inline float WrapPi(float a)
{
    for (;;) {
        if (Gt(a, 3.1415927f)) { a += -6.2831855f; continue; }
        if (a < -3.1415927f) { a += 6.2831855f; continue; }
        break;
    }
    return a;
}

extern "C" void cSplinedMotion_Angle_UpdateSplinePoints(AC* c)
{
    bool go = 0;
    if (c->f34 == c->p30->f10 && c->f28 > 0.0f) go = 1;
    if (go) {
        void* v;
        c->f10 = c->f8 + WrapPi(c->f10 - c->f8);
        func_0017CA90(c->a18, -1);
        v = opNew_uint_voidP(0x18, c->a18);
        if (v) cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_floatR_floatR_etc(v, &c->f8, &c->fC, &c->f10, &D_0048A1A8, c->f28);
    } else {
        bool ne = !Eq(0.0f, c->f34);
        if (ne) {
            float* q = &c->f20;
            float base = c->f20;
            float d = WrapPi(c->f10 - base);
            c->f10 = base + d;
            Set2(q, c->f10, D_0048A1B0 * c->f28);
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_001B88C0 */

/* merge_units: begin func_001B8AC0 */
#pragma push /* merge_units */
typedef struct { int a, b; float ang; } S1B8;
static inline int Gt1B8(float a, float b) { return a > b; }
void cSplinedMotion_Angle_FixUpResultOfSplineEvaluation(S1B8* s) {
    float a = s->ang;
    for (;;) {
        if (Gt1B8(a, 3.1415927f)) { a += -6.2831855f; continue; }
        if (a < -3.1415927f) { a += 6.2831855f; continue; }
        break;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_001B8AC0 */

/* merge_units: begin func_001B8B40 */
#pragma push /* merge_units */
typedef struct { int pad0; float a; float b; float rate; int pad10; float damp; } AC_t;
static inline float AC_Max(float a, float b) {
    float r;
    asm { max.s r, a, b }
    return r;
}
void cSplinedMotion_Angle_UpdateVelocity(AC_t* p, float dt, float k) {
    float d = p->b - p->a;
    while (1) {
        if (d > 3.1415927f) d += -6.2831855f;
        else if (d < -3.1415927f) d += 6.2831855f;
        else break;
    }
    p->rate = k * d;
    p->rate *= AC_Max(0.0f, 1.0f - p->damp * dt);
}
#pragma pop /* merge_units */
/* merge_units: end func_001B8B40 */

/* merge_units: begin func_001B8C00 */
#pragma push /* merge_units */
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
extern "C" void cHumanCollision_DeltaPosModificationFunction_Floor_Execute(Phys* p, V4* v) {
    float w = v->w; float d; V4* axis = &p->axis;
    d = Dot3(v, axis); *v -= *axis * d;
    v->w = w;
}
#pragma pop /* merge_units */
/* merge_units: end func_001B8C00 */

/* merge_units: begin func_001B8C80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR2(cHumanCollision_DeltaPosModificationFunction_Floor_dtor, D_004DA800, D_004DA810)
#pragma pop /* merge_units */
/* merge_units: end func_001B8C80 */

/* merge_units: begin func_001B8CE0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR1(cSkaAnimAnchor_cDeltaPosModificationFunction_dtor, D_004DA810)
#pragma pop /* merge_units */
/* merge_units: end func_001B8CE0 */

/* merge_units: begin func_001B8D30 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V { float x, y, z, w; } __attribute__((aligned(16)));
struct Phys_001B8D30 { char pad[0x10]; V axis; };
static inline float Dot3_001B8D30(V* a, V* b) {
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
extern "C" void cHumanCollision_DeltaPosModificationFunction_Ledge_Execute(Phys_001B8D30* p, V* b);
void cHumanCollision_DeltaPosModificationFunction_Ledge_Execute(Phys_001B8D30* p, V* b)
{
    p = (Phys_001B8D30*)&p->axis; V* ax = (V*)p;
    float d = Dot3_001B8D30(b, ax);
    float w = b->w;
    { __int128 q; asm volatile { lq q, 0(ax); sq q, 0(b) } }
    __int128 tt = 0; /* dead: retail's paddub zero */
    b->w = w;
    Scale3(b, d);
}
#pragma pop /* merge_units */
/* merge_units: end func_001B8D30 */

/* merge_units: begin func_001B8D90 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR2(cHumanCollision_DeltaPosModificationFunction_Ledge_dtor, D_004DA820, D_004DA810)
#pragma pop /* merge_units */
/* merge_units: end func_001B8D90 */

/* merge_units: begin func_001B8DF0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR1(cIkRoutine_dtor_void, D_004DA830)
#pragma pop /* merge_units */
/* merge_units: end func_001B8DF0 */

/* merge_units: begin func_001B8E40 */
#pragma push /* merge_units */
#pragma opt_common_subs off
#pragma opt_propagation off
extern float Libc_Fmodf(float, float);
static inline float clamp_(float a, float lo, float hi) { asm { max.s lo, a, lo
 min.s lo, lo, hi } return lo; }
typedef struct {
    char pad0[4];
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    char pad24[4];
    float f28;
    char pad2C[0x38 - 0x2C];
    unsigned char b38;
} Ch;
extern char D_0048A190;

static inline float Clamp(Ch* c, float x)
{
    float v;
    if (!c->b38) {
        v = clamp_(x, 0.0f, 1.0f);
    } else {
        v = Libc_Fmodf(x, 1.0f);
        if (v < 0.0f) v += 1.0f;
    }
    return v;
}
static inline float Wrap(Ch* p, float d)
{
    float r;
    float h;
    if (!p->b38) {
        return d;
    }
    r = Libc_Fmodf(d, 1.0f);
    h = 0.5f;
    if (r < h) {
        r += 1.0f;
    } else if (r > h) {
        r -= 1.0f;
    }
    return r;
}

void cSplinedMotion_Scalar0To1_TeleportByDelta(Ch* c, float* dt)
{
    void* v;
    c->f4 += *dt;
    c->f8 += *dt;
    c->f10 += *dt;
    c->f18 += *dt;
    c->f20 += *dt;
    c->f4 = Clamp(c, c->f4);
    c->f8 = Clamp(c, c->f8);
    c->f10 = c->f8 + Wrap(c, c->f10 - c->f8);
    func_0017CA90(&c->f18, -1);
    v = opNew_uint_voidP(0x18, &c->f18);
    if (v) cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_floatR_floatR_etc(v, &c->f8, &c->fC, &c->f10, &D_0048A190, c->f28);
}
#pragma pop /* merge_units */
/* merge_units: end func_001B8E40 */
