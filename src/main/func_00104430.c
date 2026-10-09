/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00104430(int a0, int a1) {
    *(int*)((char*)a0) = a1;
    *(int*)((char*)a0 + 8) = 0;
    *(int*)((char*)a0 + 4) = a1;
}
