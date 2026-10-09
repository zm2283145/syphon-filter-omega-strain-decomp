/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_00432720(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00432730(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_00432740(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
