/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00400140(int a0, int a1, int a2, int a3, int t0) {
    *(int*)((char*)a0) = 0;
    *(short*)((char*)a0 + 4) = a1;
    *(char*)((char*)a0 + 6) = a3;
    *(char*)((char*)a0 + 7) = 0;
    *(int*)((char*)a0 + 8) = a2;
    *(int*)((char*)a0 + 12) = t0;
}
