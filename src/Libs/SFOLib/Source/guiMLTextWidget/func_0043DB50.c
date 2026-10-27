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
