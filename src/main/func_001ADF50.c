/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DA930[];
extern char D_004DFD80[];

int func_001ADF50(int a0, int a1) {
    int tmp0;
    int tmp1;
    int tmp2;
    int tmp3;
    int tmp4;
    int tmp5;
    int tmp6;
    signed char tmp7;
    int tmp8;
    signed char tmp9;
    int tmp10;
    unsigned char tmp11;
    float tmp12;

    *(int*)((char*)a0) = (int)D_004DFD80;
    tmp0 = *(int*)((char*)a1 + 4);
    *(int*)((char*)a0 + 4) = tmp0;
    tmp1 = *(int*)((char*)a1 + 8);
    *(int*)((char*)a0 + 8) = tmp1;
    tmp2 = *(int*)((char*)a1 + 12);
    *(int*)((char*)a0 + 12) = tmp2;
    tmp3 = *(int*)((char*)a1 + 16);
    *(int*)((char*)a0 + 16) = tmp3;
    tmp4 = *(int*)((char*)a1 + 20);
    *(int*)((char*)a0 + 20) = tmp4;
    tmp5 = *(int*)((char*)a1 + 24);
    *(int*)((char*)a0 + 24) = tmp5;
    tmp6 = *(int*)((char*)a1 + 28);
    *(int*)((char*)a0 + 28) = tmp6;
    tmp7 = *(signed char*)((char*)a1 + 32);
    *(char*)((char*)a0 + 32) = tmp7;
    *(int*)((char*)a0) = (int)D_004DA930;
    tmp8 = *(int*)((char*)a1 + 36);
    *(int*)((char*)a0 + 36) = tmp8;
    tmp9 = *(signed char*)((char*)a1 + 40);
    *(char*)((char*)a0 + 40) = tmp9;
    tmp10 = *(int*)((char*)a1 + 44);
    *(int*)((char*)a0 + 44) = tmp10;
    tmp11 = *(unsigned char*)((char*)a1 + 48);
    *(char*)((char*)a0 + 48) = tmp11;
    tmp12 = *(float*)((char*)a1 + 52);
    *(float*)((char*)a0 + 52) = tmp12;
    return a0;
}

int func_001ADFE0(int a0, int a1) {
    *(int*)((char*)a0) = a1;
    return a0;
}

int func_001ADFF0(int a0, int a1) {
    *(float*)((char*)a0 + 8) = *(float*)(char*)a1;
    *(float*)((char*)a0 + 12) = *(float*)((char*)a1 + 4);
    *(float*)((char*)a0 + 16) = *(float*)((char*)a1 + 8);
    *(float*)((char*)a0 + 20) = *(float*)((char*)a1 + 12);
    *(char*)((char*)a0 + 5) = 1;
    return a0;
}
