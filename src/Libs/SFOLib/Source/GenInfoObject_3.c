/*
 * Libs/SFOLib/Source/GenInfoObject: 1 file, 00438DF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00438DF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* cLListIterator_tGenInfoPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_tGenInfoPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_tGenInfoPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_00438DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00438DF0 */
