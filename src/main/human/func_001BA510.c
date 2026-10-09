/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EF010[];
extern char D_005061D0[];
extern void func_00282020(int);

void func_001BA510(int a0) {
    int tmp0;
    signed char tmp3;
    int tmp4;
    int tmp5;
    signed char tmp6;
    int tmp7;
    int tmp8;

    tmp0 = *(int*)((char*)a0 + 36);
    func_00282020(tmp0);
    tmp3 = *(signed char*)((char*)a0 + 40);
    tmp4 = *(int*)D_005061D0;
    *(char*)((char*)tmp4) = tmp3;
    tmp5 = *(int*)D_005061D0;
    *(int*)D_005061D0 = (tmp5 + 1);
    tmp6 = *(signed char*)((char*)a0 + 41);
    tmp7 = *(int*)D_005061D0;
    *(char*)((char*)tmp7) = tmp6;
    tmp8 = *(int*)D_005061D0;
    *(int*)D_005061D0 = (tmp8 + 1);
}

int func_001BA580(void) {
    int tmp0;

    tmp0 = *(int*)D_004EF010;
    return tmp0;
}
