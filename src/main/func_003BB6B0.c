/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003BB6B0(int a0, int a1) {
    *(int*)((char*)a0 + 68) = a1;
    *(int*)((char*)a0 + 72) = (*(int*)((char*)a0 + 72) | 4096);
    *(char*)((char*)a0 + 96) = 0;
    *(char*)((char*)a0 + 97) = 0;
}
