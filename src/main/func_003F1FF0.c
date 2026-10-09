/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003F1FF0(int a0, int a1) {
    int tmp0;
    float tmp1;
    int tmp2;
    float tmp3;

    tmp0 = *(int*)(char*)a1;
    *(int*)((char*)a1) = (tmp0 + 4);
    tmp1 = *(float*)(char*)tmp0;
    *(float*)((char*)a0) = tmp1;
    tmp2 = *(int*)(char*)a1;
    *(int*)((char*)a1) = (tmp2 + 4);
    tmp3 = *(float*)(char*)tmp2;
    *(float*)((char*)a0 + 4) = tmp3;
    return a0;
}
