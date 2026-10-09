/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0055A818[];

void func_00165610(void) {
    int tmp0;

    tmp0 = *(int*)D_0055A818;
    *(int*)D_0055A818 = (tmp0 + 1);
}
