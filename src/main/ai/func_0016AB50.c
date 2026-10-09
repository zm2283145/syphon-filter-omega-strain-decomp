/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int GObj_IdentityA(int);

int func_0016AB50(int a0) {
    int loc[1];
    int v0, v1;
    float f0;

    v1 = *(int*)(char*)(a0 + 4);
    v0 = 0;
    *(int*)(char*)loc = v1;
    v1 = *(int*)(char*)a0;
    f0 = *(float*)(char*)loc;
    *(float*)(char*)(v1 + 88) = f0;
    goto ret;
ret:
    return v0;
}

int Script_GetGOBJ_AI(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = *(int*)((char*)tmp0 + 48);
    return GObj_IdentityA(tmp1);
}

int func_0016AB90(int a0) {
    return ((unsigned int)(0) < (unsigned int)((*(int*)((char*)*(int*)((char*)*(int*)(char*)a0 + 48) + 56) ^ 128)));
}
