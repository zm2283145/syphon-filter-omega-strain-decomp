/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003695C0(int);

void func_0036DEC0(int a0) {
    int v0, v1;
    int cond;

    v1 = *(int*)(char*)a0;
    v1 = v1 & 1;
    cond = v1 == 0;
    if (cond) goto L0036DEE0;
    a0 = *(int*)(char*)(a0 + 152);
    v0 = func_003695C0(a0);
L0036DEE0:;
    goto ret;
ret:;
}
