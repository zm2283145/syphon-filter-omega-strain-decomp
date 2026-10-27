/*
 * main/human: range (2 files, 001AF040-001AF080)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "human_types.h"

/* merge_units: begin func_001AF040 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct AnimSlot {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual float Evaluate(); /* +0x14 */
    float start;   /* +0x04 */
    float current; /* +0x08 */
    float value;   /* +0x0C */
    float target;  /* +0x10 */
};

/* Resets the slot start/current/target to v and re-evaluates its value; returns the slot. */
extern "C" AnimSlot* cSkaSliderValue_opAssign(AnimSlot* self, float v)
{
    self->target = v;
    self->current = v;
    self->start = v;
    self->value = self->Evaluate();
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AF040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AF040 */

/* merge_units: begin func_001AF080 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_ctor(void* binding, CurveSegment* segment);
extern int cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_float(CurveSegment*, int, int, float);
static const float dat_0048A198[2] = { 0.0f, 0.0f };
static const float dat_0048A1A0[2] = { 0.0f, 0.0f };
extern char D_004DA380[];   /* CurveChannel base vtable */
extern char D_004DA840[];   /* AnimChannel vtable */
extern void std_tree_pair_cString_value_compare_find_cStringR_2(int*, int, int);

/* AnimChannel constructor: zero scalars, constant segment, wrapping off. */
AnimChannel* cSplinedMotion_Scalar0To1_ctor(AnimChannel* self) {
    self->base.vtable = D_004DA380;
    self->base.previous = (*(float*)dat_0048A198);
    self->base.current = (*(float*)dat_0048A198);
    self->base.target = (*(float*)dat_0048A1A0);
    self->base.rate = (*(float*)dat_0048A198);
    self->base.damping = 0.0f;
    cHermiteSplineWithScaledDuration_float_ctor_floatR_floatR_float(&self->base.segment, (int)&(*(float*)dat_0048A198), (int)&(*(float*)dat_0048A1A0), 0.0f);
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_ctor(self->base.binding, &self->base.segment);
    self->base.vtable = D_004DA840;
    self->wrap = 0;
    return self;
}

int cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opMul(int* self) {
    return *self + 24;
}

int cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void cAssocArray_cString_cSkaAnimationSetPtr_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Tree lookup wrapper returning the found iterator through out. */
void cAssocArray_cString_cSkaAnimationSetPtr_Find(int* out) {
    int it[1];
    int a1, a2;

    std_tree_pair_cString_value_compare_find_cStringR_2(it, a1, a2);
    *out = it[0];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AF080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AF080 */
