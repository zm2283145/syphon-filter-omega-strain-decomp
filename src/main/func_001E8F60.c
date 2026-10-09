/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001E8F60(int a0, int a1) {
    return ((unsigned int)((*(int*)(char*)a0 ^ *(int*)(char*)a1)) < (unsigned int)(1));
}

Iter* func_001E8F80(Iter* it) {
    it->p++;
    return it;
}

void func_001E8FA0(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* func_001E8FC0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_001E8FD0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
