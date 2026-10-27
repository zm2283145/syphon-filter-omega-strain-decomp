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
