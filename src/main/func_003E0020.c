/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003E0020(int a0, int a1) {
    *(int*)((char*)a0 + 20080) = (*(int*)((char*)a0 + 20080) + -4);
    *(int*)((char*)*(int*)((char*)a0 + 20080)) = a1;
}
