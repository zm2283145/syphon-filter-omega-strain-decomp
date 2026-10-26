/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int setVuFftMode(int);

int nciEnableVu0Optimizations(void) {
    int a0, v0, v1;

    v0 = setVuFftMode(a0);
    v1 = 0 + 6165;
    if (v0 == 0) v1 = 0;
    v0 = v1;
    goto ret;
ret:
    return v0;
}
