/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00198EF0(int, int);
extern int func_00198F20(int);

int func_00198E90(int a0) {
    int a1, s0, v0, v1;

    v1 = *(int*)(char*)(a0 + 16);
    v0 = *(int*)(char*)(a0 + 20);
    v0 = v1 + v0;
    s0 = v0 + -1;
    v0 = func_00198F20(a0);
    a1 = (unsigned int)s0 >> 3;
    a0 = v0;
    v0 = func_00198EF0(a0, a1);
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
