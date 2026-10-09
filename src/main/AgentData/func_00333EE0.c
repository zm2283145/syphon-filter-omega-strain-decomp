/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00333EE0(int a0, int a1) {
    int at, v0;
    int cond;

    v0 = a1 & 255;
    at = v0 < 31;
    cond = at == 0;
    if (cond) goto L00333F00;
    v0 = v0 << 2;
    v0 = v0 + a0;
    v0 = *(int*)(char*)(v0 + 8);
    goto L00333F04;
L00333F00:;
    v0 = 0;
L00333F04:;
    goto ret;
ret:
    return v0;
}
