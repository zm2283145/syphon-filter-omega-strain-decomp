/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_0042A640(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* func_0042A660(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0042A670(Iter* out, PtrVec* v) {
    out->p = v->data;
}
