/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_001CF140(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_001CF150(Iter* out, PtrVec* v) {
    out->p = v->data;
}
