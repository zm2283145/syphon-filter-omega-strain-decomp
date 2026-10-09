/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0010B330(int a0) {
    int v0, v1;

    v1 = *(int*)(char*)(a0 + 64);
    v0 = 0 + 1;
    *(int*)(char*)(v1 + 4256) = v0;
    goto ret;
ret:
    return v0;
}
