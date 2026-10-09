/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int MotionGroup_CopyPair(int a0, int a1) {
    *(int*)((char*)a0) = *(int*)(char*)a1;
    *(int*)((char*)a0 + 4) = *(int*)((char*)a1 + 4);
    return a0;
}
