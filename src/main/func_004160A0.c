/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E08D0[];
extern int ScalarCollection_Init(int);
extern int func_0041F690(int);

int func_004160A0(int a0) {
    int a1, s0, v0, v1;

    s0 = a0;
    v0 = func_0041F690(a0);
    a0 = s0 + 84;
    v0 = (int)D_004E08D0;
    *(int*)(char*)s0 = v0;
    v0 = ScalarCollection_Init(a0);
    *(char*)((char*)s0 + 80) = 0;
    a0 = 0 + 1;
    *(int*)((char*)s0 + 72) = 0;
    v1 = 0 | 61440;
    *(int*)((char*)s0 + 76) = 0;
    v0 = s0;
    *(char*)((char*)s0 + 96) = 0;
    *(int*)((char*)s0 + 100) = 0;
    a1 = *(unsigned short*)((char*)s0 + 20);
    a1 = a1 & 65531;
    *(short*)((char*)s0 + 20) = a1;
    *(char*)((char*)s0 + 81) = a0;
    *(char*)((char*)s0 + 82) = a0;
    *(int*)((char*)s0 + 104) = v1;
    goto ret;
ret:
    return v0;
}
