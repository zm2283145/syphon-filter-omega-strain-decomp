/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int Vec_SetPositionW1(int a0) {
    int v0;

    v0 = 0x3f800000;
    *(int*)(char*)(a0 + 12) = v0;
    v0 = a0;
    goto ret;
ret:
    return v0;
}
