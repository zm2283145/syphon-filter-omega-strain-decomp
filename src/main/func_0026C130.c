/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0048B2A8[];
extern char D_0048B2B0[];
extern char D_004FF070[];
extern char D_004FF074[];
extern char D_004FF078[];
extern char D_004FF07C[];

void func_0026C130(int a0) {
    float tmp0;

    *(int*)D_004FF074 = 0;
    *(int*)D_004FF078 = 0;
    *(int*)D_004FF07C = 0;
    *(int*)D_004FF070 = 1051931443;
    tmp0 = *(float*)D_0048B2A8;
    *(float*)D_0048B2B0 = tmp0;
    *(int*)((char*)a0 + 96) = 0;
    *(int*)((char*)a0 + 100) = 0;
    *(int*)((char*)a0 + 144) = 0;
    *(int*)((char*)a0 + 148) = 0;
}
