/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0039EF90(int, int, int, int, int, int, float);

int func_003A3420(int a0, int a1, int a2, int a3, int t0, int t1, float f12) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 8);
    return func_0039EF90(tmp0, a1, a2, a3, t0, t1, f12);
}
