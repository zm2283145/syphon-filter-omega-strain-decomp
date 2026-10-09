/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int func_002B5F48(int* a, int* b);

/* Polls func_002B5F48 until it returns non-zero. */
void func_0040D5D0(void) {
    int loc[2];

    while (func_002B5F48(&loc[1], &loc[0]) == 0) {
    }
}
