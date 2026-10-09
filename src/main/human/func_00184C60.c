/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00184C60(int a0, int a1) {
    int v1;
    int cond;

    v1 = *(int*)(char*)(a0 + 13700);
    cond = v1 == 0;
    if (cond) goto L00184C70;
    *(char*)(char*)(v1 + 50) = a1;
L00184C70:;
    goto ret;
ret:;
}
