/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int ScalarCollection_Init(int);

int func_003AD310(int a0, int a1) {
    return ((unsigned int)((*(int*)((char*)a0 + 16) ^ *(int*)((char*)a1 + 16))) < (unsigned int)(1));
}

int func_003AD330(int a0, float f12) {
    ScalarCollection_Init(a0);
    *(float*)((char*)a0 + 12) = f12;
    return a0;
}
