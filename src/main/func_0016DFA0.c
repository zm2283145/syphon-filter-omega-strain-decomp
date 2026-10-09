/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0053834C[];
extern char D_005383C8[];

void func_0016DFA0(int a0) {
    float tmp0;
    int tmp1;

    *(int*)((char*)a0 + 20) = 1061752795;
    tmp0 = *(float*)D_0053834C;
    *(float*)((char*)a0 + 16) = tmp0;
    tmp1 = *(int*)D_005383C8;
    *(int*)((char*)a0 + 80) = (tmp1 + 20);
}
