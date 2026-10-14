/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00301898(int a0, int a1) {
    int v0;
    int cond;

    a1 = a1 << 24;
    v0 = 0 + 2;
    cond = a0 == 0;
    a1 = a1 >> 24;
    if (cond) goto L003018B0;
    *(char*)(char*)a0 = a1;
    v0 = 0;
L003018B0:;
    goto ret;
ret:
    return v0;
}
