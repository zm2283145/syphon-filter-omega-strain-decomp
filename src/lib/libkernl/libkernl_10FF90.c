/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0010F988(int, int, int, int, int, int);

int func_0010FF90(int a0, int a1, int a2, int a3) {
    int t0, t1, v0, v1;

    a1 = a3;
    a0 = 0x80000000;
    a0 = a0 | 0x8;
    a2 = 0 + 64;
    a3 = *(int*)((char*)a1 + 36);
    t0 = *(int*)((char*)a1 + 40);
    t1 = *(int*)((char*)a1 + 44);
    v0 = func_0010F988(a0, a1, a2, a3, t0, t1);
    v1 = 0 + 2048;
    if (v0 != 0) v1 = 0;
    v0 = v1;
    goto ret;
ret:
    return v0;
}
