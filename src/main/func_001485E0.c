/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Global_ResetNpc(int);

int Script_ResetNpc(int a0) {
    int tmp0;

    tmp0 = *(int*)(char*)a0;
    Global_ResetNpc(tmp0);
    return 0;
}
