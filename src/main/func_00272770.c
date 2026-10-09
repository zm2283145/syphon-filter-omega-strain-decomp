/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_00272770(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00272780(Iter* out, Tree* t) {
    out->p = &t->header;
}
