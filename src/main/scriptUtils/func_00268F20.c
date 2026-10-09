/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_002690C0(int);

int Script_Array_Count(int a0) {
    int loc[1];
    int v0;

    a0 = *(int*)(char*)a0;
    v0 = func_002690C0(a0);
    v0 = *(int*)(char*)(v0 + 8);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}
