/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_vector_FuncDefPtr_end(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* cArray_FuncDefPtr_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_FuncDefPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
