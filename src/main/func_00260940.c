/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

unsigned char func_00260940(unsigned char* self) {
    return self[1];
}

void func_00260950(int a0, float f12, float f13, float f14, float f15) {
    *(float*)((char*)a0 + 8) = f12;
    *(float*)((char*)a0 + 12) = f13;
    *(float*)((char*)a0 + 16) = f14;
    *(float*)((char*)a0 + 20) = f15;
}

void func_00260970(int a0) {
    *(int*)((char*)a0 + 4) = 0;
    *(int*)((char*)a0 + 20) = 0;
    *(int*)((char*)a0 + 16) = 0;
    *(int*)((char*)a0 + 12) = 0;
    *(int*)((char*)a0 + 8) = 0;
    *(char*)((char*)a0) = 0;
    *(char*)((char*)a0 + 1) = 0;
}
