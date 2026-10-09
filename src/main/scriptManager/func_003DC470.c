/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00554F30[];
extern int func_003DC4C0(int, int);
extern int func_003DC4D0(int, int);

int func_003DC470(int a0, int a1, int a2) {
    int tmp0;
    int tmp2;
    int tmp3;
    int tmp5;
    int tmp6;
    int tmp7;

    tmp0 = func_003DC4D0(a0, a1);
    tmp2 = *(int*)D_00554F30;
    tmp3 = func_003DC4C0(tmp2, (tmp0 + -10));
    tmp5 = *(int*)(char*)tmp3;
    tmp6 = *(int*)((char*)tmp5 + 12);
    tmp7 = *(int*)(char*)(tmp6 + (a2 * 12));
    return tmp7;
}
