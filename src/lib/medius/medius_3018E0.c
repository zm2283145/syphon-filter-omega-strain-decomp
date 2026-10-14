/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003018E0(int a0, int a1) {
    int v0;
    int cond;

    a1 = a1 & 255;
    cond = a0 == 0;
    v0 = 0 + 2;
    if (cond) goto L003018F4;
    *(char*)(char*)a0 = a1;
    v0 = 0;
L003018F4:;
    goto ret;
ret:
    return v0;
}
