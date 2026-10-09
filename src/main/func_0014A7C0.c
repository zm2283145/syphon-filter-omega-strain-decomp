/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0018C9D0(int, int, int);
extern int func_001992B0(int, int, int);

void func_0014A7C0(int a0, int a1) {
    *(char*)((char*)*(int*)((char*)a0 + 48) + 13240) = a1;
}

void func_0014A7D0(int a0) {
    *(char*)((char*)*(int*)((char*)*(int*)((char*)a0 + 48) + 13604) + 168) = 1;
}

int func_0014A7F0(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 48);
    return func_001992B0(tmp0, a1, 0);
}

int func_0014A800(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 48);
    return func_0018C9D0(tmp0, a1, 0);
}
