/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00269430(int);
extern int func_002697E0(int);
extern int func_003D9970(int);

void func_002693F0(void) {
}

int Script_CreateNodeList(int a0) {
    int tmp0;
    int tmp1;
    int tmp3;
    int tmp5;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_003D9970(tmp0);
    tmp3 = func_00269430(tmp1);
    tmp5 = func_002697E0(tmp3);
    return tmp5;
}
