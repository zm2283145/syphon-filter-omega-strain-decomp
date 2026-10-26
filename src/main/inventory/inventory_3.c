/*
 * main/inventory: 2 files, 00471960-004719B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00471960 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* swap(a, b) */
void std_swap_vectordeleterR_vectordeleterR_54(PtrVec* a, PtrVec* b) {
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

/* clear(): count = 0 */
void func_004719A0(PtrVec* v) {
    v->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00471960 */

/* merge_units: begin func_004719B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "clear_buffer_dtor.h"

/* Clear and free a vector, optionally delete. */
extern "C" { char D_004C33E0[] = "allocator.hh"; }
DEFINE_CLEAR_BUFFER_DTOR(std_vector_deleter_tRecord_dtor, D_004C33E0)
#pragma pop /* merge_units */
/* merge_units: end func_004719B0 */
