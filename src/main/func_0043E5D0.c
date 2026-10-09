/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004C0100[];
extern char D_004C0104[];
extern char D_004C0108[];
extern char D_004C010C[];
extern char D_004E1040[];
extern int ScalarCollection_Init(int);
extern void func_0041F690(int);

int func_0043E5D0(int a0) {
    float tmp4;
    float tmp5;
    float tmp6;
    float tmp7;

    func_0041F690(a0);
    *(int*)((char*)a0) = (int)D_004E1040;
    ScalarCollection_Init((a0 + 112));
    *(int*)((char*)a0 + 72) = 0;
    *(int*)((char*)a0 + 76) = 0;
    *(int*)((char*)a0 + 96) = 0;
    *(int*)((char*)a0 + 104) = 0;
    *(int*)((char*)a0 + 100) = 0;
    *(int*)((char*)a0 + 108) = 0;
    tmp4 = *(float*)D_004C0100;
    *(float*)((char*)a0 + 80) = tmp4;
    tmp5 = *(float*)D_004C0104;
    *(float*)((char*)a0 + 84) = tmp5;
    tmp6 = *(float*)D_004C0108;
    *(float*)((char*)a0 + 88) = tmp6;
    tmp7 = *(float*)D_004C010C;
    *(float*)((char*)a0 + 92) = tmp7;
    return a0;
}
