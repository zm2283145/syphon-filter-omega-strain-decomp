/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0013ADF0(int);

int func_001F2690(int a0) {
    return func_0013ADF0((a0 + 4));
}

int func_001F26A0(int a0, int a1) {
    *(int*)((char*)a0) = a1;
    return a0;
}
