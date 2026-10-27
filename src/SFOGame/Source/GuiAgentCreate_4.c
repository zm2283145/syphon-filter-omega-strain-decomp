/*
 * SFOGame/Source/GuiAgentCreate: 1 file, 0028C090
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0028C090 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentCreate.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* cLListIterator_GuiWidgetPtr_ctor_listR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_GuiWidgetPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_GuiWidgetPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_0028C090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028C090 */
