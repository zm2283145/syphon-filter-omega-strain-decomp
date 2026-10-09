/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00363800(int a0, int a1) {
    *(int*)((char*)a0) = a1;
    *(int*)((char*)a0 + 4) = 0;
    return a0;
}
