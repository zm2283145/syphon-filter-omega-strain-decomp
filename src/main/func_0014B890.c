/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00143DF0(int, int, int, int, int, int);

int func_0014B890(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 48);
    tmp1 = *(int*)((char*)tmp0 + 13604);
    return func_00143DF0(tmp1, a1, 1, 0, 0, 0);
}
