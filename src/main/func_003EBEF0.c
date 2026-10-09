/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003EBEF0(int a0) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 8) = 0;
    *(int*)((char*)a0 + 4) = 0;
    *(char*)((char*)a0 + 12) = 0;
    return a0;
}
