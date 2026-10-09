/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_002D79A0(int a0, int a1) {
    float tmp0;
    float tmp1;
    float tmp2;

    tmp0 = *(float*)((char*)a0 + 56);
    *(float*)((char*)a1) = tmp0;
    tmp1 = *(float*)((char*)a0 + 60);
    *(float*)((char*)a1 + 4) = tmp1;
    tmp2 = *(float*)((char*)a0 + 64);
    *(float*)((char*)a1 + 8) = tmp2;
    *(int*)((char*)a1 + 12) = 1065353216;
}
