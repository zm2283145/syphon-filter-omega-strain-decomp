/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003ED850(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_003ED860(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003ED870(Iter* out, PtrVec* v) {
    out->p = v->data;
}
