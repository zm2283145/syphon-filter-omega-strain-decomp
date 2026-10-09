/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_002FE8B0(int a0) {
    int v0, v1;
    int cond;

    cond = a0 == 0;
    v0 = 0;
    if (cond) goto L002FE8D0;
    v1 = 0 + -80;
    cond = a0 == v1;
    if (cond) goto L002FE8D0;
    v0 = 0 + -104;
    v0 = a0 ^ v0;
    v0 = (unsigned int)0 < (unsigned int)v0;
L002FE8D0:;
    goto ret;
ret:
    return v0;
}
