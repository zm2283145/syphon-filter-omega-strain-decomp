/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_0018A6E0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0018A6F0(Iter* out, Tree* t) {
    out->p = &t->header;
}

int func_0018A700(int a0, int a1) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = a1;
    return a0;
}
