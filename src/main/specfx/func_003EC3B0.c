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
