/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int GObj_IdentityB(int);
extern int func_0016DDB0(int, int, int);

int func_0014A1C0(int a0) {
    int v0, v1;

    v1 = *(int*)(char*)a0;
    v0 = 0;
    v1 = *(int*)(char*)(v1 + 428);
    *(int*)(char*)(v1 + 28) = 0;
    goto ret;
ret:
    return v0;
}

int func_0014A1E0(int a0) {
    int a1, a2, v0;

    a1 = 0;
    v0 = *(int*)(char*)a0;
    a0 = *(int*)(char*)(v0 + 428);
    a2 = 0 + 100;
    v0 = func_0016DDB0(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_0014A210(int a0) {
    int tmp0;
    int tmp1;
    int tmp3;
    int tmp4;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = GObj_IdentityB(tmp0);
    tmp3 = *(int*)(char*)a0;
    tmp4 = *(int*)((char*)tmp3 + 428);
    func_0016DDB0(tmp4, tmp1, 100);
    return 0;
}
