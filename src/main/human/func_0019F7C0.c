/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* func_0019F7C0(int* dst, int* src) {
    dst[0] = src[0];
    dst[1] = src[1];
    return dst;
}

void func_0019F7E0(char* self) {
    *(int*)(self + 12) = 0;
    *(int*)(self + 16) = 0;
}
