/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00285390(int a0, float f12) {
    int v1;
    int cond;

    v1 = *(int*)(char*)(a0 + 108);
    cond = v1 == 0;
    if (cond) goto L002853A0;
    *(float*)(char*)(v1 + 44) = f12;
L002853A0:;
    goto ret;
ret:;
}
