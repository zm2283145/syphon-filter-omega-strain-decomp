/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00267860(int, int, float);
extern int GObj_IdentityB(int);

int func_002677D0(int a0) {
    int loc[1];
    int a1, v0;
    float f12;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = GObj_IdentityB(a0);
    f12 = *(float*)(char*)loc;
    a0 = v0;
    a1 = 0;
    v0 = func_00267860(a0, a1, f12);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
