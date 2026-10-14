/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_002FB568(int, int);

int func_002DD358(void) {
    int a0, a1, v0, v1;

    v0 = func_002FB568(a0, a1);
    v1 = 0 + 22;
    if (v0 == 0) v1 = 0;
    v0 = v1;
    goto ret;
ret:
    return v0;
}
