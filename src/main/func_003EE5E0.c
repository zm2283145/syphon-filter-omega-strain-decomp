/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003EE360(int, int);

int func_003EE5E0(int a0, int a1) {
    float tmp0;
    float tmp1;
    float tmp2;
    float tmp3;

    tmp0 = *(float*)(char*)a1;
    *(float*)((char*)a0 + 160) = tmp0;
    tmp1 = *(float*)((char*)a1 + 4);
    *(float*)((char*)a0 + 164) = tmp1;
    tmp2 = *(float*)((char*)a1 + 8);
    *(float*)((char*)a0 + 168) = tmp2;
    tmp3 = *(float*)((char*)a1 + 12);
    *(float*)((char*)a0 + 172) = tmp3;
    return func_003EE360(a0, a1);
}
