/*
 * Libs/SFOLib/Source/NetObjectMgr: 1 file, 0042DF00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042DF00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Iterator copy-assignment. */
Word* cAssocArray_int_tNetObjectPtr_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* end(): iterator at the tree header. */
void std_map_int_tNetObjectPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}
static inline void merge_flush_func_0042DF00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042DF00 */
