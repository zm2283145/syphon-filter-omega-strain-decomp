/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003E1090(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* func_003E10B0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003E10C0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
