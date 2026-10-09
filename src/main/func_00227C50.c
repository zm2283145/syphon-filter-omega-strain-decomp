/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFC2C[];
extern void func_00242B00(int, int);

void func_00227C50(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)D_004FFC2C;
    func_00242B00(tmp0, a1);
}
