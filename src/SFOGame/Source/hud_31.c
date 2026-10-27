/*
 * SFOGame/Source/hud: 2 files, 00246FB0-00246FF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00246FB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_22(PtrVec* a, PtrVec* b) {
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
static inline void merge_flush_func_00246FB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00246FB0 */

/* merge_units: begin func_00246FF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_buffer_dtor.h"

extern "C" { char D_004A74E8[] = "allocator.hh"; }
DEFINE_GUARDED_BUFFER_CALL_DTOR(std_vector_deleter_PDAQuip_dtor, std_vector_deleter_PDAQuip_clear, D_004A74E8)
static inline void merge_flush_func_00246FF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00246FF0 */
