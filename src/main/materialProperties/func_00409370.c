/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00409940(int, int, int, int);

int func_00409370(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return ((tmp1 + (tmp0 * 292)) + -292);
}

int func_004093A0(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 8);
    tmp1 = *(int*)((char*)a0 + 4);
    return func_00409940(a0, (tmp0 + (tmp1 * 292)), 1, a1);
}

int func_004093D0(char* self) {
    return *(int*)(self + 4);
}
