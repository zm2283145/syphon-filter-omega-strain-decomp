/*
 * SFOGame/Source/gameCamera: 4 files, 0017F1E0-0017F2E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017F1E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

typedef struct Binding {
    int target;
    int unk4;
} Binding;

/* Initializes the binding with target and clears the second word. */
Binding* cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_ctor(Binding* b, int target) {
    b->target = target;
    b->unk4 = 0;
    return b;
}
static inline void merge_flush_func_0017F1E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017F1E0 */

/* merge_units: begin func_0017F1F0 */
#pragma push /* merge_units */
/* cHermiteSplineWithScaledDuration_cVector_ctor_cVectorR_cVectorR_float: Pair[2] init from (a, b*f) + f40=f, f44=1/f. Empty do/while stands in for the Pair array ctor loop; named scale temp V s fixes stack order; 'i <= 1' gives slti $at. */
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
static inline void ScaleTo(V* d, const V* s, float k) { int r; V* dd = d; asm {
        .set noreorder
        lqc2 vf1, 0x0(s)
        mfc1 r, k
        qmtc2.ni r, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(dd)
        .set reorder
    } }
inline V V::operator*(float k) const { V t; ScaleTo(&t, this, k); return t; }
struct Pair {
    V a; V b;
    Pair() {}
    Pair(const V& x, const V& y) : a(x), b(y) {}
    Pair& operator=(const Pair& o) { Pair* t = this; t->a = o.a; t->b = o.b; return *this; }
};
struct T {
    Pair arr[2];
    float f40;
    float f44;
};
extern "C" T* cHermiteSplineWithScaledDuration_cVector_ctor_cVectorR_cVectorR_float(T* p, const V* a, const V* b, float f)
{
    int i;
    V s = *b * f; Pair pl(*a, s);
    {
        Pair* q = p->arr;
        do { q++; } while (q != p->arr + 2);
    }
    for (i = 0; i <= 1; i++) p->arr[i] = pl;
    p->f40 = f;
    p->f44 = (f != 0.0f) ? 1.0f / f : 0.0f;
    return p;
}
static inline void merge_flush_func_0017F1F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017F1F0 */

/* merge_units: begin func_0017F2E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern char D_0048A158[];
extern char D_0048A160[];
extern char D_004DA3E0[]; /* vtable */
extern int cSplinedMotion_float_ctor_floatR_floatR(char* self, char*, char*);

/* Constructor: base construct, set vtable, clear words +0x38 and +0x3C. */
char* cCameraShake_cPulsedShakeMagnitude_ctor(char* self) {
    cSplinedMotion_float_ctor_floatR_floatR(self, D_0048A158, D_0048A160);
    *(char**)self = D_004DA3E0;
    *(int*)(self + 0x38) = 0;
    *(int*)(self + 0x3C) = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017F2E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017F2E0 */

/* merge_units: begin func_0017F330 */
#pragma push /* merge_units */
typedef struct { char b[0x18]; } Curve;
typedef struct { char b[0x10]; } CurveBinding;
typedef struct {
    void* vtable;
    float min;
    float cur;
    float max;
    float def;
    int unk14;
    Curve curve;
    CurveBinding binding;
} Obj17F;
extern char D_004DA380[];
#if 0 /* merge_units */
extern float D_0048A158;
#endif /* merge_units */
#define D_0048A158 (*(float*)&D_0048A158) /* merge_units */


#if 0 /* merge_units */
extern float D_0048A160;
#endif /* merge_units */
#define D_0048A160 (*(float*)&D_0048A160) /* merge_units */


extern void cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_float(Curve* c, float* lo, float* hi, float value);
extern void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_ctor(CurveBinding* b, Curve* c);

/* Constructor: default range values, a constant curve and its binding. */
Obj17F* cSplinedMotion_Scalar_ctor(Obj17F* self)
{
    self->vtable = D_004DA380;
    self->min = D_0048A158;
    self->cur = D_0048A158;
    self->max = D_0048A160;
    self->def = D_0048A158;
    self->unk14 = 0;
    cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_float(&self->curve, &D_0048A158, &D_0048A160, 0.0f);
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_ctor(&self->binding, &self->curve);
    self->vtable = D_004DA3E0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017F330(void) {}
#undef D_0048A158 /* merge_units */
#undef D_0048A160 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017F330 */
