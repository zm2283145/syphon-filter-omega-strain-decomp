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
