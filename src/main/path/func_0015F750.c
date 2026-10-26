/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_list_cPathSystemRequestPtr_end_void(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* cLListIterator_cPathSystemRequestPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cPathSystemRequestPtr_begin_void(Iter* out, PtrVec* v) {
    out->p = v->data;
}
