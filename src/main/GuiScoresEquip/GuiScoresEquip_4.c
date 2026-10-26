/*
 * main/GuiScoresEquip: 6 files, 0035E7A0-0035ED90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0035E7A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "range_copy_assign.h"

/* Copy a range of 60-byte elements by assignment. */
DEFINE_COPY_ELEMENT(Elem60, 60)
DEFINE_RANGE_COPY_ASSIGN(func_0035E7A0, Elem60, cSplinedMotion_Scalar0To1_opAssign)
#pragma pop /* merge_units */
/* merge_units: end func_0035E7A0 */

/* merge_units: begin func_0035E810 */
#pragma push /* merge_units */
typedef struct { char data[0x18]; } Part18;
typedef struct { char data[8]; } Part8;
typedef struct { int unk0; float f[5]; Part18 a; Part8 b; unsigned char flag; } Obj35E;

extern void cHermiteSplineWithScaledDuration_float_opAssign(Part18* dst, Part18* src);
extern float cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_GetTimeLeft(Part8* p);
extern void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Reset(Part8* dst, Part18* ref, float value);

/* Copies src into self (floats, sub-objects and flag); returns self. */
Obj35E* func_0035E810(Obj35E* self, Obj35E* src)
{
    self->f[0] = src->f[0];
    self->f[1] = src->f[1];
    self->f[2] = src->f[2];
    self->f[3] = src->f[3];
    self->f[4] = src->f[4];
    cHermiteSplineWithScaledDuration_float_opAssign(&self->a, &src->a);
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Reset(&self->b, &self->a, cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_GetTimeLeft(&src->b));
    self->flag = src->flag;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0035E810 */

/* merge_units: begin func_0035E8A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; float f10; } A2B35E;
typedef struct { A2B35E* b; float f; } A2A35E;
void func_0035E8A0(A2A35E* a, A2B35E* b, float x) {
    a->b = b;
    if (x < 0.0f) x = b->f10;
    a->f = x;
}
#pragma pop /* merge_units */
/* merge_units: end func_0035E8A0 */

/* merge_units: begin func_0035E8C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiScoresEquip.cc. Functions are named by address
 * until real names are known.
 */

#include "GuiScoresEquip_types.h"

float func_0035E8C0(char* self) {
    return *(float*)(self + 4);
}

Float6* func_0035E8D0(Float6* dst, Float6* src) {
    dst->v[0] = src->v[0];
    dst->v[1] = src->v[1];
    dst->v[2] = src->v[2];
    dst->v[3] = src->v[3];
    dst->v[4] = src->v[4];
    dst->v[5] = src->v[5];
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_0035E8C0 */

/* merge_units: begin func_0035E910 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill_obj.h"

extern "C" { char D_004BB680[] = "vector::insert length error\n"; }
DEFINE_VECTOR_INSERT_FILL_OBJ(Vector_Insert_35E910, 0x3C, 0x199999, 0xCCCCC, D_004BB680, D_0049ECF8, 0x5C, Mem_PlacementNew, AnimChannel_CopyCtor, std_copy_backward_cSkaSliderValue_copy_backward, std_fill_n_cSkaSliderValue_int_fill_n, std_swap_vectordeleterR_vectordeleterR_9, std_vector_deleter_cSkaSliderValue_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0035E910 */

/* merge_units: begin func_0035ED90 */
#pragma push /* merge_units */
void func_0035ED90(PtrVec* a, PtrVec* b) {
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
/* merge_units: end func_0035ED90 */
