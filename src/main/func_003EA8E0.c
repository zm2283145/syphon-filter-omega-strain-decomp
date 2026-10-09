/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_003EA8E0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003EA8F0(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_003EA900(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
