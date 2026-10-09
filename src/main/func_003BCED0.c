/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003C3220(int);
extern int func_003C6FC0(int, int, int, int, int, int, int, float, float, float, float, float, float, float);

int func_003BCED0(int a0) {
    return func_003C3220(a0);
}

int func_003BCEE0(int a0, int a1, int a2, int a3, int t0, int t1, int t2, float f12, float f13, float f14, float f15, float f16, float f17) {
    return func_003C6FC0(a0, a1, a2, a3, t0, t1, t2, 1.0f, f12, f13, f14, f15, f16, f17);
}
