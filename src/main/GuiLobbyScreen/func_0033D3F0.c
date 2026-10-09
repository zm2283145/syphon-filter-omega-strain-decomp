/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004928A8[];
extern int func_0041DB80(int, int);
extern int func_0041F150(int);

void func_0033D3F0(int a0) {
    int tmp2;
    int tmp3;

    func_0041F150(a0);
    tmp2 = *(int*)D_004928A8;
    tmp3 = func_0041DB80(a0, tmp2);
    *(int*)((char*)a0 + 124) = tmp3;
}
