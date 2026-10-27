/*
 * SFOGame/Source/GuiAgentCreate: 9 files, 00291C90-00291DF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00291C90 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "range_copy_backward_assign.h"

/* Copy a range of 60-byte elements backward by assignment. */
DEFINE_COPY_BACKWARD_ELEMENT(Elem60, 60)
DEFINE_RANGE_COPY_BACKWARD_ASSIGN(func_00291C90, Elem60, cSplinedMotion_Scalar0To1_opAssign)
static inline void merge_flush_func_00291C90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00291C90 */

/* merge_units: begin func_00291D00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

extern AnimChannel* cSplinedMotion_float_ctor_cSplinedMotionR(AnimChannel* self, AnimChannel* src);
extern char D_004DA840[];   /* AnimChannel vtable */

/* AnimChannel copy constructor (inline copy emitted in this unit). */
AnimChannel* AnimChannel_CopyCtor_291D00(AnimChannel* self, AnimChannel* src) {
    cSplinedMotion_float_ctor_cSplinedMotionR(self, src);
    self->base.vtable = D_004DA840;
    self->wrap = src->wrap;
    return self;
}
static inline void merge_flush_func_00291D00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00291D00 */

/* merge_units: begin func_00291D50 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
extern int D_004DA380;

int func_00291D50(int arg0, int arg1) {
    int temp_a2;
    int var_v1;

    temp_a2 = arg0 + 0x18;
    var_v1 = temp_a2;
    F_(arg0, 0x0, int) = (int)(&D_004DA380);
    F_(arg0, 0x4, float) = F_(arg1, 0x4, float);
    F_(arg0, 0x8, float) = F_(arg1, 0x8, float);
    F_(arg0, 0xC, float) = F_(arg1, 0xC, float);
    F_(arg0, 0x10, float) = F_(arg1, 0x10, float);
    F_(arg0, 0x14, float) = F_(arg1, 0x14, float);
    do {
        var_v1 += 8;
    } while (var_v1 != (temp_a2 + 0x10));
    F_(temp_a2, 0x0, float) = F_(arg1, 0x18, float);
    F_(temp_a2, 0x4, float) = F_(arg1, 0x1C, float);
    F_(temp_a2, 0x8, float) = F_(arg1, 0x20, float);
    F_(temp_a2, 0xC, float) = F_(arg1, 0x24, float);
    F_(temp_a2, 0x10, float) = F_(arg1, 0x28, float);
    F_(temp_a2, 0x14, float) = F_(arg1, 0x2C, float);
    F_(arg0, 0x30, int) = (int ) (arg0 + 0x18);
    F_(arg0, 0x34, int) = 0;
    return arg0;
}
static inline void merge_flush_func_00291D50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00291D50 */

/* merge_units: begin func_00291DF0 */
#pragma push /* merge_units */
#include "pod8_vector_erase.h"

/* Erase a range from a vector of 8-byte elements. */
DEFINE_POD8_VECTOR_ERASE(func_00291DF0)
static inline void merge_flush_func_00291DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00291DF0 */

/* merge_units: begin func_00291F50 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill8.h"

DEFINE_VECTOR_INSERT_FILL8(Vector_Insert_291F50, D_004A9B20, D_0049ECE8, 0x5C, std_swap_vectordeleterR_vectordeleterR_10, std_vector_deleter_cSkaSwitchValue_dtor)
static inline void merge_flush_func_00291F50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00291F50 */

/* merge_units: begin func_00292390 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void func_00292390(PtrVec* a, PtrVec* b) {
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
static inline void merge_flush_func_00292390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00292390 */

/* merge_units: begin func_002923D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_release_dtor.h"

/* Destroy a vector through its allocator, optionally delete. */
DEFINE_VECTOR_RELEASE_DTOR(func_002923D0, std_vector_deleter_cSkaSliderValue_clear, opDelete_cSkaSliderValueP_int_bool_charP_etc, D_0049ECD8)
static inline void merge_flush_func_002923D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002923D0 */

/* merge_units: begin func_00292450 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_destroy_release.h"

/* Destroy and free an allocation under the allocator guard. */
DEFINE_GUARDED_DESTROY_RELEASE(func_00292450, cSplinedMotion_Scalar0To1_dtor)
static inline void merge_flush_func_00292450(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00292450 */

/* merge_units: begin func_00292530 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR(func_00292530, std_vector_deleter_cSkaSwitchValue_clear)
static inline void merge_flush_func_00292530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00292530 */
