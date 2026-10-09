/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_001BC2B0(int a0, int a1) {
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

    tmp0 = *(float*)((char*)a1 + 44);
    tmp1 = *(float*)((char*)a1 + 40);
    tmp2 = *(float*)((char*)a1 + 36);
    tmp3 = *(float*)((char*)a1 + 32);
    tmp4 = *(float*)((char*)a1 + 28);
    tmp5 = *(float*)((char*)a1 + 24);
    tmp6 = *(float*)((char*)a1 + 20);
    tmp7 = *(float*)((char*)a1 + 16);
    tmp8 = *(float*)((char*)a1 + 12);
    tmp9 = *(float*)((char*)a1 + 8);
    tmp10 = *(float*)((char*)a1 + 4);
    tmp11 = *(float*)(char*)a1;
    *(float*)((char*)a0) = tmp11;
    *(float*)((char*)a0 + 4) = tmp10;
    *(float*)((char*)a0 + 8) = tmp9;
    *(float*)((char*)a0 + 12) = tmp8;
    *(float*)((char*)a0 + 16) = tmp7;
    *(float*)((char*)a0 + 20) = tmp6;
    *(float*)((char*)a0 + 24) = tmp5;
    *(float*)((char*)a0 + 28) = tmp4;
    *(float*)((char*)a0 + 32) = tmp3;
    *(float*)((char*)a0 + 36) = tmp2;
    *(float*)((char*)a0 + 40) = tmp1;
    *(float*)((char*)a0 + 44) = tmp0;
    *(int*)((char*)a0 + 48) = 0;
    *(int*)((char*)a0 + 52) = 0;
    *(int*)((char*)a0 + 56) = 0;
    *(int*)((char*)a0 + 60) = 1065353216;
}
