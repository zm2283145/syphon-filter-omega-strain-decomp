/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hud_types.h"

/* Stores value into *dst; volatile mirrors the original stack temporary. */
int* std_list_tCalloutPtr_generic_iterator_1_ctor(int* dst, int value) {
    volatile int tmp = value;

    *dst = tmp;
    return dst;
}
