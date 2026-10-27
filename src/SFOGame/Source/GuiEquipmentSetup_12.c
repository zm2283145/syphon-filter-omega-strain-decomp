/*
 * SFOGame/Source/GuiEquipmentSetup: 6 files, 002A5DD0-002A63C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A5DD0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "range_copy_assign.h"

/* Copy a range of 60-byte elements by assignment. */
DEFINE_COPY_ELEMENT(Elem60, 60)
DEFINE_RANGE_COPY_ASSIGN(func_002A5DD0, Elem60, cSplinedMotion_Scalar0To1_opAssign)
static inline void merge_flush_func_002A5DD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A5DD0 */

/* merge_units: begin func_002A5E40 */
#pragma push /* merge_units */
typedef struct Obj39 {
    int unk0;
    float f[5];
    char sub18[0x18];
    char sub30[8];
    unsigned char flag;
} Obj39;

extern void cHermiteSplineWithScaledDuration_float_opAssign(void*, void*);
extern float cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_GetTimeLeft(void*);
extern void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Reset(void*, void*, float);

/* Assignment: copies five floats, the sub-object at +0x18, derived data at +0x30 and the flag. */
Obj39* func_002A5E40(Obj39* self, Obj39* other) {
    self->f[0] = other->f[0];
    self->f[1] = other->f[1];
    self->f[2] = other->f[2];
    self->f[3] = other->f[3];
    self->f[4] = other->f[4];
    cHermiteSplineWithScaledDuration_float_opAssign(self->sub18, other->sub18);
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Reset(self->sub30, self->sub18, cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_GetTimeLeft(other->sub30));
    self->flag = other->flag;
    return self;
}
static inline void merge_flush_func_002A5E40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A5E40 */

/* merge_units: begin func_002A5ED0 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; float f10; } A5_002A5ED0_B;
typedef struct { A5_002A5ED0_B* b; float f; } A5_002A5ED0_A;
void func_002A5ED0(A5_002A5ED0_A* a, A5_002A5ED0_B* b, float f) {
    a->b = b;
    if (f < 0.0f) f = b->f10;
    a->f = f;
}
static inline void merge_flush_func_002A5ED0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A5ED0 */

/* merge_units: begin func_002A5EF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiEquipmentSetup.cc. Functions are named by address
 * until real names are known.
 */

#include "GuiEquipmentSetup_types.h"

float func_002A5EF0(char* self) {
    return *(float*)(self + 4);
}

Float6* func_002A5F00(Float6* dst, Float6* src) {
    dst->v[0] = src->v[0];
    dst->v[1] = src->v[1];
    dst->v[2] = src->v[2];
    dst->v[3] = src->v[3];
    dst->v[4] = src->v[4];
    dst->v[5] = src->v[5];
    return dst;
}
static inline void merge_flush_func_002A5EF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A5EF0 */

/* merge_units: begin func_002A5F40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill_obj.h"

extern "C" { char D_004AB2E0[] = "vector::insert length error\n"; }
DEFINE_VECTOR_INSERT_FILL_OBJ(Vector_Insert_2A5F40, 0x3C, 0x199999, 0xCCCCC, D_004AB2E0, D_0049ECF8, 0x5C, opNew_uint_voidP, cSkaSliderValue_ctor_cSkaSliderValueR, std_copy_backward_cSkaSliderValue_copy_backward, std_fill_n_cSkaSliderValue_int_fill_n, std_swap_vectordeleterR_vectordeleterR_9, std_vector_deleter_cSkaSliderValue_dtor)
static inline void merge_flush_func_002A5F40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A5F40 */

/* merge_units: begin func_002A63C0 */
#pragma push /* merge_units */
void func_002A63C0(PtrVec* a, PtrVec* b) {
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
static inline void merge_flush_func_002A63C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A63C0 */
