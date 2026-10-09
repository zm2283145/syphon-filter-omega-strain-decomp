/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_0032D040(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0032D050(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}
