/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int _sceSifLoadElfPart(int, int, int, int);

int sceSifLoadElfPart(int a0, int a1, int a2) {
    int tmp0;

    tmp0 = _sceSifLoadElfPart(a0, a1, a2, 1);
    return tmp0;
}

int sceSifLoadElf(int a0, int a1) {
    int tmp0;

    tmp0 = _sceSifLoadElfPart(a0, (int)"all", a1, 1);
    return tmp0;
}
