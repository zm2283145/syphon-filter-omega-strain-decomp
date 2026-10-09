/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00452F30(int a0, int a1, int a2) {
    int v0, v1;
    int cond;

    v1 = *(int*)(char*)(a0 + 9556);
    cond = v1 == 0;
    if (cond) goto L00452F50;
    a0 = a1;
    a1 = a2;
    v0 = ((int (*)(int, int))v1)(a0, a1);
L00452F50:;
    goto ret;
ret:;
}

void func_00452F60(char* self, int value) {
    *(int*)(self + 9556) = value;
}
