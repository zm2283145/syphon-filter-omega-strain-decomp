/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F54D0[];
extern char D_004F5660[];
extern char D_004F5668[];
extern char D_00555070[];
extern void func_003D9440(int, int);
extern int func_003E1AA0(int, int, int);

void func_00210AC0(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_004F5668;
    tmp1 = *(int*)D_004F54D0;
    func_003D9440(tmp0, tmp1);
}

int func_00210AE0(void) {
    int tmp0;

    tmp0 = *(int*)D_004F5660;
    return tmp0;
}

int func_00210AF0(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}
