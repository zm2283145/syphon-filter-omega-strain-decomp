/*
 * main/human: 3 files, 001BF9E0-001BFAD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001BF9E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_10(PtrVec* a, PtrVec* b) {
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

/* clear(): count = 0. */
void func_001BFA20(PtrVec* v) {
    v->count = 0;
}

/* clear(): count = 0. */
void func_001BFA30(PtrVec* v) {
    v->count = 0;
}

/* clear(): count = 0. */
void func_001BFA40(PtrVec* v) {
    v->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_001BF9E0 */

/* merge_units: begin func_001BFA50 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_release_dtor.h"

/* Destroy a vector through its allocator, optionally delete. */
extern "C" { char D_0049ECD8[] = "allocator.hh"; }
DEFINE_VECTOR_RELEASE_DTOR(std_vector_deleter_cSkaSliderValue_dtor, std_vector_deleter_cSkaSliderValue_clear, opDelete_cSkaSliderValueP_int_bool_charP_etc, D_0049ECD8)
#pragma pop /* merge_units */
/* merge_units: end func_001BFA50 */

/* merge_units: begin func_001BFAD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_destroy_release.h"

/* Destroy and free an allocation under the allocator guard. */
DEFINE_GUARDED_DESTROY_RELEASE(opDelete_cSkaSliderValueP_int_bool_charP_etc, cSplinedMotion_Scalar0To1_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_001BFAD0 */
