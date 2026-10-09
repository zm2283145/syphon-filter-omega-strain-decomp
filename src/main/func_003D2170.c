/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_003D2170(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003D2180(Iter* out, PtrVec* v) {
    out->p = v->data;
}
