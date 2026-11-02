/*
 * SFOGame/Source/gameCamera: 4 files, 0017D380-0017D5A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017D380 */
#pragma push /* merge_units */
/* cHermiteSpline::Evaluate(u): Hermite basis h0..h3 times P0, P1, T0, T1 summed with by-value operator+; product temps one inline level deeper (Scaled) to get retail's stack layout. */
#pragma cplusplus on
#pragma exceptions off
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; __int128 t; const V* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
    V operator*(float k) const;
} __attribute__((aligned(16)));
static inline void ScaleTo(V* d, const V* s, float k) { __int128 r = 0; V* dd = d; asm {
        .set noreorder
        lqc2 vf1, 0x0(s)
        mfc1 r, k
        qmtc2.ni r, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(dd)
        .set reorder
    } }
static inline V Scaled(const V& v, float k) { V t; ScaleTo(&t, &v, k); return t; } inline V V::operator*(float k) const { return Scaled(*this, k); }
static inline void AddTo(V* d, const V* a, const V* b) { asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    } }
static inline V operator+(V a, V b) { V t; const V* pa = &a; AddTo(&t, pa, &b); return t; }
struct CP {
    V position;
    V tangent;
    CP() {}
};
struct Arr { CP d[2]; const CP& operator[](int i) const { return d[i]; } };
struct HS {
    Arr mPoints;
    V Evaluate(float u) const;
};
inline V HS::Evaluate(float u) const
{
    float uSquared = u * u;
    float uCubed = uSquared * u;
    float h0 = 1.0f + (2.0f * uCubed - 3.0f * uSquared);
    float h1 = -2.0f * uCubed + 3.0f * uSquared;
    float h2 = u + (uCubed - 2.0f * uSquared);
    float h3 = uCubed - uSquared;
    return mPoints[0].position * h0 + mPoints[1].position * h1 + mPoints[0].tangent * h2 + mPoints[1].tangent * h3;
}
extern "C" V cHermiteSpline_cQuaternion_Evaluate(const HS* s, float u)
{
    return s->Evaluate(u);
}
static inline void merge_flush_func_0017D380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017D380 */

/* merge_units: begin func_0017D510 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char pad[0xB4]; float fB4; } A1_S;
int func_0017D510(A1_S* o) {
    return !(o->fB4 == 0.0f);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017D510(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017D510 */

/* merge_units: begin func_0017D540 */
#pragma push /* merge_units */
typedef struct { int pad0; float v; } F17D540_t;
static inline float F17D540_Max(float a, float b) {
    float r;
    asm {
        mov.s r, a
        max.s r, b, r
    }
    return r;
}
int cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_NextFrame(F17D540_t* p, float dt) {
    float old = p->v;
    p->v -= dt;
    p->v = F17D540_Max(p->v, 0.0f);
    return old > 0.0f && p->v == 0.0f;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017D540(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017D540 */

/* merge_units: begin func_0017D5A0 */
#pragma push /* merge_units */
/* cSplinedMotion::UpdateSplinePoints: on target change rebuild the hermite spline with GetSpeed() as end tangent, else rescale the end tangent into the existing spline. */
#pragma cplusplus on
#pragma inline_depth(8)

struct V_0017D5A0 {
    float x, y, z, w;
    V_0017D5A0() {}
    V_0017D5A0(const V_0017D5A0& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V_0017D5A0& operator=(const V_0017D5A0& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));

static inline void ScaleTo_0017D5A0(V_0017D5A0* d, const V_0017D5A0* v, float k)
{
    int t;
    __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(d), "r"(v), "f"(k) : "memory");
}
static inline void ScaleTo2(V_0017D5A0* d, const V_0017D5A0* v, float k) { ScaleTo_0017D5A0(d, v, k); }
static inline V_0017D5A0 Scaled_0017D5A0(const V_0017D5A0& v, float k)
{
    V_0017D5A0 r;
    ScaleTo2(&r, &v, k);
    return r;
}

static inline void Asg(V_0017D5A0* d, const V_0017D5A0& s) { *d = s; }
struct Spline {
    char pad0[0x20];
    V_0017D5A0 a;
    V_0017D5A0 b;
    float t;
    void Set(const V_0017D5A0& na, const V_0017D5A0& nb) { V_0017D5A0* p = &a; V_0017D5A0* q = &a; *q = na; Asg(p + 1, nb); }
};

static inline void SetSc(Spline* s, const V_0017D5A0& a, const V_0017D5A0& z, float t) { s->Set(a, Scaled_0017D5A0(z, t)); }
struct Ref { char pad0[0x40]; float f40; };

struct Cam {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual V_0017D5A0 GetSpeed();
    char pad4[0x1C];
    V_0017D5A0 p20;
    V_0017D5A0 p30;
    V_0017D5A0 p40;
    char pad50[0x10];
    Spline sp;
    Ref* ref;
    float fB4;
};

extern "C" {
void cHermiteSplineWithScaledDuration_float_dtor(void* p, int f);
void* opNew_uint_voidP(int size, void* p);
void cHermiteSplineWithScaledDuration_cQuaternion_ctor(void* p, V_0017D5A0* a, V_0017D5A0* b, V_0017D5A0* c, V_0017D5A0* d, float t);
}

extern "C" void cSplinedMotion_cQuaternion_UpdateSplinePoints(Cam* c)
{
    Ref* r = c->ref; bool go = 0; float f = r->f40; bool eq = c->fB4 == f; if (eq && !(c->sp.t <= 0.0f)) go = 1;
    if (go) {
        V_0017D5A0 z = c->GetSpeed();
        cHermiteSplineWithScaledDuration_float_dtor(&c->sp, -1);
        void* p = opNew_uint_voidP(0x50, &c->sp);
        if (p)
            cHermiteSplineWithScaledDuration_cQuaternion_ctor(p, &c->p20, &c->p30, &c->p40, &z, c->sp.t);
    } else {
        bool zf = c->fB4 == 0.0f;
        if ((zf != 0) ^ 1) {
            V_0017D5A0 z = c->GetSpeed();
            SetSc(&c->sp, c->p40, z, c->sp.t);
        }
    }
}
static inline void merge_flush_func_0017D5A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017D5A0 */
