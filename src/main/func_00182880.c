/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00181E80(int, int);
extern int func_00182260(int, int);

int func_00182880(int a0) {
    int loc[1];
    int a1, v0;

    a1 = (int)loc;
    v0 = *(int*)(char*)(a0 + 16);
    *(int*)(char*)loc = v0;
    v0 = func_00181E80(a0, a1);
    goto ret;
ret:
    return v0;
}

int func_001828B0(int a0) {
    int loc[1];
    int a1, v0;

    a1 = (int)loc;
    v0 = *(int*)(char*)(a0 + 8);
    *(int*)(char*)loc = v0;
    v0 = func_00182260(a0, a1);
    goto ret;
ret:
    return v0;
}
