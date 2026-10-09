/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003C6420(int a0, int a1) {
    int v0, v1;

    v0 = 0x11000000;
    v1 = a1 << 4;
    v0 = v0 | 0x4000;
    v0 = v1 | v0;
    goto ret;
ret:
    return v0;
}
