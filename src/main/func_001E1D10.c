/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00183B10(int, int);

float func_001E1D10(char* self) {
    return *(float*)(self + 60);
}

void func_001E1D20(int a0, int a1, int a2) {
    *(int*)((char*)a0) = a1;
    *(int*)((char*)a0 + 4) = a2;
}

int func_001E1D30(int a0) {
    return ((unsigned int)(0) < (unsigned int)((*(unsigned char*)((char*)a0 + 12) & 128)));
}

int func_001E1D40(int a0) {
    return ((unsigned int)(0) < (unsigned int)((*(unsigned char*)((char*)a0 + 11) & 128)));
}

int func_001E1D50(void) {
    return 0;
}

int func_001E1D60(int a0) {
    return *(int*)((char*)*(int*)(char*)a0 + 80);
}

void* func_001E1D70(char* self) {
    return self + 12;
}

int func_001E1D80(int a0, int a1) {
    int loc[1];
    int s0, v0, v1;

    v0 = *(int*)(char*)(a0 + 4);
    s0 = a1;
    a1 = (int)loc;
    a0 = *(int*)(char*)v0;
    v0 = *(int*)(char*)(a0 + 32);
    *(int*)(char*)loc = v0;
    v0 = func_00183B10(a0, a1);
    v1 = s0 << 4;
    v0 = v0 + v1;
    goto ret;
ret:
    return v0;
}
