/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0027FF60(int a0, int a1) {
    *(float*)((char*)a0) = *(float*)(char*)a1;
    *(float*)((char*)a0 + 4) = *(float*)((char*)a1 + 4);
    *(float*)((char*)a0 + 8) = *(float*)((char*)a1 + 8);
    return a0;
}

float func_0027FF80(char* self) {
    return *(float*)(self + 8);
}

void* func_0027FF90(char* self) {
    return self + 8;
}

float func_0027FFA0(char* self) {
    return *(float*)(self + 4);
}

void* func_0027FFB0(char* self) {
    return self + 4;
}
