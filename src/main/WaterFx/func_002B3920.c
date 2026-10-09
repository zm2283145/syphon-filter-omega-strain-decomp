/*
 * Matched functions (byte-identical with the retail executable).
 * Container iterator helpers.
 */

#include "types.h"
#include "WaterFx_types.h"

Word* func_002B3920(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_002B3930(Iter* out, Tree* t) {
    out->p = &t->header;
}

WaterListIter* func_002B3940(WaterListIter* it, WaterListLink* node) {
    it->node = node;
    return it;
}

/* Address of the list sentinel (end()). */
WaterListLink* func_002B3950(WaterList* list) {
    return &list->head;
}
