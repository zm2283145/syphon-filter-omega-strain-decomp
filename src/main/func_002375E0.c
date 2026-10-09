/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7CF8[];
extern char D_004F7D00[];
extern char D_004F7D20[];
extern char D_00555070[];
extern int func_003CC830(void);
extern int func_003D9400(int, int);
extern void func_003D9440(int, int);
extern int func_003E1AA0(int, int, int);

int func_002375E0(void) {
    int tmp0;
    int tmp2;
    int tmp3;
    int tmp6;
    int tmp7;
    int tmp8;

    tmp0 = func_003CC830();
    tmp2 = *(int*)D_004F7D00;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
    tmp6 = *(int*)D_004F7D00;
    tmp7 = *(int*)D_004F7D20;
    tmp8 = func_003D9400(tmp6, tmp7);
    return tmp8;
}

int func_00237620(void) {
    int tmp0;

    tmp0 = *(int*)D_004F7CF8;
    return tmp0;
}

int func_00237630(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}
