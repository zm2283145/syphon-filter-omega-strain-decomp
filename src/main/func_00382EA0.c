/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_00382EA0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00382EB0(Iter* out, Tree* t) {
    out->p = &t->header;
}

int func_00382EC0(int a0, int a1) {
    *(int*)((char*)a0) = a1;
    return a0;
}
