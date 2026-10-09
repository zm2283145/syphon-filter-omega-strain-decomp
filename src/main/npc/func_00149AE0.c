/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void cNPC_SetSkill(int, float);

int Script_cNPC_SetSkill(int a0) {
    int loc[1];
    int v0;
    float f12;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    f12 = *(float*)(char*)loc;
    a0 = *(int*)(char*)a0;
    cNPC_SetSkill(a0, f12);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
