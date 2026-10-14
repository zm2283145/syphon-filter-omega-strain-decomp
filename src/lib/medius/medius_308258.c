/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00308258(int a0, int a1) {
    int v0;
    int cond;

    a1 = a1 & 255;
    cond = a0 == 0;
    v0 = 0 + 1;
    if (cond) goto L0030826C;
    *(char*)((char*)a0 + 68) = a1;
    v0 = 0;
L0030826C:;
    goto ret;
ret:
    return v0;
}
