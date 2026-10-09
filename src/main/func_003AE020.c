/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00397840(int, int, int);

void func_003AE020(int a0, float f12) {
    int at, v1;
    int cond;

    v1 = *(int*)(char*)a0;
    at = (unsigned int)v1 < (unsigned int)4;
    cond = at == 0;
    if (cond) goto L003AE048;
    v1 = v1 << 2;
    v1 = v1 + a0;
    *(float*)(char*)(v1 + 4) = f12;
    v1 = *(int*)(char*)a0;
    v1 = v1 + 1;
    *(int*)(char*)a0 = v1;
L003AE048:;
    goto ret;
ret:;
}

void func_003AE050(int a0) {
    int loc[8];
    int a1, a2, s0, v0, v1;

    a2 = 0;
    s0 = a0;
    a0 = (int)loc;
    v0 = func_00397840(a0, a1, a2);
    v1 = *(int*)(char*)loc;
    *(int*)(char*)s0 = v1;
    v1 = *(int*)((char*)loc + 4);
    *(int*)(char*)(s0 + 4) = v1;
    v1 = *(int*)((char*)loc + 8);
    *(int*)(char*)(s0 + 8) = v1;
    v1 = *(int*)((char*)loc + 12);
    *(int*)(char*)(s0 + 12) = v1;
    v1 = *(int*)((char*)loc + 16);
    *(int*)(char*)(s0 + 16) = v1;
    v1 = *(int*)((char*)loc + 20);
    *(int*)(char*)(s0 + 20) = v1;
    goto ret;
ret:;
}

int func_003AE0B0(int a0, int a1) {
    *(int*)((char*)a0) = *(int*)(char*)a1;
    *(int*)((char*)a0 + 4) = *(int*)((char*)a1 + 4);
    *(int*)((char*)a0 + 8) = *(int*)((char*)a1 + 8);
    *(int*)((char*)a0 + 12) = *(int*)((char*)a1 + 12);
    *(int*)((char*)a0 + 16) = *(int*)((char*)a1 + 16);
    *(int*)((char*)a0 + 20) = *(int*)((char*)a1 + 20);
    return a0;
}

void func_003AE0F0(int a0, int a1) {
    int loc[8];
    int a2, s0, v0, v1;

    a2 = *(int*)(char*)(a1 + 20);
    s0 = a0;
    a0 = (int)loc;
    v0 = func_00397840(a0, a1, a2);
    v1 = *(int*)(char*)loc;
    *(int*)(char*)s0 = v1;
    v1 = *(int*)((char*)loc + 4);
    *(int*)(char*)(s0 + 4) = v1;
    v1 = *(int*)((char*)loc + 8);
    *(int*)(char*)(s0 + 8) = v1;
    v1 = *(int*)((char*)loc + 12);
    *(int*)(char*)(s0 + 12) = v1;
    v1 = *(int*)((char*)loc + 16);
    *(int*)(char*)(s0 + 16) = v1;
    v1 = *(int*)((char*)loc + 20);
    *(int*)(char*)(s0 + 20) = v1;
    goto ret;
ret:;
}
