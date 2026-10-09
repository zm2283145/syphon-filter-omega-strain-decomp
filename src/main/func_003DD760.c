/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_003DD760(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003DD770(Iter* out, Tree* t) {
    out->p = &t->header;
}

int* func_003DD780(PtrVec* v, int i) {
    return v->data + i;
}
