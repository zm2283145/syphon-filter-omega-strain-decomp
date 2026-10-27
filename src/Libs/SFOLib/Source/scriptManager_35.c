/*
 * Libs/SFOLib/Source/scriptManager: 1 file, 003E1EF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E1EF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_vector_VarDefPtr_end(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* cArray_VarDefPtr_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_VarDefPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_003E1EF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E1EF0 */
