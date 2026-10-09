/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E0FC0[];
extern char D_00539248[];
extern int func_003813A0(int, int, int);
extern int func_0041EBF0(int);
extern int func_0041EFA0(int);
extern void func_0041F690(int);
extern int func_0043C730(int);

void func_0043CAA0(int a0) {
    int a1, a2, s0, v0, v1;
    int cond;

    s0 = a0;
    v0 = func_0041EBF0(a0);
    a1 = *(int*)(char*)(s0 + 72);
    v1 = 0 + -1;
    cond = a1 == v1;
    if (cond) goto L0043CAD8;
    a0 = *(int*)(char*)D_00539248;
    a2 = 0;
    v0 = func_003813A0(a0, a1, a2);
    v1 = 0 + -1;
    *(int*)(char*)(s0 + 72) = v1;
L0043CAD8:;
    goto ret;
ret:;
}

int func_0043CAF0(int a0) {
    int tmp2;

    func_0041EFA0(a0);
    tmp2 = func_0043C730(a0);
    return tmp2;
}

int func_0043CB20(int a0) {
    func_0041F690(a0);
    *(int*)((char*)a0) = (int)D_004E0FC0;
    *(int*)((char*)a0 + 80) = 0;
    *(int*)((char*)a0 + 84) = 0;
    *(int*)((char*)a0 + 88) = 0;
    *(int*)((char*)a0 + 72) = -1;
    *(int*)((char*)a0 + 76) = 0;
    *(int*)((char*)a0 + 96) = 1065353216;
    *(int*)((char*)a0 + 100) = 1065353216;
    *(int*)((char*)a0 + 104) = 1065353216;
    *(int*)((char*)a0 + 108) = 1065353216;
    *(int*)((char*)a0 + 112) = 1065353216;
    return a0;
}
