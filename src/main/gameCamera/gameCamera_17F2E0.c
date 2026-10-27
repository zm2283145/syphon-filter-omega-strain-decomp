/*
 * main/gameCamera: range (2 files, 0017F2E0-0017F330)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

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
#undef D_0048A158 /* merge_units */
#undef D_0048A160 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017F330(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017F330 */
