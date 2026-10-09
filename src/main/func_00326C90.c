/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005061D0[];

void func_00326C90(int a0) {
    unsigned char tmp0;
    int tmp1;
    int tmp2;

    tmp0 = *(unsigned char*)((char*)a0 + 36);
    tmp1 = *(int*)D_005061D0;
    *(char*)((char*)tmp1) = tmp0;
    tmp2 = *(int*)D_005061D0;
    *(int*)D_005061D0 = (tmp2 + 1);
}
