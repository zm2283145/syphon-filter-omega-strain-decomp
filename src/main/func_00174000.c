/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_vector_cObjectId_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* std_vector_imp_cObjectId_end(PtrVec* v) {
    return v->data + v->count;
}

int cArray_cObjectId_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* cArray_cObjectId_Iterator_opInc(Iter* it) {
    it->p++;
    return it;
}

Word* cArray_cObjectId_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Word equality. */
int opEq(Word* a, Word* b) {
    return a->value == b->value;
}

int* cArray_cObjectId_Iterator_opMul(Iter* it) {
    return it->p;
}

void cArray_cObjectId_End_void(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void cArray_cObjectId_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
