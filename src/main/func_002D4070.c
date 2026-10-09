/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0015DDB0(int);

void func_002D4070(int a0, int a1) {
    int tmp0;

    *(int*)((char*)a0 + 520) = a1;
    tmp0 = func_0015DDB0(a1);
    *(int*)((char*)a0 + 488) = tmp0;
}
