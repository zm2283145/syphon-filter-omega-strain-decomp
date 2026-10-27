/*
 * Libs/SFOLib/Source/guiMLTextWidget: 1 file, 0043DB50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043DB50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after GenInfoObject.cc (ends 0x0043BA00),
 * before guiMLTextWidget.cc (starts 0x0043DB80).
 */

#include "types.h"

Word* cLListIterator_charPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_charPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_charPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_0043DB50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043DB50 */
