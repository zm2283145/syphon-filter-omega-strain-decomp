/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_004498C0(int);
extern int func_0044D780(int);
extern int func_00451B30(int);

void func_00442700(int a0) {
    int a1, s0, v0, v1;
    int cond;

    v1 = 0 + 4;
    a1 = *(int*)(char*)(a0 + 9564);
    cond = a1 != v1;
    s0 = a0;
    if (cond) goto L00442740;
    v1 = *(unsigned char*)(char*)(s0 + 9225);
    cond = v1 != 0;
    if (cond) goto L00442740;
    v0 = func_0044D780(a0);
    a0 = s0;
    v0 = func_004498C0(a0);
    a0 = s0;
    v0 = func_00451B30(a0);
L00442740:;
    goto ret;
ret:;
}
