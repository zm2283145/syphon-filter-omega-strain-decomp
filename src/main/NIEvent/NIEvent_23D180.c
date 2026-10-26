/*
 * main/NIEvent: range (2 files, 0023D180-0023D1B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "NIEvent_types.h"

/* merge_units: begin func_0023D180 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern NIEventVec3* std_vector_imp_cFXKeyPtr_1_ctor(NIEventVec3* vec);

/* Constructs an empty vector that owns its storage. */
NIEventOwnedVec* cArray_cFXKeyPtr_ctor(NIEventOwnedVec* self) {
    std_vector_imp_cFXKeyPtr_1_ctor(&self->vec);
    self->owned = 1;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023D180(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023D180 */

/* merge_units: begin func_0023D1B0 */
#pragma push /* merge_units */
/* Constructs an empty vector. */
NIEventVec3* std_vector_imp_cFXKeyPtr_1_ctor(NIEventVec3* vec) {
    vec->begin = 0;
    vec->end = 0;
    vec->cap = 0;
    return vec;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023D1B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023D1B0 */
