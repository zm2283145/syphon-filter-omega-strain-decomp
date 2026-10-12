/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001152F8(int, int, int, int);

int func_00115400(int a0, int a1, int a2) {
    int tmp0;

    tmp0 = func_001152F8(a0, a1, a2, 1);
    return tmp0;
}

int func_00115420(int a0, int a1) {
    int tmp0;

    tmp0 = func_001152F8(a0, (int)"all", a1, 1);
    return tmp0;
}
