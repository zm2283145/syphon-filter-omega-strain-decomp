/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void Global_PlayXA(int, int);

int Script_PlayXA(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)loc;
    a1 = 0;
    Global_PlayXA(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
