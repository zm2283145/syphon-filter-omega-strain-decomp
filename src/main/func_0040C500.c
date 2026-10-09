/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0040C500(int a0, int a1, int a2, int a3) {
    *(int*)((char*)a0) = (a2 | (((a3 + 1) << 24) | (a1 << 16)));
    return a0;
}
