/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0041EBF0(int);

int func_00456A30(int a0) {
    int tmp0;

    tmp0 = func_0041EBF0(a0);
    *(int*)((char*)a0 + 16) = -1;
    return tmp0;
}
