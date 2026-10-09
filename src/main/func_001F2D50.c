/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001F2D60(int, int);
extern int func_001F2DB0(int);
extern int func_0020B570(int, int, int, int);

void func_001F2D50(int a0, int a1) {
    func_001F2D60(a0, a1);
}

int func_001F2D60(int a0, int a1) {
    int tmp0;
    int tmp2;

    tmp0 = func_001F2DB0(a0);
    tmp2 = func_0020B570(a0, tmp0, 1, a1);
    return tmp2;
}
