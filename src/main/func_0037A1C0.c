/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_0037A370(int, int, int, int, int, int);

void func_0037A1C0(int a0, int a1, int a2, int a3) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 28);
    tmp1 = *(int*)((char*)a0 + 32);
    func_0037A370(a0, tmp0, tmp1, a1, a2, a3);
}
