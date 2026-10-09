/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_0010B5E8(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 8);
    *(int*)((char*)a0 + 12) = tmp0;
}

void func_0010B5F8(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 12);
    *(int*)((char*)a0 + 8) = tmp0;
}
