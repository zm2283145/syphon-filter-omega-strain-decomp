/*
 * main/GuiNetMessages: 6 files, 00345B50-00346140
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00345B50 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "range_copy_assign.h"

/* Copy a range of 60-byte elements by assignment. */
DEFINE_COPY_ELEMENT(Elem60, 60)
DEFINE_RANGE_COPY_ASSIGN(func_00345B50, Elem60, cSplinedMotion_Scalar0To1_opAssign)
#pragma pop /* merge_units */
/* merge_units: end func_00345B50 */

/* merge_units: begin func_00345BC0 */
#pragma push /* merge_units */
typedef struct Shape345 {
    int unk00;
    float a, b, c, d, e;   /* 0x04 - 0x14 */
    char part18[0x18];     /* 0x18 */
    char part30[8];        /* 0x30 */
    unsigned char flag;    /* 0x38 */
} Shape345;

extern void cHermiteSplineWithScaledDuration_float_opAssign(void* dst, void* src);
extern float cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_GetTimeLeft(void* src);
extern void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Reset(void* dst, void* ref, float value);

/* Copy-assigns a shape; returns dst. */
Shape345* func_00345BC0(Shape345* dst, Shape345* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    cHermiteSplineWithScaledDuration_float_opAssign(dst->part18, src->part18);
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Reset(dst->part30, dst->part18, cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_GetTimeLeft(src->part30));
    dst->flag = src->flag;
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_00345BC0 */

/* merge_units: begin func_00345C50 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; float f10; } A1_T;
typedef struct { A1_T* p; float f4; } A1_S;
void func_00345C50(A1_S* o, A1_T* p, float x) {
    o->p = p;
    if (x < 0.0f) x = p->f10;
    o->f4 = x;
}
#pragma pop /* merge_units */
/* merge_units: end func_00345C50 */

/* merge_units: begin func_00345C70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

float func_00345C70(Float6* self) {
    return self->v[1];
}

/* Float6 copy. */
Float6* func_00345C80(Float6* dst, Float6* src) {
    dst->v[0] = src->v[0];
    dst->v[1] = src->v[1];
    dst->v[2] = src->v[2];
    dst->v[3] = src->v[3];
    dst->v[4] = src->v[4];
    dst->v[5] = src->v[5];
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_00345C70 */

/* merge_units: begin func_00345CC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill_obj.h"

DEFINE_VECTOR_INSERT_FILL_OBJ(Vector_Insert_345CC0, 0x3C, 0x199999, 0xCCCCC, D_004BA0E0, D_0049ECF8, 0x5C, opNew_uint_voidP, cSkaSliderValue_ctor_cSkaSliderValueR, std_copy_backward_cSkaSliderValue_copy_backward, std_fill_n_cSkaSliderValue_int_fill_n, std_swap_vectordeleterR_vectordeleterR_9, std_vector_deleter_cSkaSliderValue_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00345CC0 */

/* merge_units: begin func_00346140 */
#pragma push /* merge_units */
void func_00346140(PtrVec* a, PtrVec* b) {
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
/* merge_units: end func_00346140 */
