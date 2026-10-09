/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0010A0F8(int a0, int a1) {
    int v0, v1;
    int cond;

    v1 = *(int*)((char*)a0 + 8);
    a1 = a1 >> 3;
    v0 = *(int*)((char*)a0 + 36);
    v1 = v1 + a1;
    v0 = (unsigned int)v1 < (unsigned int)v0;
    cond = v0 != 0;
    if (cond) goto L0010A11C;
    v0 = *(int*)((char*)a0 + 40);
    v1 = v1 - v0;
L0010A11C:;
    v0 = v1;
    goto ret;
ret:
    return v0;
}
