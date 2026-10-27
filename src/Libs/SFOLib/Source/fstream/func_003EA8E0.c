/*
 * Matched functions (byte-identical with the retail executable).
 * fstream.cc: copy helpers and tree end() iterator.
 */

#include "types.h"

Word* cLListIterator_cFSDataPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cFSDataPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_cFSDataPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
