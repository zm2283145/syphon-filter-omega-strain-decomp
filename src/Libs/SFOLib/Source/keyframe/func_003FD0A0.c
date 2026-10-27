/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* cArray_cAnimatorPtr_ConstIterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_cAnimatorPtr_end_void_2(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void std_vector_cAnimatorPtr_pointer2iterator_cAnimatorPPR_2(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int std_vector_imp_cAnimatorPtr_1_begin_void_2(PtrVec* v) {
    return (int)v->data;
}
