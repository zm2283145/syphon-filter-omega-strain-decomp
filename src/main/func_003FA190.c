/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003FA190(int a0, float f12) {
    int v1;
    int cond;

    v1 = *(int*)(char*)(a0 + 1292);
    cond = v1 == 0;
    if (cond) goto L003FA1A0;
    *(float*)(char*)(v1 + 72) = f12;
L003FA1A0:;
    goto ret;
ret:;
}
