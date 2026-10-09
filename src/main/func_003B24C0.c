/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_003B24C0(void* self) {
    return self;
}

int func_003B24D0(char* self) {
    return *(int*)(self + 0);
}

void AnimRoot_AccumAngular(int a0, float f12, float f13) {
    *(float*)((char*)a0 + 256) = (*(float*)((char*)a0 + 256) + (f12 * f13));
}

int func_003B2500(char* self) {
    return *(int*)(self + 0);
}

void func_003B2510(int a0, int a1) {
    float tmp0;
    float tmp1;
    float tmp2;

    tmp0 = *(float*)((char*)a1 + 16);
    tmp1 = *(float*)((char*)a1 + 12);
    tmp2 = *(float*)((char*)a1 + 8);
    *(float*)((char*)a0) = tmp2;
    *(float*)((char*)a0 + 4) = tmp1;
    *(float*)((char*)a0 + 8) = tmp0;
    *(int*)((char*)a0 + 12) = 0;
}

int func_003B2530(char* self) {
    return *(int*)(self + 192);
}
