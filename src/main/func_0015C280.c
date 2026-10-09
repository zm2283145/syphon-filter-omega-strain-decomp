/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

float func_0015C280(char* self) {
    return *(float*)(self + 12);
}

float func_0015C290(char* self) {
    return *(float*)(self + 8);
}

float func_0015C2A0(char* self) {
    return *(float*)(self + 4);
}

float func_0015C2B0(char* self) {
    return *(float*)(self + 0);
}

void func_0015C2C0(int a0, int a1) {
    float tmp0;
    float tmp1;
    float tmp2;

    tmp0 = *(float*)((char*)a1 + 136);
    tmp1 = *(float*)((char*)a1 + 132);
    tmp2 = *(float*)((char*)a1 + 128);
    *(float*)((char*)a0) = tmp2;
    *(float*)((char*)a0 + 4) = tmp1;
    *(float*)((char*)a0 + 8) = tmp0;
    *(int*)((char*)a0 + 12) = 1065353216;
}
