/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_00220490(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_002204A0(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_002204B0(void* self) {
    return self;
}
