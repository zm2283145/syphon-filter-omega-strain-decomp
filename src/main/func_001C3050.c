/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001C30A0(int, int);
extern int func_001C3210(int, int, int);

int func_001C3050(int a0, int a1, int a2) {
    int tmp2;

    func_001C30A0(a0, a1);
    tmp2 = func_001C3210(a0, a1, a2);
    return tmp2;
}
