/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_002C5EE0(int a0, int a1) {
    Q tmp0;
    float tmp1;
    float tmp2;
    int tmp3;
    int tmp4;
    unsigned char tmp5;
    unsigned char tmp6;

    tmp0 = *(Q*)(char*)a1;
    *(Q*)((char*)a0) = tmp0;
    tmp1 = *(float*)((char*)a1 + 16);
    *(float*)((char*)a0 + 16) = tmp1;
    tmp2 = *(float*)((char*)a1 + 20);
    *(float*)((char*)a0 + 20) = tmp2;
    tmp3 = *(int*)((char*)a1 + 24);
    *(int*)((char*)a0 + 24) = tmp3;
    tmp4 = *(int*)((char*)a1 + 28);
    *(int*)((char*)a0 + 28) = tmp4;
    tmp5 = *(unsigned char*)((char*)a1 + 32);
    *(char*)((char*)a0 + 32) = tmp5;
    tmp6 = *(unsigned char*)((char*)a1 + 33);
    *(char*)((char*)a0 + 33) = tmp6;
    return a0;
}
