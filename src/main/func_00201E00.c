/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00201E30(int, int, int);
extern int func_00201E70(int);

int func_00201E00(int a0, int a1, int a2) {
    func_00201E30(a0, a1, a2);
    return a0;
}

int func_00201E30(int a0, int a1, int a2) {
    func_00201E70(a0);
    *(int*)((char*)a0) = a2;
    return a0;
}
