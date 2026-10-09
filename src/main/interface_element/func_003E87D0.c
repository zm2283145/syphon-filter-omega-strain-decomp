/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00538C64[];
extern char D_00538C68[];

void func_003E87D0(void) {
    int tmp0;

    tmp0 = *(int*)D_00538C64;
    *(char*)D_00538C68 = 1;
    *(int*)D_00538C64 = (tmp0 + -1);
}
