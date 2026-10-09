/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0013BCB0(int, int);

int func_004089B0(int a0, int a1, int a2) {
    int tmp0;

    tmp0 = func_0013BCB0(a0, a1);
    *(char*)((char*)a0 + 12) = a2;
    return tmp0;
}
