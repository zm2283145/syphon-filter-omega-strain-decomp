/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Stores value into *dst; volatile mirrors the original stack temporary. */
int* func_003AA270(int* dst, int value) {
    volatile int tmp = value;

    *dst = tmp;
    return dst;
}
