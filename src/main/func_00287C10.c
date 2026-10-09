/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00287C10(int a0, int a1, int a2) {
    *(int*)((char*)a0 + 4) = a2;
    *(int*)((char*)a0) = a1;
    *(float*)((char*)a0 + 36) = *(float*)((char*)*(int*)((char*)a0 + 4) + 324);
    *(char*)((char*)a0 + 40) = 0;
    return a0;
}
