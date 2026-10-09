/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001CAB30(int a0, int a1) {
    return (a0 + (a1 << 5));
}

int func_001CAB40(int a0, int a1) {
    return (a0 + (((a1 << 3) - a1) << 6));
}
