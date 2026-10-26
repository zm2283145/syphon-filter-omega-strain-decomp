/*
 * main/human: range (2 files, 001B79C0-001B7A20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "human_types.h"

/* merge_units: begin func_001B79C0 */
#pragma push /* merge_units */
Rel* std_vector_cTargetZRotationStackSlot_ctor(Rel* r); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern Rel* std_vector_cTargetZRotationStackSlot_ctor(Rel*);
#endif /* merge_units */
#define std_vector_cTargetZRotationStackSlot_ctor(a0) (std_vector_cTargetZRotationStackSlot_ctor((a0))) /* merge_units */


void cSplinedMotion_float_SetTargetVal(char* self, float* value) {
    *(float*)(self + 16) = *value;
}

/* back(): address of the last 8-byte element. */
char* cArray_cTargetZRotationStackSlot_Back(PtrVec* v) {
    return (char*)v->data + (v->count << 3) - 8;
}

/* Clear the three words and set the byte at +0x0C. */
Rel* cHumanMotionParams_cTargetZRotationStack_ctor(Rel* r) {
    std_vector_cTargetZRotationStackSlot_ctor(r);
    *((char*)r + 12) = 1;
    return r;
}
#undef std_vector_cTargetZRotationStackSlot_ctor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B79C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B79C0 */

/* merge_units: begin func_001B7A20 */
#pragma push /* merge_units */
extern int Curve_Bind(void* binding, CurveSegment* segment);
extern int Curve_InitConstant(CurveSegment*, int, int, float);
static const float dat_0048A1B8[2] = { 0.0f, 0.0f };
static const float dat_0048A1C0[2] = { 0.0f, 0.0f };
extern char D_004DA380[];   /* CurveChannel base vtable */
extern char D_004DA7D0[];   /* AngleCurve vtable */

Rel* std_vector_cTargetZRotationStackSlot_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Scalar angle curve constructor (actor member +0x3050). */
CurveChannel* AngleCurve_Construct(CurveChannel* self) {
    self->vtable = D_004DA380;
    self->previous = (*(float*)dat_0048A1B8);
    self->current = (*(float*)dat_0048A1B8);
    self->target = (*(float*)dat_0048A1C0);
    self->rate = (*(float*)dat_0048A1B8);
    self->damping = 0.0f;
    Curve_InitConstant(&self->segment, (int)&(*(float*)dat_0048A1B8), (int)&(*(float*)dat_0048A1C0), 0.0f);
    Curve_Bind(self->binding, &self->segment);
    self->vtable = D_004DA7D0;
    return self;
}

Rel* cStatesWithHistory_1_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B7A20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B7A20 */
