/*
 * Libs/SFOLib/Source/specfx: 1 file, 003EC3B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EC3B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Container iterator helpers.
 */

#include "types.h"

Word* cLListIterator_cSfxSchedulerPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cSfxSchedulerPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_cSfxSchedulerPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_003EC3B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EC3B0 */
