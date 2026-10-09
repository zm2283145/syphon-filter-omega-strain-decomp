/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0044F2E0(int, int);

void func_00450EC0(int a0, int a1) {
    int at, v0, v1;
    int cond;

    v1 = *(int*)(char*)(a0 + 60);
    at = a1 < v1;
    cond = at == 0;
    if (cond) goto L00450EE0;
    a0 = a0 + 56;
    v0 = func_0044F2E0(a0, a1);
L00450EE0:;
    goto ret;
ret:;
}
