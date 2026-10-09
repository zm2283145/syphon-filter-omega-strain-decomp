/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int ScalarCollection_Init(int);

int func_003AD310(int a0, int a1) {
    return ((unsigned int)((*(int*)((char*)a0 + 16) ^ *(int*)((char*)a1 + 16))) < (unsigned int)(1));
}

int TransitionReq_Construct(int a0, float f12) {
    ScalarCollection_Init(a0);
    *(float*)((char*)a0 + 12) = f12;
    return a0;
}

int func_003AD370(int a0) {
    int v0, v1;

    *(int*)(char*)a0 = 0;
    v0 = 0x7f7f0000;
    v1 = v0 | 0xffff;
    *(int*)(char*)(a0 + 4) = 0;
    *(int*)(char*)(a0 + 8) = v1;
    v0 = a0;
    *(int*)(char*)(a0 + 12) = v1;
    *(int*)(char*)(a0 + 16) = 0;
    goto ret;
ret:
    return v0;
}
