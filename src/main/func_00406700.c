/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0036DC60(int);
extern void Appearance_PackText(int, int, int);

void func_00406700(int a0, int a1, int a2) {
    int tmp0;

    tmp0 = func_0036DC60(a1);
    Appearance_PackText(a0, tmp0, a2);
}
