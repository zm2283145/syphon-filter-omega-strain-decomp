/*
 * SFOGame/Source/gameCamera: 5 files, 0017D700-0017D7F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017D700 */
#pragma push /* merge_units */
/* cHermiteSplineWithScaledDuration<cQuaternion>(p0, v0, p1, v1, duration): base cHermiteSpline(p0, v0*duration, p1, v1*duration), then duration and its inverse. */
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
inline V V::operator*(float k) const { V t; ScaleTo(&t, this, k); return t; }
struct CP {
    V position;
    V tangent;
    CP() {}
};
struct Arr { CP d[2]; CP& operator[](int i) { return d[i]; } };
struct HSD {
    Arr mPoints;
    float mDuration;
    float mOneOverDuration;
};
static inline void HS_ctor(HSD* p, const V& p0, V v0, const V& p1, V v1)
{
    {
        CP* q = p->mPoints.d;
        do { q++; } while (q != p->mPoints.d + 2);
    }
    p->mPoints[0].position = p0;
    p->mPoints[0].tangent = v0;
    p->mPoints[1].position = p1;
    p->mPoints[1].tangent = v1;
}
extern "C" HSD* cHermiteSplineWithScaledDuration_cQuaternion_ctor(HSD* p, const V* p0, const V* v0, const V* p1, const V* v1, float duration)
{
    HS_ctor(p, *p0, *v0 * duration, *p1, *v1 * duration);
    p->mDuration = duration;
    p->mOneOverDuration = (duration != 0.0f) ? 1.0f / duration : 0.0f;
    return p;
}
static inline void merge_flush_func_0017D700(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017D700 */

/* merge_units: begin func_0017D7F0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cHermiteSplineWithScaledDuration_float_dtor)
static inline void merge_flush_func_0017D7F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017D7F0 */

/* merge_units: begin func_0017D840 */
#pragma push /* merge_units */
#include "types.h"
#include "vu0_scale_eq.h"
#pragma push
#pragma peephole off
#pragma opt_propagation off
CURVE_RETIME_FUNC(cSplinedMotion_cQuaternion_RestartTransition)
#pragma pop
static inline void merge_flush_func_0017D840(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017D840 */

/* merge_units: begin func_0017D8E0 */
#pragma push /* merge_units */
void cHermiteSplineWithScaledDuration_cVector_Evaluate(char* arg0, char* arg1, float farg0); /* gsynth: defined below */
#pragma cplusplus on
struct V_0017D8E0 {
    float x, y, z, w;
    V_0017D8E0() {}
    V_0017D8E0(const V_0017D8E0& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V_0017D8E0& operator=(const V_0017D8E0& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct W {
    float x, y, z, w;
    W() {}
    W& operator=(const W& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
extern "C" float cHermiteSplineWithScaledDuration_cVector_Duration(void* c);
#if 0 /* merge_units */
extern "C" void cHermiteSplineWithScaledDuration_cVector_Evaluate(V_0017D8E0* out, void* c, float t);
#endif /* merge_units */
extern "C" void cHermiteSplineWithScaledDuration_cVector_Evaluate(char* arg0, char* arg1, float farg0); /* merge_units */
#define cHermiteSplineWithScaledDuration_cVector_Evaluate(a0, a1, a2) (cHermiteSplineWithScaledDuration_cVector_Evaluate((char *)(a0), (char *)(a1), (a2))) /* merge_units */


static inline float CR_Max(float a, float b) { float r; asm { max.s r, a, b } return r; }
static inline bool Pos(float f) { return f > 0.0f; }
struct VC {
    /* vptr at 0; slots 0x18/0x1C/0x20 */
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void Begin();
    virtual void Changed();
    virtual void Update(float dt, float x);
    char pad4[0xC];
    W v10;
    W v20;
    char pad30[0x10];
    W v40;
    char pad50[0x60];
    void* curve;
    float t;
    bool Zero() const { return t == 0.0f; }
    bool NotZero() const { return !Zero(); }
};
extern "C" bool cSplinedMotion_cVector_NextFrame(VC* self, float dt, float x)
{
    bool done;
    self->v10 = self->v20;
    self->Begin();
    float z = 0.0f; /* dead on purpose: retail keeps this mtc1 */
    float old = self->t;
    self->t -= dt;
    self->t = CR_Max(0.0f, self->t);
    {
        bool r = Pos(old);
        if (r) r = self->Zero();
        done = r;
    }
    if (self->NotZero()) {
        V_0017D8E0 tmp;
        cHermiteSplineWithScaledDuration_cVector_Evaluate(&tmp, self->curve, cHermiteSplineWithScaledDuration_cVector_Duration(self->curve) - self->t);
        { void* xx = &tmp; /* dead on purpose: retail keeps this addiu */ }
        self->v20 = (W&)tmp;
        self->Changed();
    } else {
        self->v20 = self->v40;
    }
    self->Update(dt, x);
    return done;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017D8E0(void) {}
#undef cHermiteSplineWithScaledDuration_cVector_Evaluate /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017D8E0 */

/* merge_units: begin func_0017DA60 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int cVector_opAdd(char *, char *, char *);                          
int cHermiteSplineControlPoint_cVector_Tangent(int);                             
int opMul(float, char *, int);                     
int cHermiteSplineControlPoint_cVector_Position(int);                             
int cArray_FixedSize_cHermiteSplineControlPoint_cVector_2_opIndex(char * , int);                       

void cHermiteSplineWithScaledDuration_cVector_Evaluate(char *arg0, char * arg1, float farg0) {
    int sp90[4];
    int sp80[4];
    int sp70[4];
    float temp_f22;
    float temp_f21;
    int sp60[4];
    int sp50[4];
    float var_f20;
    float temp_f23;
    int sp40[4];

    if (F_(arg1, 0x40, float) != 0.0f) {
        var_f20 = farg0 * F_(arg1, 0x44, float);
    } else {
        var_f20 = 1.0f;
    }
    temp_f22 = var_f20 * var_f20;
    temp_f21 = temp_f22 * var_f20;
    temp_f23 = 3.0f * temp_f22;
    opMul(1.0f + ((2.0f * temp_f21) - temp_f23), sp70, cHermiteSplineControlPoint_cVector_Position(cArray_FixedSize_cHermiteSplineControlPoint_cVector_2_opIndex(arg1, 0)));
    opMul((-2.0f * temp_f21) + temp_f23, sp60, cHermiteSplineControlPoint_cVector_Position(cArray_FixedSize_cHermiteSplineControlPoint_cVector_2_opIndex(arg1, 1)));
    cVector_opAdd(sp80, sp70, sp60);
    opMul(var_f20 + (temp_f21 - (2.0f * temp_f22)), sp50, cHermiteSplineControlPoint_cVector_Tangent(cArray_FixedSize_cHermiteSplineControlPoint_cVector_2_opIndex(arg1, 0)));
    cVector_opAdd(sp90, sp80, sp50);
    opMul(temp_f21 - temp_f22, sp40, cHermiteSplineControlPoint_cVector_Tangent(cArray_FixedSize_cHermiteSplineControlPoint_cVector_2_opIndex(arg1, 1)));
    cVector_opAdd(arg0, sp90, sp40);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017DA60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017DA60 */
