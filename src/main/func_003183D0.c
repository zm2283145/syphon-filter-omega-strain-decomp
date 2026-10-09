/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003183D0(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 72);
    *(short*)((char*)tmp0 + 42) = 0;
    return tmp0;
}
