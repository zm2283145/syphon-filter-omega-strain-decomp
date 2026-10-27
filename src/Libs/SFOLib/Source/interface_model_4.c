/*
 * Libs/SFOLib/Source/interface_model: 1 file, 003ED850
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003ED850 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_list_cInterfaceElementPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* cLListIterator_cInterfaceElementPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cInterfaceElementPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_003ED850(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ED850 */
