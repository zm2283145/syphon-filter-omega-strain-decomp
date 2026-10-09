/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_002D9EA0(int a0, int a1) {
    int v0;

    v0 = *(int*)(char*)(a0 + 112);
    v0 = v0 | a1;
    *(int*)(char*)(a0 + 112) = v0;
    goto ret;
ret:
    return v0;
}
