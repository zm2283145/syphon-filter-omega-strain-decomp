/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001F40C0(int, int);
extern int func_001F4110(int);
extern int func_0020A080(int, int, int, int);

void func_001F40B0(int a0, int a1) {
    func_001F40C0(a0, a1);
}

int func_001F40C0(int a0, int a1) {
    int tmp0;
    int tmp2;

    tmp0 = func_001F4110(a0);
    tmp2 = func_0020A080(a0, tmp0, 1, a1);
    return tmp2;
}
