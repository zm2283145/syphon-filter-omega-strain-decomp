/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0030EBC8(int a0) {
    int v0, v1;
    int cond;

    cond = a0 == 0;
    v0 = 0 + 2;
    if (cond) goto L0030EBE8;
    v1 = *(int*)((char*)a0 + 80);
    cond = v1 != 0;
    v0 = 0 + 7;
    if (cond) goto L0030EBE8;
    v1 = 0 + 1;
    v0 = 0;
    *(char*)((char*)a0 + 76) = v1;
L0030EBE8:;
    goto ret;
ret:
    return v0;
}
