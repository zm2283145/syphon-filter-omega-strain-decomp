/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* Physical_GetPositionPtr(char* self) {
    return self + 16;
}

void cArray_cHumanPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* cArray_cHumanPtr_ConstIterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void cArray_cHumanPtr_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void* cObjList_cHumanPtr_GetList(char* self) {
    return self + 4;
}
