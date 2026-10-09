/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003E9DF0(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_003E9E00(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003E9E10(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* func_003E9E20(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
