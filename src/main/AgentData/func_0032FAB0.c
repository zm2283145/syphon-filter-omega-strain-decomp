/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int cAgentData_HasMedal(int, int);

int Script_cAgentData_HasMedal(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(int*)(char*)a0;
    v0 = cAgentData_HasMedal(a0, a1);
    v0 = v0 & 255;
    goto ret;
ret:
    return v0;
}
