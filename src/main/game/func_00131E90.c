/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int Mtx_SetBasis(int a0, int a1, int a2, int a3) {
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

    tmp0 = *(float*)((char*)a1 + 12);
    tmp1 = *(float*)((char*)a1 + 8);
    tmp2 = *(float*)((char*)a1 + 4);
    tmp3 = *(float*)(char*)a1;
    *(float*)((char*)a0) = tmp3;
    *(float*)((char*)a0 + 4) = tmp2;
    *(float*)((char*)a0 + 8) = tmp1;
    *(float*)((char*)a0 + 12) = tmp0;
    tmp4 = *(float*)((char*)a2 + 12);
    tmp5 = *(float*)((char*)a2 + 8);
    tmp6 = *(float*)((char*)a2 + 4);
    tmp7 = *(float*)(char*)a2;
    *(float*)((char*)a0 + 16) = tmp7;
    *(float*)((char*)a0 + 20) = tmp6;
    *(float*)((char*)a0 + 24) = tmp5;
    *(float*)((char*)a0 + 28) = tmp4;
    tmp8 = *(float*)((char*)a3 + 12);
    tmp9 = *(float*)((char*)a3 + 8);
    tmp10 = *(float*)((char*)a3 + 4);
    tmp11 = *(float*)(char*)a3;
    *(float*)((char*)a0 + 32) = tmp11;
    *(float*)((char*)a0 + 36) = tmp10;
    *(float*)((char*)a0 + 40) = tmp9;
    *(float*)((char*)a0 + 44) = tmp8;
    return a0;
}
