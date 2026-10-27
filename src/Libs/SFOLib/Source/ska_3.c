/*
 * Libs/SFOLib/Source/ska: 2 files, 003AB3A0-003AB3E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003AB3A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_39(PtrVec* a, PtrVec* b) {
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
static inline void merge_flush_func_003AB3A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AB3A0 */

/* merge_units: begin func_003AB3E0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cSkeletonData_dtor)
static inline void merge_flush_func_003AB3E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AB3E0 */
