/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_0010B5D0(int a0, int a1, int a2) {
    *(int*)((char*)a0 + 12) = a1;
    *(int*)((char*)a0 + 4) = a2;
    *(int*)((char*)a0) = a1;
    *(int*)((char*)a0 + 8) = a1;
}
