/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_002232C0(int, int);

int func_003D1700(int a0) {
    int tmp0;

    tmp0 = func_002232C0(0, 1);
    *(char*)((char*)a0 + 2) = 0;
    return tmp0;
}

int func_003D1730(int a0) {
    int tmp0;

    tmp0 = func_002232C0(0, 0);
    *(char*)((char*)a0 + 2) = 1;
    return tmp0;
}
