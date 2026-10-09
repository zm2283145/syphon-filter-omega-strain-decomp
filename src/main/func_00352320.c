/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003527A0(int, int);

int func_00352320(int a0, int a1) {
    int s0, s1, s2, v0, v1;

    s2 = a0;
    s1 = a1;
    v0 = *(int*)(char*)a1;
    s0 = s2 + 4;
    *(int*)(char*)a0 = v0;
    a1 = s1 + 4;
    a0 = s0;
    v0 = func_003527A0(a0, a1);
    v1 = *(unsigned char*)(char*)(s1 + 16);
    v0 = s2;
    *(char*)(char*)(s0 + 12) = v1;
    goto ret;
ret:
    return v0;
}
