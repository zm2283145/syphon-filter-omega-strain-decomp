/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0013EE20(int a0) {
    float tmp0;
    float tmp1;
    float tmp2;
    float tmp3;
    float tmp4;
    float tmp5;

    tmp0 = *(float*)((char*)a0 + 4);
    tmp1 = *(float*)((char*)a0 + 16);
    *(float*)((char*)a0 + 4) = tmp1;
    *(float*)((char*)a0 + 16) = tmp0;
    tmp2 = *(float*)((char*)a0 + 8);
    tmp3 = *(float*)((char*)a0 + 32);
    *(float*)((char*)a0 + 8) = tmp3;
    *(float*)((char*)a0 + 32) = tmp2;
    tmp4 = *(float*)((char*)a0 + 24);
    tmp5 = *(float*)((char*)a0 + 36);
    *(float*)((char*)a0 + 24) = tmp5;
    *(float*)((char*)a0 + 36) = tmp4;
    return a0;
}

int func_0013EE60(void) {
    return 0;
}
