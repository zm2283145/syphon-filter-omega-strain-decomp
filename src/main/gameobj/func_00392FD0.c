/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

Word* cLListIterator_cSkaTransPlaybackPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cSkaTransPlaybackPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_cSkaTransPlaybackPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
