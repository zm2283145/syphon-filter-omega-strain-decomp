/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00412150(int a0, int a1) {
    *(float*)((char*)a0) = *(float*)(char*)a1;
    *(float*)((char*)a0 + 4) = *(float*)((char*)a1 + 4);
    *(float*)((char*)a0 + 8) = *(float*)((char*)a1 + 8);
    *(float*)((char*)a0 + 12) = *(float*)((char*)a1 + 12);
    return a0;
}

void* func_00412180(char* self) {
    return self + 80;
}

int func_00412190(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 104);
    tmp1 = *(int*)((char*)a0 + 96);
    return ((tmp1 + (tmp0 * 320)) + (a1 * 100));
}
