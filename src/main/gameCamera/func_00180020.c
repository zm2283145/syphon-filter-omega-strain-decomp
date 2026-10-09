/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00180020(int a0, int a1) {
    *(float*)((char*)a0 + 4) = (*(float*)((char*)a0 + 4) + *(float*)(char*)a1);
    *(float*)((char*)a0 + 8) = (*(float*)((char*)a0 + 8) + *(float*)(char*)a1);
    *(float*)((char*)a0 + 16) = (*(float*)((char*)a0 + 16) + *(float*)(char*)a1);
    *(float*)((char*)a0 + 24) = (*(float*)((char*)a0 + 24) + *(float*)(char*)a1);
    *(float*)((char*)a0 + 32) = (*(float*)((char*)a0 + 32) + *(float*)(char*)a1);
}

float func_00180080(void) {
    return 0.0f;
}

float Curve_ReturnZero(void) {
    return 0.0f;
}
