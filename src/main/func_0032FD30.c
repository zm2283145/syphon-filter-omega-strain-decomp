/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int AgentData_TotalPoints(int);

int func_0032FD30(int a0) {
    int loc[1];
    int v0;

    a0 = *(int*)(char*)a0;
    v0 = AgentData_TotalPoints(a0);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

void func_0032FD60(void) {
}
