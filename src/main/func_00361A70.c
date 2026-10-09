/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFC04[];
extern int func_002C9C80(int, int);
extern int func_0041F090(int);

int func_00361A70(int a0) {
    int tmp2;
    int tmp3;

    func_0041F090(a0);
    tmp2 = *(int*)D_004FFC04;
    tmp3 = func_002C9C80(tmp2, 0);
    return tmp3;
}
