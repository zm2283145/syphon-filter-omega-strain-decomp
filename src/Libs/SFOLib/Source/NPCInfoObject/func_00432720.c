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
