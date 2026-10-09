/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E0DC0[];
extern int func_00424C50(int);
extern int func_00427000(int);

int func_00426CC0(int a0) {
    int s0, s1, v0, v1;

    s1 = a0;
    v0 = func_00424C50(a0);
    s0 = s1 + 176;
    v0 = (int)D_004E0DC0;
    a0 = s0;
    *(int*)(char*)s1 = v0;
    v0 = func_00427000(a0);
    v0 = 0 + 1;
    a0 = 0 + 2;
    *(char*)(char*)(s0 + 12) = v0;
    v1 = 0x3f800000;
    *(int*)(char*)(s1 + 144) = 0;
    v0 = s1;
    *(int*)(char*)(s1 + 148) = 0;
    *(char*)(char*)(s1 + 152) = a0;
    *(int*)(char*)(s1 + 160) = v1;
    *(int*)(char*)(s1 + 164) = v1;
    *(int*)(char*)(s1 + 168) = v1;
    *(int*)(char*)(s1 + 172) = v1;
    goto ret;
ret:
    return v0;
}
