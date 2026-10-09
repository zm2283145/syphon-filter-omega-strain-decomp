/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern float func_00142170(int);
extern int func_0016DC60(int);

int func_002D4640(int a0) {
    int tmp0;
    int tmp1;
    int tmp4;
    int tmp5;

    tmp0 = *(int*)((char*)a0 + 48);
    tmp1 = *(int*)((char*)tmp0 + 13604);
    func_00142170(tmp1);
    tmp4 = *(int*)((char*)a0 + 428);
    tmp5 = func_0016DC60(tmp4);
    return tmp5;
}
