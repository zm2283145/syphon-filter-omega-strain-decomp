/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_0015E0F0(int a0, int a1, float f12, float f13) {
    *(float*)((char*)a0) = f12;
    *(float*)((char*)a0 + 4) = f13;
    *(char*)((char*)a0 + 8) = a1;
    return a0;
}
