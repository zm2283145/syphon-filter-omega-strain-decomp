/*
 * SFOGame/Source/gameCamera: 5 files, 0017D100-0017D260
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017D100 */
#pragma push /* merge_units */
/* cSplinedMotion::UpdateSplinePoints: on target change rebuild the hermite spline with GetSpeed() as end tangent, else rescale the end tangent into the existing spline. */
#pragma cplusplus on
#pragma inline_depth(8)

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));

static inline void ScaleTo(V* d, const V* v, float k)
{
    int t;
    __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(d), "r"(v), "f"(k) : "memory");
}
static inline void ScaleTo2(V* d, const V* v, float k) { ScaleTo(d, v, k); }
static inline V Scaled(const V& v, float k)
{
    V r;
    ScaleTo2(&r, &v, k);
    return r;
}

static inline void Asg(V* d, const V& s) { *d = s; }
struct Spline {
    char pad0[0x20];
    V a;
    V b;
    float t;
    void Set(const V& na, const V& nb) { V* p = &a; V* q = &a; *q = na; Asg(p + 1, nb); }
};

static inline void SetSc(Spline* s, const V& a, const V& z, float t) { s->Set(a, Scaled(z, t)); }
struct Ref { char pad0[0x40]; float f40; };

struct Cam {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual V GetSpeed();
    char pad4[0x1C];
    V p20;
    V p30;
    V p40;
    char pad50[0x10];
    Spline sp;
    Ref* ref;
    float fB4;
};

extern "C" {
void cHermiteSplineWithScaledDuration_cVector_dtor(void* p, int f);
void* opNew_uint_voidP(int size, void* p);
void cHermiteSplineWithScaledDuration_cVector_ctor_cVectorR_cVectorR_cVectorR_cVectorR_etc(void* p, V* a, V* b, V* c, V* d, float t);
}

extern "C" void cSplinedMotion_cVector_UpdateSplinePoints(Cam* c)
{
    Ref* r = c->ref; bool go = 0; float f = r->f40; bool eq = c->fB4 == f; if (eq && !(c->sp.t <= 0.0f)) go = 1;
    if (go) {
        V z = c->GetSpeed();
        cHermiteSplineWithScaledDuration_cVector_dtor(&c->sp, -1);
        void* p = opNew_uint_voidP(0x50, &c->sp);
        if (p)
            cHermiteSplineWithScaledDuration_cVector_ctor_cVectorR_cVectorR_cVectorR_cVectorR_etc(p, &c->p20, &c->p30, &c->p40, &z, c->sp.t);
    } else {
        bool zf = c->fB4 == 0.0f;
        if ((zf != 0) ^ 1) {
            V z = c->GetSpeed();
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

#include "types.h"

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
