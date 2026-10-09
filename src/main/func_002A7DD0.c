/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_002A7DD0(int a0, int a1) {
    int v1;
    int cond;

    v1 = *(int*)(char*)(a0 + 136);
    cond = v1 == 0;
    if (cond) goto L002A7DE0;
    *(int*)(char*)(v1 + 132) = a1;
L002A7DE0:;
    goto ret;
ret:;
}
