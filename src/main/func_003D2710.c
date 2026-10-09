/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00138EA0(int, int, int, int);
extern int func_003D27B0(int, int);

Word* func_003D2710(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_003D2720(int a0, int a1) {
    return ((unsigned int)(0) < (unsigned int)((*(int*)(char*)a0 ^ *(int*)(char*)a1)));
}

int func_003D2740(int a0) {
    *(int*)((char*)a0) = *(int*)((char*)*(int*)(char*)a0 + 4);
    return a0;
}

int func_003D2760(int a0) {
    return (*(int*)(char*)a0 + 8);
}

int func_003D2770(int a0, int a1) {
    *(float*)((char*)a0) = *(float*)(char*)a1;
    return a0;
}

void* func_003D2780(void* self) {
    return self;
}

void func_003D2790(int a0, int a1) {
    int loc[1];
    int v0;

    *(int*)(char*)loc = a1;
    a1 = (int)loc;
    v0 = func_003D27B0(a0, a1);
    goto ret;
ret:;
}

int func_003D27B0(int a0, int a1) {
    int loc[2];
    int a2, a3, v0;

    a3 = a1;
    a1 = a0;
    v0 = *(int*)(char*)(a0 + 8);
    a2 = (int)loc;
    *(int*)(char*)loc = v0;
    a0 = (int)((char*)loc + 4);
    v0 = func_00138EA0(a0, a1, a2, a3);
    goto ret;
ret:
    return v0;
}
