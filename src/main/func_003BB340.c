/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003BB340(int a0) {
    *(int*)((char*)a0) = -1;
    *(int*)((char*)a0 + 4) = -1;
    *(int*)((char*)a0 + 8) = 0;
    *(int*)((char*)a0 + 12) = 0;
    *(char*)((char*)a0 + 16) = 0;
    return a0;
}
