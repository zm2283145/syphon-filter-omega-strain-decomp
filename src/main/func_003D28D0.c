/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E00A8[];
extern int func_00139070(int);

int func_003D28D0(int a0) {
    *(int*)((char*)a0 + 16) = (int)D_004E00A8;
    func_00139070(a0);
    *(char*)((char*)a0 + 12) = 0;
    return a0;
}
