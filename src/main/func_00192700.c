/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001BDA10(int, int, int, int);

int func_00192700(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 8);
    tmp1 = *(int*)((char*)a0 + 4);
    return func_001BDA10(a0, (tmp0 + (tmp1 * 20)), 1, a1);
}

int func_00192730(int a0, int a1, int a2) {
    *(int*)((char*)a0) = a1;
    *(int*)((char*)a0 + 4) = a2;
    return a0;
}
