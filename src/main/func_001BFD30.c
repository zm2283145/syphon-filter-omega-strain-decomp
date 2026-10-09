/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Global_LoadAnimation(int);

int Script_LoadAnimation(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)loc;
    v0 = Global_LoadAnimation(a0);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
