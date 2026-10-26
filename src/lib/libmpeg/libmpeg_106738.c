/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int _ipuVdec(int, int);

int _dmVector(int a0) {
    int tmp0;

    tmp0 = _ipuVdec(a0, 3);
    return tmp0;
}
