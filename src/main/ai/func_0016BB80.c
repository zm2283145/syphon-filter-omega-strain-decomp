/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_0016BB80(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_0016BB90(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0016BBA0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
