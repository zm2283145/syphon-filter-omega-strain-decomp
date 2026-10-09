/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003AC4F0(int, int);
extern int func_003AC520(int);

int func_003AC4A0(int a0, int a1) {
    int s0, v0, v1;

    v0 = *(int*)(char*)(a0 + 16);
    s0 = a1 + v0;
    v0 = func_003AC520(a0);
    a1 = (unsigned int)s0 >> 3;
    a0 = v0;
    v0 = func_003AC4F0(a0, a1);
    a0 = s0 & 7;
    v0 = *(int*)(char*)v0;
    v1 = a0 << 5;
    v1 = v1 - a0;
    v1 = v1 << 3;
    v0 = v0 + v1;
    goto ret;
ret:
    return v0;
}
