/*
 * main/GuiSaveAgentWidget: 6 files, 00291600-00291BF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00291600 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "range_copy_assign.h"

/* Copy a range of 60-byte elements by assignment. */
DEFINE_COPY_ELEMENT(Elem60, 60)
DEFINE_RANGE_COPY_ASSIGN(func_00291600, Elem60, cSplinedMotion_Scalar0To1_opAssign)
#pragma pop /* merge_units */
/* merge_units: end func_00291600 */

/* merge_units: begin func_00291670 */
#pragma push /* merge_units */
typedef struct Obj291 {
    int unk0;
    float values[5];
    char sub18[0x18];
    char sub30[8];
    unsigned char flag;
} Obj291;

extern void cHermiteSplineWithScaledDuration_float_opAssign(void* dst, void* src);
extern float cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_GetTimeLeft(void* src);
extern void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Reset(void* dst, void* ref, float value);

/* Copy-assigns src into dst (all fields but the first word); returns dst. */
Obj291* func_00291670(Obj291* dst, Obj291* src) {
    dst->values[0] = src->values[0];
    dst->values[1] = src->values[1];
    dst->values[2] = src->values[2];
    dst->values[3] = src->values[3];
    dst->values[4] = src->values[4];
    cHermiteSplineWithScaledDuration_float_opAssign(dst->sub18, src->sub18);
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Reset(dst->sub30, dst->sub18, cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_GetTimeLeft(src->sub30));
    dst->flag = src->flag;
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_00291670 */

/* merge_units: begin func_00291700 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; float def; } F291700_Src;
typedef struct { F291700_Src* src; float t; } F291700_t;
void func_00291700(F291700_t* o, F291700_Src* s, float t) {
    o->src = s;
    if (t < 0.0f) t = s->def;
    o->t = t;
}
#pragma pop /* merge_units */
/* merge_units: end func_00291700 */

/* merge_units: begin func_00291720 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

/* Returns the float at +4 (second float of the record). */
float func_00291720(Float6* self) {
    return self->v[1];
}

/* Float6 copy (assignment). */
Float6* func_00291730(Float6* dst, Float6* src) {
    dst->v[0] = src->v[0];
    dst->v[1] = src->v[1];
    dst->v[2] = src->v[2];
    dst->v[3] = src->v[3];
    dst->v[4] = src->v[4];
    dst->v[5] = src->v[5];
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_00291720 */

/* merge_units: begin func_00291770 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill_obj.h"

DEFINE_VECTOR_INSERT_FILL_OBJ(Vector_Insert_291770, 0x3C, 0x199999, 0xCCCCC, D_004A9B20, D_0049ECF8, 0x5C, Mem_PlacementNew, AnimChannel_CopyCtor, std_copy_backward_cSkaSliderValue_copy_backward, std_fill_n_cSkaSliderValue_int_fill_n, std_swap_vectordeleterR_vectordeleterR_9, std_vector_deleter_cSkaSliderValue_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00291770 */

/* merge_units: begin func_00291BF0 */
#pragma push /* merge_units */
void func_00291BF0(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00291BF0 */
