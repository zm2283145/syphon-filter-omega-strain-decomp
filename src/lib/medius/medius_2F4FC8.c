/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_002DAAB0(int, int);

int func_002F4FC8(void) {
    int a0, a1, v0, v1;

    v0 = func_002DAAB0(a0, a1);
    v1 = 0 + -1;
    if (v0 != 0) v1 = 0;
    v0 = v1;
    goto ret;
ret:
    return v0;
}
