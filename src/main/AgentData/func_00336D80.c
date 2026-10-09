/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00336DC0(int);
extern int func_00337140(int, int, int);

int func_00336D80(int a0, int a1, int a2) {
    return func_00337140(a0, a1, a2);
}

int func_00336D90(int a0) {
    func_00336DC0(a0);
    *(char*)((char*)a0 + 12) = 1;
    return a0;
}
