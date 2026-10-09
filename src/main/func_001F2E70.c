/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001F2EA0(int);

int func_001F2E70(int a0) {
    int s0, v0;

    s0 = a0;
    v0 = func_001F2EA0(a0);
    v0 = s0;
    goto ret;
ret:
    return v0;
}
