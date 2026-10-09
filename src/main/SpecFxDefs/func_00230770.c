/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int GObj_IdentityB(int);
extern int Global_SpawnParticle(int, int, int);

int Script_SpawnParticle(int a0) {
    int a1, a2, s0, v0;

    s0 = *(signed char*)(char*)a0;
    a0 = *(int*)(char*)(a0 + 4);
    v0 = GObj_IdentityB(a0);
    a0 = s0;
    a1 = v0;
    a2 = 0 + 1;
    v0 = Global_SpawnParticle(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
