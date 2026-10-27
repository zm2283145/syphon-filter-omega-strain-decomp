/*
 * SFOGame/Source/humanCollision: 1 file, 001ED210
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001ED210 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

FlagElem16* cArray_cEdgeGroup_ConstIterator_opMul(FlagElem16Iter* it) {
    return it->p;
}

/* End iterator of an array of 16-byte elements. */
void cArray_cEdgeGroup_End_void_2(FlagElem16Iter* out, Vec16Array* v) {
    out->p = v->data + v->count;
}

void cArray_cEdgeGroup_Begin_void_2(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_001ED210(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ED210 */
