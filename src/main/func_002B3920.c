/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_002B3920(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_002B3930(Iter* out, Tree* t) {
    out->p = &t->header;
}
