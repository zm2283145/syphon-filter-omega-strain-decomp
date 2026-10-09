/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_003FD0A0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003FD0B0(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_003FD0D0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int func_003FD0E0(PtrVec* v) {
    return (int)v->data;
}
