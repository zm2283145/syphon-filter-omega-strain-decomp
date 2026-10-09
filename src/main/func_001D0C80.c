/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001D0CF0(int, int, int, int);
extern int func_001D1140(int, int, int, int);

int func_001D0C80(int a0, int a1, int a2, int a3, int t0) {
    int tmp2;

    func_001D1140(a0, a1, a3, t0);
    tmp2 = func_001D0CF0(a0, a2, a3, t0);
    return tmp2;
}
