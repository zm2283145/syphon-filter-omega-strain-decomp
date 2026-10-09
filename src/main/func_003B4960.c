/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00139200(int, int, int, int);

int func_003B4960(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return func_00139200(a0, (tmp1 + (tmp0 << 2)), 1, a1);
}

Word* func_003B4980(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003B4990(Iter* out, Tree* t) {
    out->p = &t->header;
}
