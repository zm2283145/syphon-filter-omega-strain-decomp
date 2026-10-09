/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00285590(int, int);

int Script_cTank_ClearEnemy(int a0) {
    int a1, v0;

    a0 = *(int*)(char*)a0;
    a1 = 0;
    v0 = func_00285590(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
