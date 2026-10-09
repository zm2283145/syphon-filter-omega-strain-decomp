/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

float func_00291720(char* self) {
    return *(float*)(self + 4);
}

int func_00291730(int a0, int a1) {
    *(float*)((char*)a0) = *(float*)(char*)a1;
    *(float*)((char*)a0 + 4) = *(float*)((char*)a1 + 4);
    *(float*)((char*)a0 + 8) = *(float*)((char*)a1 + 8);
    *(float*)((char*)a0 + 12) = *(float*)((char*)a1 + 12);
    *(float*)((char*)a0 + 16) = *(float*)((char*)a1 + 16);
    *(float*)((char*)a0 + 20) = *(float*)((char*)a1 + 20);
    return a0;
}
