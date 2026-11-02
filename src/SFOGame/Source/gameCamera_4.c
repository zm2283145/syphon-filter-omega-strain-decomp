/*
 * SFOGame/Source/gameCamera: 8 files, 0017CEE0-0017D100
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017CEE0 */
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
extern "C" V cHermiteSpline_cVector_Evaluate(const HS* s, float u)
{
    return s->Evaluate(u);
}
static inline void merge_flush_func_0017CEE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017CEE0 */

/* merge_units: begin func_0017D070 */
#pragma push /* merge_units */
#include "types.h"
#include "curve_count_down.h"

typedef struct { char pad[0xB4]; float fB4; } S17D070;
int cSplinedMotion_cVector_IsTransitionInProgress(S17D070* s) {
    return !(s->fB4 == 0.0f);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017D070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017D070 */

/* merge_units: begin func_0017D0A0 */
#pragma push /* merge_units */
/* Count a curve's remaining time down to zero. */
DEFINE_CURVE_COUNT_DOWN(cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_NextFrame)
static inline void merge_flush_func_0017D0A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017D0A0 */

/* merge_units: begin func_0017D100 */
#pragma push /* merge_units */
/* cSplinedMotion::UpdateSplinePoints: on target change rebuild the hermite spline with GetSpeed() as end tangent, else rescale the end tangent into the existing spline. */
#pragma cplusplus on
#pragma inline_depth(8)

struct V_0017D100 {
    float x, y, z, w;
    V_0017D100() {}
    V_0017D100(const V_0017D100& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V_0017D100& operator=(const V_0017D100& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));

static inline void ScaleTo_0017D100(V_0017D100* d, const V_0017D100* v, float k)
{
    int t;
    __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(d), "r"(v), "f"(k) : "memory");
}
static inline void ScaleTo2(V_0017D100* d, const V_0017D100* v, float k) { ScaleTo_0017D100(d, v, k); }
static inline V_0017D100 Scaled_0017D100(const V_0017D100& v, float k)
{
    V_0017D100 r;
    ScaleTo2(&r, &v, k);
    return r;
}

static inline void Asg(V_0017D100* d, const V_0017D100& s) { *d = s; }
struct Spline {
    char pad0[0x20];
    V_0017D100 a;
    V_0017D100 b;
    float t;
    void Set(const V_0017D100& na, const V_0017D100& nb) { V_0017D100* p = &a; V_0017D100* q = &a; *q = na; Asg(p + 1, nb); }
};

static inline void SetSc(Spline* s, const V_0017D100& a, const V_0017D100& z, float t) { s->Set(a, Scaled_0017D100(z, t)); }
struct Ref { char pad0[0x40]; float f40; };

struct Cam {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual V_0017D100 GetSpeed();
    char pad4[0x1C];
    V_0017D100 p20;
    V_0017D100 p30;
    V_0017D100 p40;
    char pad50[0x10];
    Spline sp;
    Ref* ref;
    float fB4;
};

extern "C" {
void cHermiteSplineWithScaledDuration_cVector_dtor(void* p, int f);
void* opNew_uint_voidP(int size, void* p);
void cHermiteSplineWithScaledDuration_cVector_ctor_cVectorR_cVectorR_cVectorR_cVectorR_etc(void* p, V_0017D100* a, V_0017D100* b, V_0017D100* c, V_0017D100* d, float t);
}

extern "C" void cSplinedMotion_cVector_UpdateSplinePoints(Cam* c)
{
    Ref* r = c->ref; bool go = 0; float f = r->f40; bool eq = c->fB4 == f; if (eq && !(c->sp.t <= 0.0f)) go = 1;
    if (go) {
        V_0017D100 z = c->GetSpeed();
        cHermiteSplineWithScaledDuration_cVector_dtor(&c->sp, -1);
        void* p = opNew_uint_voidP(0x50, &c->sp);
        if (p)
            cHermiteSplineWithScaledDuration_cVector_ctor_cVectorR_cVectorR_cVectorR_cVectorR_etc(p, &c->p20, &c->p30, &c->p40, &z, c->sp.t);
    } else {
        bool zf = c->fB4 == 0.0f;
        if ((zf != 0) ^ 1) {
            V_0017D100 z = c->GetSpeed();
            SetSc(&c->sp, c->p40, z, c->sp.t);
        }
    }
}
static inline void merge_flush_func_0017D100(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017D100 */

/* merge_units: begin func_0017D260 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Address of 32-byte element i. */
char* cHermiteSpline_cVector_ControlPoint(char* base, int i) {
    return base + (i << 5);
}
static inline void merge_flush_func_0017D260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017D260 */

/* merge_units: begin func_0017D270 */
#pragma push /* merge_units */
/* cSplinedMotion_cQuaternion_UpdateVelocity: rate = (b - a) * k; rate *= max(0, 1 - damp * dt). Hand-matched (auto1 family seed).
 * The empty `.set noreorder/.set reorder` asm blocks are scheduling barriers that reproduce retail instruction order. */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x10]; V4 a; V4 b; V4 rate; char pad40[0x10]; float damp; } CR_t;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
static inline float CR_Max(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }
void cSplinedMotion_cQuaternion_UpdateVelocity(CR_t* c, float dt, float k) {
    V4 u; V4 t; V4 s; V4 d; V4* q;
    {
        V4* q = &d; V4* x = &c->b; V4* y;
        asm { .set noreorder; .set reorder }
        y = &c->a;
        asm { lqc2 vf1, 0x0(x); lqc2 vf2, 0x0(y); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(q) }
    }
    {
        __int128 tt = 0; V4* p; V4* ss = &d; V4* dd = &t;
        *dd = *ss; p = &t; q = &s;
        asm { .set noreorder; lqc2 vf1, 0x0(p); mfc1 tt, k; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(q); .set reorder }
    }
    {
        V4* d2; V4* ss; V4* d1 = &u;
        asm { .set noreorder; .set reorder }
        *d1 = *q; ss = &u; d2 = &c->rate; *d2 = *ss;
    }
    {
        float f = CR_Max(0.0f, 1.0f - c->damp * dt); __int128 tt = 0; V4* q = &c->rate; V4* p = &c->rate;
        asm { .set noreorder; lqc2 vf1, 0x0(p); mfc1 tt, f; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(q); .set reorder }
    }
}
#pragma pop
static inline void merge_flush_func_0017D270(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017D270 */

/* merge_units: begin func_0017D330 */
#pragma push /* merge_units */
void cSplinedMotion_cQuaternion_FixUpResultOfSplineEvaluation(void) {
}
static inline void merge_flush_func_0017D330(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017D330 */

/* merge_units: begin func_0017D340 */
#pragma push /* merge_units */
typedef struct { char pad[0x40]; float f40; float f44; } A2C17D;
typedef struct { A2C17D* c; float t; } A2S17D;
extern void cHermiteSpline_cQuaternion_Evaluate(void* a, A2C17D* c, float v);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_Evaluate(void* a, A2S17D* s) {
    A2C17D* c = s->c;
    float d = c->f40 - s->t;
    float v;
    if (c->f40 != 0.0f) v = d * c->f44;
    else v = 1.0f;
    cHermiteSpline_cQuaternion_Evaluate(a, c, v);
}
static inline void merge_flush_func_0017D340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017D340 */
