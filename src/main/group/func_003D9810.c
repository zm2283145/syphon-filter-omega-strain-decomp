/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003D9970(int);
extern float func_003D9A00(int);

int Script_cGroup_Randomize(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_003D9970(tmp0);
    func_003D9A00(tmp1);
    return 0;
}
