/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EF038[];
extern char D_005061D0[];

void func_001BA6B0(int a0) {
    unsigned char tmp0;
    int tmp1;
    int tmp2;

    tmp0 = *(unsigned char*)((char*)a0 + 36);
    tmp1 = *(int*)D_005061D0;
    *(char*)((char*)tmp1) = tmp0;
    tmp2 = *(int*)D_005061D0;
    *(int*)D_005061D0 = (tmp2 + 1);
}

int func_001BA6E0(void) {
    int tmp0;

    tmp0 = *(int*)D_004EF038;
    return tmp0;
}
