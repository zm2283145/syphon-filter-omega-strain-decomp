/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001F2E20(int);

int func_001F2E10(int a0) {
    return func_001F2E20(a0);
}

int func_001F2E20(int a0) {
    return (*(int*)(char*)a0 + 8);
}
