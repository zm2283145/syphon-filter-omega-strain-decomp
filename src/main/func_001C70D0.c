/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void Global_SetReverb(int, int, int);

int Script_SetReverb(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    a0 = 0 + 1;
    a1 = *(int*)(char*)loc;
    a2 = a1;
    Global_SetReverb(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
