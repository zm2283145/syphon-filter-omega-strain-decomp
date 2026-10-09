/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0013A8D0(int a0) {
    int v0;
    int cond;

    v0 = *(int*)((char*)a0 + 72);
    v0 = v0 + 1;
    cond = v0 != 0;
    *(int*)((char*)a0 + 72) = v0;
    if (cond) goto L0013A8E8;
    v0 = 0 + 1;
    *(int*)((char*)a0 + 72) = v0;
L0013A8E8:;
    v0 = *(int*)((char*)a0 + 72);
    goto ret;
ret:
    return v0;
}
