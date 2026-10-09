/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0040E5D0(int);

void func_0040E320(int a0) {
    int s0, v0, v1;
    int cond;

    s0 = a0;
    a0 = *(int*)(char*)a0;
    v0 = func_0040E5D0(a0);
    v1 = (unsigned int)0 < (unsigned int)v0;
    *(char*)(char*)(s0 + 4) = v1;
    v1 = *(unsigned char*)(char*)(s0 + 4);
    v1 = (unsigned int)0 < (unsigned int)v1;
    v1 = v1 ^ 1;
    cond = v1 == 0;
    if (cond) goto L0040E358;
    *(char*)(char*)(s0 + 12) = 0;
L0040E358:;
    goto ret;
ret:;
}
