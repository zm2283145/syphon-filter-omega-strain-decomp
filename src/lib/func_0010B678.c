/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0010B678(int a0) {
    int tmp0;
    int tmp1;
    int tmp2;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)a0 + 4);
    tmp2 = *(int*)((char*)a0 + 8);
    return ((tmp0 + tmp1) - tmp2);
}
