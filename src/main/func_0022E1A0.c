/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00175FA0(int);
extern int func_0022E1D0(int);

int func_0022E1A0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_00175FA0(tmp0);
    func_0022E1D0(tmp1);
    return 0;
}
