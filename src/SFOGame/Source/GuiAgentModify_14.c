/*
 * SFOGame/Source/GuiAgentModify: 10 files, 00346180-00346340
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00346180 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x3C]; } G3E_00346180;
extern void cSplinedMotion_Scalar0To1_opAssign(G3E_00346180* p, int x);
void func_00346180(G3E_00346180* p, int n, int x) {
    for (; n != 0; n--) {
        cSplinedMotion_Scalar0To1_opAssign(p, x);
        p++;
    }
}
static inline void merge_flush_func_00346180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00346180 */

/* merge_units: begin func_003461E0 */
#pragma push /* merge_units */
typedef struct Rec3C {
    char b[0x3C];
} Rec3C;

#if 0 /* merge_units */
extern void cSplinedMotion_Scalar0To1_opAssign(Rec3C*, Rec3C*);
#endif /* merge_units */
#define cSplinedMotion_Scalar0To1_opAssign(a0, a1) (cSplinedMotion_Scalar0To1_opAssign((G3E_00346180 *)(a0), (int)(a1))) /* merge_units */



/* Copies [first, last) backwards ending at destEnd; returns the new destination begin. */
Rec3C* func_003461E0(Rec3C* first, Rec3C* last, Rec3C* destEnd) {
    while (last > first) {
        Rec3C* src = --last;
        Rec3C* dst = --destEnd;
        cSplinedMotion_Scalar0To1_opAssign(dst, src);
    }
    return destEnd;
}
#undef cSplinedMotion_Scalar0To1_opAssign /* merge_units */
static inline void merge_flush_func_003461E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003461E0 */

/* merge_units: begin func_00346250 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern int cSplinedMotion_float_ctor_cSplinedMotionR(L3AnimChannel* self, L3AnimChannel* src);
extern char D_004DA840[];       /* AnimChannel vtable */

/* AnimChannel copy constructor. */
L3AnimChannel* AnimChannel_CopyCtor_346250(L3AnimChannel* self, L3AnimChannel* src) {
    cSplinedMotion_float_ctor_cSplinedMotionR(self, src);
    self->vtable = D_004DA840;
    self->wrap = src->wrap;
    return self;
}
static inline void merge_flush_func_00346250(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00346250 */

/* merge_units: begin func_003462A0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
extern int D_004DA380;

int AnimChannelBase_CopyCtor_3462A0(int arg0, int arg1) {
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
static inline void merge_flush_func_003462A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003462A0 */

/* merge_units: begin func_00346340 */
#pragma push /* merge_units */
#include "pod8_vector_erase.h"

/* Erase a range from a vector of 8-byte elements. */
DEFINE_POD8_VECTOR_ERASE(func_00346340)
static inline void merge_flush_func_00346340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00346340 */

/* merge_units: begin func_003464A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill8.h"

DEFINE_VECTOR_INSERT_FILL8(Vector_Insert_3464A0, D_004BA0E0, D_0049ECE8, 0x5C, std_swap_vectordeleterR_vectordeleterR_10, std_vector_deleter_cSkaSwitchValue_dtor)
static inline void merge_flush_func_003464A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003464A0 */

/* merge_units: begin func_003468E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void func_003468E0(PtrVec* a, PtrVec* b) {
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

void func_00346920(char* self) {
    *(int*)(self + 4) = 0;
}
static inline void merge_flush_func_003468E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003468E0 */

/* merge_units: begin func_00346930 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_release_dtor.h"

/* Destroy a vector through its allocator, optionally delete. */
DEFINE_VECTOR_RELEASE_DTOR(func_00346930, std_vector_deleter_cSkaSliderValue_clear, opDelete_cSkaSliderValueP_int_bool_charP_etc, D_0049ECD8)
static inline void merge_flush_func_00346930(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00346930 */

/* merge_units: begin func_003469B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_destroy_release.h"

/* Destroy and free an allocation under the allocator guard. */
DEFINE_GUARDED_DESTROY_RELEASE(func_003469B0, cSplinedMotion_Scalar0To1_dtor)
static inline void merge_flush_func_003469B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003469B0 */

/* merge_units: begin func_00346A90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR(func_00346A90, std_vector_deleter_cSkaSwitchValue_clear)
static inline void merge_flush_func_00346A90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00346A90 */
