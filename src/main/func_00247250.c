/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_002472E0(int);
extern int func_003CB1A0(int);

int func_00247250(int a0) {
    int tmp0;
    int tmp1;
    int tmp3;
    int tmp4;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_002472E0(tmp0);
    tmp3 = *(int*)((char*)tmp1 + 36);
    tmp4 = func_003CB1A0(tmp3);
    return tmp4;
}
