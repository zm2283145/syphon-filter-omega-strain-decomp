/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00157800(int, int);
extern int GObj_IdentityB(int);

int func_0014A280(int a0) {
    int tmp0;
    int tmp1;
    int tmp2;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)a0 + 4);
    tmp2 = GObj_IdentityB(tmp1);
    func_00157800(tmp0, tmp2);
    return 0;
}

int func_0014A2C0(int a0) {
    int a1, v0;

    a0 = *(int*)(char*)a0;
    a1 = 0;
    v0 = func_00157800(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
