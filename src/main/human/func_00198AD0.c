/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* MotionGroup_CopyPair(int* dst, int* src) {
    dst[0] = src[0];
    dst[1] = src[1];
    return dst;
}
