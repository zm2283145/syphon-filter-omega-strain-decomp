/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_002C5E20(int a0, int a1) {
    Q tmp0;
    int tmp1;
    int tmp2;
    int tmp3;

    tmp0 = *(Q*)(char*)a1;
    *(Q*)((char*)a0) = tmp0;
    tmp1 = *(int*)((char*)a1 + 16);
    *(int*)((char*)a0 + 16) = tmp1;
    tmp2 = *(int*)((char*)a1 + 20);
    *(int*)((char*)a0 + 20) = tmp2;
    tmp3 = *(int*)((char*)a1 + 24);
    *(int*)((char*)a0 + 24) = tmp3;
    return a0;
}
