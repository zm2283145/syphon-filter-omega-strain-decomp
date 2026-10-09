/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0016DDB0(int, int, int);
extern int func_003CC820(int);

int func_0014A210(int a0) {
    int tmp0;
    int tmp1;
    int tmp3;
    int tmp4;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = func_003CC820(tmp0);
    tmp3 = *(int*)(char*)a0;
    tmp4 = *(int*)((char*)tmp3 + 428);
    func_0016DDB0(tmp4, tmp1, 100);
    return 0;
}
