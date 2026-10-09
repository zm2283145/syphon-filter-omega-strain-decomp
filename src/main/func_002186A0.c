/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_002186A0(int a0) {
    *(int*)((char*)a0 + 4) = (*(int*)((char*)a0 + 4) + -1);
}

int func_002186B0(int a0, int a1) {
    *(int*)((char*)a0) = *(int*)(char*)a1;
    *(float*)((char*)a0 + 4) = *(float*)((char*)a1 + 4);
    return a0;
}

int func_002186D0(int a0, int a1) {
    return (*(int*)((char*)a0 + 8) + (a1 << 3));
}

int func_002186E0(char* self) {
    return *(int*)(self + 4);
}
