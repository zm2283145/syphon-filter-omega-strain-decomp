/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F54D0[];
extern char D_004F54F0[];
extern char D_004F54F8[];
extern char D_004F5638[];
extern char D_00555070[];
extern int func_003D9400(int, int);
extern void func_003D9440(int, int);
extern int ScriptFilter_Dispatch(int, int, int);

int func_00211400(void) {
    int tmp0;
    int tmp1;
    int tmp4;
    int tmp5;
    int tmp6;

    tmp0 = *(int*)D_004F54F8;
    tmp1 = *(int*)D_004F54D0;
    func_003D9440(tmp0, tmp1);
    tmp4 = *(int*)D_004F54F8;
    tmp5 = *(int*)D_004F5638;
    tmp6 = func_003D9400(tmp4, tmp5);
    return tmp6;
}

int func_00211440(void) {
    int tmp0;

    tmp0 = *(int*)D_004F54F0;
    return tmp0;
}

int PathObj_ScriptFilter(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}
