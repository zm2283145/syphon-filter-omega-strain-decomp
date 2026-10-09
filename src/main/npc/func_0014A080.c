/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int GObj_IdentityB(int);
extern int func_001573D0(int, int);

int func_0014A080(int a0) {
    int tmp0;
    int tmp1;
    int tmp2;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)a0 + 4);
    tmp2 = GObj_IdentityB(tmp1);
    func_001573D0(tmp0, tmp2);
    return 0;
}
