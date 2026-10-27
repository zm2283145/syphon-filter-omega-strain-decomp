/*
 * SFOGame/Source/WaterFx: 1 file, 002B3920
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002B3920 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Container iterator helpers.
 */

#include "types.h"
#include "WaterFx_types.h"

Word* cLListIterator_tNode_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_deleter_tNode_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

WaterListIter* std_list_deleter_tNode_generic_iterator_ctor_nodeP(WaterListIter* it, WaterListLink* node) {
    it->node = node;
    return it;
}

/* Address of the list sentinel (end()). */
WaterListLink* std_list_deleter_tNode_tail(WaterList* list) {
    return &list->head;
}
static inline void merge_flush_func_002B3920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B3920 */
