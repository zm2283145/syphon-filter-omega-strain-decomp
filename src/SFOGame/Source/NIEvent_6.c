/*
 * SFOGame/Source/NIEvent: 3 files, 00238850-00238940
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00238850 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cNIEventBasePtr_dtor)
static inline void merge_flush_func_00238850(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00238850 */

/* merge_units: begin func_00238940 */
#pragma push /* merge_units */
#include "types.h"
#include "NIEvent_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern NIEventVec3* std_vector_imp_FloatKey_ctor(NIEventVec3* vec);

/* Constructs an empty vector that owns its storage. */
NIEventOwnedVec* cArray_FloatKey_ctor(NIEventOwnedVec* self) {
    std_vector_imp_FloatKey_ctor(&self->vec);
    self->owned = 1;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00238940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00238940 */

/* merge_units: begin func_00238970 */
#pragma push /* merge_units */
/* Constructs an empty vector. */
NIEventVec3* std_vector_imp_FloatKey_ctor(NIEventVec3* vec) {
    vec->begin = 0;
    vec->end = 0;
    vec->cap = 0;
    return vec;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00238970(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00238970 */
