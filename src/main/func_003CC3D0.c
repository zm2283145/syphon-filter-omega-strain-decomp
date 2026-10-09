/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005436B8[];
extern char D_00543720[];
extern char D_00543728[];
extern char D_00555070[];
extern void func_003D9440(int, int);
extern int func_003E1AA0(int, int, int);

void func_003CC3D0(void) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_00543728;
    tmp1 = *(int*)D_005436B8;
    func_003D9440(tmp0, tmp1);
}

int func_003CC3F0(void) {
    int tmp0;

    tmp0 = *(int*)D_00543720;
    return tmp0;
}

int func_003CC400(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}
