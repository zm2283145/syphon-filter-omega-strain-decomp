/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E09B0[];
extern char D_004E0B40[];
extern char D_00572130[];
extern int ScalarCollection_Init(int);

int func_0041F690(int a0) {
    int s0, v0, v1;

    v1 = (int)D_004E09B0;
    *(int*)(char*)a0 = v1;
    v1 = *(int*)(char*)D_00572130;
    v0 = (int)D_004E0B40;
    s0 = a0;
    v1 = v1 + 1;
    *(int*)(char*)D_00572130 = v1;
    *(int*)(char*)a0 = v0;
    *(int*)(char*)(a0 + 4) = 0;
    *(int*)(char*)(a0 + 8) = 0;
    *(int*)(char*)(a0 + 12) = 0;
    a0 = s0 + 40;
    v0 = ScalarCollection_Init(a0);
    *(int*)(char*)(s0 + 52) = 0;
    a0 = 0 + 38;
    *(int*)(char*)(s0 + 56) = 0;
    v1 = 0 + -1;
    *(int*)(char*)(s0 + 60) = 0;
    v0 = s0;
    *(int*)(char*)(s0 + 64) = 0;
    *(short*)(char*)(s0 + 20) = a0;
    *(int*)(char*)(s0 + 16) = v1;
    *(int*)(char*)(s0 + 28) = 0;
    *(int*)(char*)(s0 + 32) = 0;
    *(int*)(char*)(s0 + 36) = 0;
    *(int*)(char*)(s0 + 52) = 0;
    *(int*)(char*)(s0 + 56) = 0;
    *(int*)(char*)(s0 + 60) = 0;
    *(int*)(char*)(s0 + 64) = 0;
    *(int*)(char*)(s0 + 68) = s0;
    *(short*)(char*)(s0 + 22) = 0;
    *(short*)(char*)(s0 + 24) = 0;
    goto ret;
ret:
    return v0;
}
