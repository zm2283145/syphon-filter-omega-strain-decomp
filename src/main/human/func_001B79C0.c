/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_001B79C0(int a0, int a1) {
    *(float*)((char*)a0 + 16) = *(float*)(char*)a1;
}

int func_001B79D0(int a0) {
    return ((*(int*)((char*)a0 + 8) + (*(int*)((char*)a0 + 4) << 3)) + -8);
}
