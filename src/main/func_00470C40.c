/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005061D0[];
extern char D_00587FC8[];

void func_00470C40(int a0) {
    short tmp0;
    int tmp1;
    int tmp2;
    int tmp3;
    int tmp4;
    signed char tmp5;
    int tmp6;
    int tmp7;
    signed char tmp8;
    int tmp9;
    int tmp10;

    tmp0 = *(short*)((char*)a0 + 36);
    tmp1 = *(int*)D_005061D0;
    *(char*)((char*)tmp1) = tmp0;
    tmp2 = *(int*)D_005061D0;
    *(int*)D_005061D0 = (tmp2 + 1);
    tmp3 = *(int*)D_005061D0;
    *(char*)((char*)tmp3) = (tmp0 >> 8);
    tmp4 = *(int*)D_005061D0;
    *(int*)D_005061D0 = (tmp4 + 1);
    tmp5 = *(signed char*)((char*)a0 + 38);
    tmp6 = *(int*)D_005061D0;
    *(char*)((char*)tmp6) = tmp5;
    tmp7 = *(int*)D_005061D0;
    *(int*)D_005061D0 = (tmp7 + 1);
    tmp8 = *(signed char*)((char*)a0 + 39);
    tmp9 = *(int*)D_005061D0;
    *(char*)((char*)tmp9) = tmp8;
    tmp10 = *(int*)D_005061D0;
    *(int*)D_005061D0 = (tmp10 + 1);
}

int func_00470CE0(void) {
    int tmp0;

    tmp0 = *(int*)D_00587FC8;
    return tmp0;
}
