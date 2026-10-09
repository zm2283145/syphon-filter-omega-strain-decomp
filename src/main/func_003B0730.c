/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003B0730(int a0, int a1) {
    return (*(int*)((char*)a0 + 144) + (a1 << 3));
}

int func_003B0740(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 12);
    return (tmp0 + (a1 * 36));
}
