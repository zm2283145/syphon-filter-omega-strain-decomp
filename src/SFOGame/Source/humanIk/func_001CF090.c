/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

int* std_vector_imp_cXformNodePtr_1_end(PtrVec* v) {
    return v->data + v->count;
}

void std_vector_cXformNodePtr_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* std_vector_imp_cXformNodePtr_1_begin(PtrVec* v) {
    return v->data;
}

int cArray_cXformNodePtr_ConstIterator_opMul(Word* w) {
    return w->value;
}

void cArray_cXformNodePtr_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void cArray_cXformNodePtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

/* End iterator of an array of 0x1D0-byte records. */
void std_vector_cBone_end(Elem1D0Iter* out, Vec1D0Array* v) {
    int count;
    Elem1D0* data;

    count = v->count;
    data = v->data;
    out->p = data + count;
}

Word* cArray_cBone_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_cBone_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
