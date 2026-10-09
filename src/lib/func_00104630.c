/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00104630(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)(char*)a0;
    *(int*)((char*)a0) = (tmp0 + (a1 << 2));
    return tmp0;
}
