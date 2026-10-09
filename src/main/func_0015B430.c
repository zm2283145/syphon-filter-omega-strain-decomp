/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int GObj_IdentityB(int);

int func_0015B430(int a0) {
    int tmp0;
    int tmp3;

    tmp0 = *(int*)((char*)a0 + 4);
    GObj_IdentityB(tmp0);
    tmp3 = *(int*)(char*)a0;
    GObj_IdentityB(tmp3);
    return 0;
}
