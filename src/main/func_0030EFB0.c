/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0030EFB0(int a0, int a1) {
    int v0;
    int cond;

    cond = a0 == 0;
    v0 = 0 + 2;
    if (cond) goto L0030EFC8;
    cond = a1 == 0;
    if (cond) goto L0030EFC8;
    *(int*)(char*)(a0 + 92) = a1;
    v0 = 0;
L0030EFC8:;
    goto ret;
ret:
    return v0;
}
