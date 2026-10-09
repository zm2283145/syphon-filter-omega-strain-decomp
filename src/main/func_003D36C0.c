/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003D36C0(int a0, int a1, int a2) {
    *(int*)((char*)a0 + 244) = (a2 & 255);
}

unsigned char func_003D36D0(unsigned char* self) {
    return self[16];
}

int func_003D36E0(char* self) {
    return *(int*)(self + 12);
}

int func_003D36F0(char* self) {
    return *(int*)(self + 8);
}
