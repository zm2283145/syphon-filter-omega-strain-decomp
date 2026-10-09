/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00489D60[];
extern char D_004FFD30[];
extern int func_00147840(int, int);

int func_00143D20(int a0) {
    int tmp0;
    int tmp1;
    unsigned char tmp3;
    signed char tmp4;

    tmp0 = *(int*)D_004FFD30;
    tmp1 = func_00147840(tmp0, a0);
    tmp3 = *(unsigned char*)((char*)tmp1 + 48);
    tmp4 = *(signed char*)(char*)((int)D_00489D60 + tmp3);
    return tmp4;
}
