/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0023E3D0(int, float);

int Script_cNIEventOBJ_SetSpeed(int a0) {
    int loc[1];
    int v0;
    float f12;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    f12 = *(float*)(char*)loc;
    a0 = *(int*)(char*)a0;
    v0 = func_0023E3D0(a0, f12);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
