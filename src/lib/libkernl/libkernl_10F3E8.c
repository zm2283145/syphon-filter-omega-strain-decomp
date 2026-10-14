/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E2F00[];

int func_0010F3E8(int a0, int a1) {
    int tmp0;
    int tmp1;
    int tmp2;

    tmp0 = *(int*)((char*)a0 + 16);
    tmp1 = *(int*)((char*)a1 + 28);
    tmp2 = *(int*)((char*)a0 + 20);
    *(int*)((char*)((tmp0 << 2) + tmp1)) = tmp2;
    return ((tmp0 << 2) + tmp1);
}

void func_0010F408(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 16);
    *(int*)((char*)a1 + 8) = tmp0;
}

int func_0010F418(int a0) {
    int tmp0;

    tmp0 = *(int*)(char*)((a0 << 2) + (int)D_004E2F00);
    return tmp0;
}

int func_0010F430(int a0, int a1) {
    *(int*)((char*)((a0 << 2) + (int)D_004E2F00)) = a1;
    return a1;
}
