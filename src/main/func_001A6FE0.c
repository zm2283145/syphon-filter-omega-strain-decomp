/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001A6FE0(char* self) {
    return *(int*)(self + 0);
}

void func_001A6FF0(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* func_001A7010(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_001A7020(Iter* out, PtrVec* v) {
    out->p = v->data;
}
