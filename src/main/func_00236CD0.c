/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003A2400(int, int, int, float);

void func_00236CD0(int a0) {
    int a1, a2, s0, v0, v1;
    float f12;
    int cond;

    s0 = a0;
    a0 = *(int*)(char*)(a0 + 12);
    cond = a0 == 0;
    a1 = s0 + 16;
    if (cond) goto L00236D08;
    a2 = 0;
    v0 = func_003A2400(a0, a1, a2, f12);
    v1 = *(int*)(char*)(s0 + 12);
    v1 = *(int*)(char*)(v1 + 28);
    cond = v1 != 0;
    v1 = 0 + 1;
    if (cond) goto L00236D08;
    *(char*)(char*)(s0 + 1) = v1;
L00236D08:;
    goto ret;
ret:;
}
