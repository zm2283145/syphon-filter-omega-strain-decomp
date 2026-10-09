/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void Script_Unschedule(int);

int Script_UnscheduleThunk(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)loc;
    Script_Unschedule(a0);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
