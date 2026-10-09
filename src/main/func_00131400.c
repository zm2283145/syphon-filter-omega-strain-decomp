/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_002426D0(int);

int World_RegisterActor(int a0, int a1) {
    int v0;

    *(int*)(char*)(a0 + 188) = a1;
    v0 = *(int*)(char*)(a1 + 48);
    a0 = v0 + 12;
    v0 = func_002426D0(a0);
    goto ret;
ret:
    return v0;
}
