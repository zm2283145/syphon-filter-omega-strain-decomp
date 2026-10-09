/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_0014B340(int);

int Script_cNPC_SetMaxActiveNpcCount(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)loc;
    func_0014B340(a0);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
