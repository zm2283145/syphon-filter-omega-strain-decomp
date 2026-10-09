/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004D92A0[];
extern char D_004D92C0[];
extern char D_004DFD80[];

Word* func_0016F7E0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_0016F7F0(int a0, int a1) {
    int tmp0;
    int tmp1;
    int tmp2;
    int tmp3;
    int tmp4;
    int tmp5;
    int tmp6;
    signed char tmp7;
    signed char tmp8;
    signed char tmp9;
    float tmp10;
    float tmp11;
    int tmp12;

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
    *(int*)((char*)a0) = (int)D_004D92A0;
    tmp8 = *(signed char*)((char*)a1 + 36);
    *(char*)((char*)a0 + 36) = tmp8;
    tmp9 = *(signed char*)((char*)a1 + 37);
    *(char*)((char*)a0 + 37) = tmp9;
    tmp10 = *(float*)((char*)a1 + 40);
    *(float*)((char*)a0 + 40) = tmp10;
    tmp11 = *(float*)((char*)a1 + 44);
    *(float*)((char*)a0 + 44) = tmp11;
    *(int*)((char*)a0) = (int)D_004D92C0;
    tmp12 = *(int*)((char*)a1 + 48);
    *(int*)((char*)a0 + 48) = tmp12;
    return a0;
}
