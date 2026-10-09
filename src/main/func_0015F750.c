/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_0015F750(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_0015F760(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0015F770(Iter* out, PtrVec* v) {
    out->p = v->data;
}
