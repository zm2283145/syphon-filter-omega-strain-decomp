/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00384A00(int a0) {
    float tmp0;
    float tmp1;
    float tmp2;
    float tmp3;
    float tmp4;
    float tmp5;
    float tmp6;
    float tmp7;
    float tmp8;
    float tmp9;
    float tmp10;
    float tmp11;

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
    tmp6 = *(float*)((char*)a0 + 12);
    tmp7 = *(float*)((char*)a0 + 48);
    *(float*)((char*)a0 + 12) = tmp7;
    *(float*)((char*)a0 + 48) = tmp6;
    tmp8 = *(float*)((char*)a0 + 28);
    tmp9 = *(float*)((char*)a0 + 52);
    *(float*)((char*)a0 + 28) = tmp9;
    *(float*)((char*)a0 + 52) = tmp8;
    tmp10 = *(float*)((char*)a0 + 44);
    tmp11 = *(float*)((char*)a0 + 56);
    *(float*)((char*)a0 + 44) = tmp11;
    *(float*)((char*)a0 + 56) = tmp10;
    return a0;
}
