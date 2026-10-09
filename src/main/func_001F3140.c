/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001F3170(int, int);
extern int func_001F31B0(int);

int func_001F3140(int a0, int a1) {
    func_001F3170(a0, a1);
    return a0;
}

int func_001F3170(int a0, int a1) {
    func_001F31B0(a0);
    *(int*)((char*)a0) = a1;
    return a0;
}
