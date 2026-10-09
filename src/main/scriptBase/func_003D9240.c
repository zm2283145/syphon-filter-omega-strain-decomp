/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003D9470(int, int, int);

int func_003D9240(int a0, int a1, int a2) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = 0;
    *(int*)((char*)a0 + 8) = 0;
    func_003D9470(a0, a1, a2);
    return a0;
}
