/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int randomMT(void);

void randomNoneZero(void) {
    int v0;
    int cond;

L00306DE8:;
    v0 = randomMT();
    cond = v0 == 0;
    if (cond) goto L00306DE8;
    goto ret;
ret:;
}
