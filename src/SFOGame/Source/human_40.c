/*
 * SFOGame/Source/human: 1 file, 001912A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001912A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* cArray_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_Iterator_opInc(Iter* it) {
    it->p++;
    return it;
}
static inline void merge_flush_func_001912A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001912A0 */
