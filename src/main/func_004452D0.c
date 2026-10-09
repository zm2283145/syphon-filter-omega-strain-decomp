/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004976D8[];

int func_004452D0(void) {
    int tmp0;

    tmp0 = *(int*)D_004976D8;
    return tmp0;
}

void func_004452E0(int a0) {
    *(int*)D_004976D8 = a0;
}
