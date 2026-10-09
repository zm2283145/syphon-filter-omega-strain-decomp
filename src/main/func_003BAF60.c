/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00539248[];

int func_003BAF60(int a0) {
    int tmp0;
    int tmp1;
    int tmp2;
    int tmp3;
    int tmp4;
    unsigned short tmp5;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)D_00539248;
    tmp2 = *(int*)((char*)tmp1 + 8);
    tmp3 = *(int*)(char*)(tmp2 + (tmp0 << 2));
    tmp4 = *(int*)((char*)tmp3 + 68);
    tmp5 = *(unsigned short*)((char*)tmp4 + 6);
    return tmp5;
}

int func_003BAF90(int a0) {
    int tmp0;
    int tmp1;
    int tmp2;
    int tmp3;
    int tmp4;
    unsigned short tmp5;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)D_00539248;
    tmp2 = *(int*)((char*)tmp1 + 8);
    tmp3 = *(int*)(char*)(tmp2 + (tmp0 << 2));
    tmp4 = *(int*)((char*)tmp3 + 68);
    tmp5 = *(unsigned short*)((char*)tmp4 + 4);
    return tmp5;
}
