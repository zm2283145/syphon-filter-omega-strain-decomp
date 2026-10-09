/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

/* Quadword copy. */
void func_003E4700(Q* dst, Q* src) {
    Q tmp;

    tmp = *src;
    *dst = tmp;
}

void func_003E4710(char* self, int value) {
    *(int*)(self + 40) = value;
}
