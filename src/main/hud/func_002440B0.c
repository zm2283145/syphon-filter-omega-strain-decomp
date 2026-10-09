/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hud_types.h"

/* Stores value into *dst; volatile mirrors the original stack temporary. */
int* func_002440B0(int* dst, int value) {
    volatile int tmp = value;

    *dst = tmp;
    return dst;
}
