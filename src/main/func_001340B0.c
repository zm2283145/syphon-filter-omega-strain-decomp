/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* Physical_GetPositionPtr(char* self) {
    return self + 16;
}

void func_001340C0(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* func_001340D0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_001340E0(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void* func_00134100(char* self) {
    return self + 4;
}
