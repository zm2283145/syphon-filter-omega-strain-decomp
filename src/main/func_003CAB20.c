/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_003CAB20(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003CAB30(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* func_003CAB40(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
