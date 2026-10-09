/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001AE050(int a0, int a1, int a2, int a3) {
    int v0, v1;

    v1 = 0 + 1;
    v0 = (signed char)a1;
    v0 = v0 << 3;
    a1 = v0 + a0;
    *(int*)(char*)(a1 + 4) = a2;
    v0 = a0;
    *(int*)(char*)(a1 + 8) = a3;
    *(char*)(char*)a0 = v1;
    goto ret;
ret:
    return v0;
}
