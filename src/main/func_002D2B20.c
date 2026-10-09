/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_002D2B20(void) {
    return 1;
}

int func_002D2B30(void) {
    return 1;
}

void func_002D2B40(void) {
}

int func_002D2B50(void) {
    return 0;
}

int func_002D2B60(int a0) {
    int loc[4];
    int v0, v1;
    float f0, f1, f2;

    a0 = *(int*)(char*)(a0 + 480);
    v1 = 0x3f800000;
    v0 = (int)loc;
    f1 = *(float*)(char*)(a0 + 24);
    f2 = *(float*)(char*)(a0 + 20);
    f0 = *(float*)(char*)(a0 + 16);
    *(float*)(char*)loc = f0;
    *(int*)((char*)loc + 12) = v1;
    *(float*)((char*)loc + 4) = f2;
    *(float*)((char*)loc + 8) = f1;
    goto ret;
ret:
    return v0;
}

int func_002D2BA0(void) {
    return 0;
}

void func_002D2BB0(void) {
}

void func_002D2BC0(void) {
}
