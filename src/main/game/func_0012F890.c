/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFC2C[];
extern int func_00245560(int, int, float);

int Global_StartGlobalTimer(int a0, float f12) {
    int tmp0;

    tmp0 = *(int*)D_004FFC2C;
    return func_00245560(tmp0, a0, f12);
}
