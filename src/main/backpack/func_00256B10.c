/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_00256B10(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00256B20(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_00256B30(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
