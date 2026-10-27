/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cArray_charPtr_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

Iter* cArray_charPtr_Iterator_opInc(Iter* it) {
    it->p++;
    return it;
}

Word* cArray_charPtr_Iterator_ctor_IteratorR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int cArray_charPtr_Iterator_opMul(char* self) {
    return *(int*)(self + 0);
}

void cArray_charPtr_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void cArray_charPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* cArray_charPtr_Iterator_ctor_wrapiteratorR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_charPtr_end(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}
