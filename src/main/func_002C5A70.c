/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_002C5A70(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_002C5A80(int a0, int a1) {
    int a2, a3, v0, v1;
    int cond;

    a3 = 0;
    a2 = a0;
L002C5A88:;
    v1 = *(int*)(char*)a1;
    a3 = a3 + 3;
    v0 = a3 < 9;
    *(int*)(char*)a2 = v1;
    v1 = *(int*)(char*)(a1 + 4);
    *(int*)(char*)(a2 + 4) = v1;
    v1 = *(int*)(char*)(a1 + 8);
    *(int*)(char*)(a2 + 8) = v1;
    a1 = a1 + 12;
    cond = v0 != 0;
    a2 = a2 + 12;
    if (cond) goto L002C5A88;
    v0 = a0;
    goto ret;
ret:
    return v0;
}
