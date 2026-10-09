/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005061D0[];
extern int func_002307B0(int, int, int);
extern void func_00282020(int);
extern int func_00282160(int);

int func_00230CE0(int a0) {
    int tmp2;
    signed char tmp3;
    signed char tmp4;
    int tmp5;
    int tmp6;

    func_00282160((a0 + 36));
    tmp2 = *(int*)D_005061D0;
    tmp3 = *(signed char*)(char*)tmp2;
    *(int*)D_005061D0 = (tmp2 + 1);
    *(char*)((char*)a0 + 40) = tmp3;
    tmp4 = *(signed char*)((char*)a0 + 40);
    tmp5 = *(int*)((char*)a0 + 36);
    tmp6 = func_002307B0(tmp4, tmp5, 0);
    return tmp6;
}

void func_00230D40(int a0) {
    int tmp0;
    signed char tmp3;
    int tmp4;
    int tmp5;

    tmp0 = *(int*)((char*)a0 + 36);
    func_00282020(tmp0);
    tmp3 = *(signed char*)((char*)a0 + 40);
    tmp4 = *(int*)D_005061D0;
    *(char*)((char*)tmp4) = tmp3;
    tmp5 = *(int*)D_005061D0;
    *(int*)D_005061D0 = (tmp5 + 1);
}
