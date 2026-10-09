/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001F2CA0(int, int);
extern int func_001F2D20(int);
extern int func_001F3430(int);
extern void func_001F3470(void);

int func_001F33F0(int a0, int a1) {
    return func_001F2CA0(a0, a1);
}

int func_001F3400(int a0) {
    func_001F3430(a0);
    return a0;
}

int func_001F3430(int a0) {
    func_001F2D20(a0);
    return a0;
}

void func_001F3460(void) {
    func_001F3470();
}
