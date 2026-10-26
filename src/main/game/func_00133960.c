/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void PtrVec_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void PtrVec_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cObjList_cGOBJPtr_GetList(char* self) {
    return self + 4;
}
