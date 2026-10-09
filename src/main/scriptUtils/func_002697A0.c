/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F8400[];
extern int func_002697E0(int);
extern int func_003CB1D0(void);
extern void func_003D9440(int, int);

void func_002697A0(void) {
    int tmp0;
    int tmp2;
    int tmp3;

    tmp0 = func_003CB1D0();
    tmp2 = *(int*)D_004F8400;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
}

int func_002697D0(int a0) {
    return func_002697E0(a0);
}

int func_002697E0(int a0) {
    int loc[1];
    int v0;

    *(int*)(char*)loc = a0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}
