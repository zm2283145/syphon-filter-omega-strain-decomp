/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

float func_003751A0(char* self) {
    return *(float*)(self + 52);
}

float func_003751B0(char* self) {
    return *(float*)(self + 56);
}

float func_003751C0(int a0) {
    return *(float*)((char*)((*(int*)((char*)a0 + 136) << 2) + a0) + 120);
}

float func_003751E0(int a0) {
    return *(float*)((char*)((*(int*)((char*)a0 + 136) << 2) + a0) + 104);
}

void* func_00375200(char* self) {
    return self + 3968;
}
