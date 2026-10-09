/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003B91B0(int, int, int);

int func_003B9170(int a0, int a1, int a2) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = 0;
    *(int*)((char*)a0 + 8) = 0;
    *(int*)((char*)a0 + 12) = 0;
    func_003B91B0(a0, a1, a2);
    return a0;
}
