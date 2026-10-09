/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003231D8(int);

int func_00323508(void) {
    int a0, v0, v1;

    v0 = func_003231D8(a0);
    v1 = 0 + 6165;
    if (v0 == 0) v1 = 0;
    v0 = v1;
    goto ret;
ret:
    return v0;
}
