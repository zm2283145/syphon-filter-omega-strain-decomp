/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005202E8[];

/* Stores the address of D_005202E8 into out; returns 23 on a null argument. */
int func_002E60A0(void** out) {
    int result = 23;

    if (out != 0) {
        result = 0;
        *out = D_005202E8;
    }
    return result;
}
