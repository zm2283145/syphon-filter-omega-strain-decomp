/*
 * SFOGame/Source/humanCollision: 1 file, 001ED0E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001ED0E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cArray_cEdgeGroup_ConstIterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter16* cArray_cEdgeGroup_ConstIterator_opInc(Iter16* it) {
    it->p += 16;
    return it;
}
static inline void merge_flush_func_001ED0E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ED0E0 */
