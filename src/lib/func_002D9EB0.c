/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_002D9EB0(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 112);
    *(int*)((char*)a0 + 112) = (tmp0 & ~((0) | (a1)));
}
