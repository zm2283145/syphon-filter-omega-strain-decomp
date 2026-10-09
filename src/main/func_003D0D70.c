/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003D0D70(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_003D0D80(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003D0D90(Iter* out, PtrVec* v) {
    out->p = v->data;
}
