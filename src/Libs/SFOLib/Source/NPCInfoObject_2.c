/*
 * Libs/SFOLib/Source/NPCInfoObject: 1 file, 00432720
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00432720 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: NPCInfoObject.cc.
 */

#include "types.h"

Word* cLListIterator_tNPCInfoPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_tNPCInfoPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_tNPCInfoPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_00432720(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00432720 */
