/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_0010B358(int a0, int a1, int a2, int a3) {
    int tmp0;
    int tmp1;
    int tmp2;
    int tmp3;

    tmp0 = *(int*)((char*)a0 + 64);
    tmp1 = *(int*)((char*)tmp0 + 172);
    *(int*)((char*)a1) = tmp1;
    tmp2 = *(int*)((char*)tmp0 + 176);
    *(int*)((char*)a2) = tmp2;
    tmp3 = *(int*)((char*)tmp0 + 180);
    *(int*)((char*)a3) = tmp3;
}

int func_0010B378(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 64);
    tmp1 = *(int*)(char*)tmp0;
    return tmp1;
}

int func_0010B388(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 64);
    tmp1 = *(int*)((char*)tmp0 + 4);
    return ((unsigned int)(tmp1) < (unsigned int)(1));
}
