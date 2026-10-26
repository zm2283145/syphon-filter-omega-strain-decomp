/*
 * Matched functions (byte-identical with the retail executable).
 * Container iterator helpers.
 */

#include "types.h"

void std_list_cElementPtr_end_void(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* cLListIterator_cElementPtr_ctor_listR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cElementPtr_begin_void(Iter* out, PtrVec* v) {
    out->p = v->data;
}
