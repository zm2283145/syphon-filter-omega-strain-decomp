/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0019D5A0(int, int, int, float, float, float);

int func_00475BB0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 12872);
    *(int*)((char*)a0 + 12872) = (tmp0 & 0xfdffffff);
    tmp1 = *(int*)((char*)a0 + 12872);
    *(int*)((char*)a0 + 12872) = (tmp1 & 0xfbffffff);
    return func_0019D5A0((a0 + 11984), 21, 0, 1.0f, 0.5f, 0.0f);
}
