/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DDDE0[];
extern int func_0041EFA0(int);
extern void func_0041F690(int);

int func_002B0D10(int a0) {
    return func_0041EFA0(a0);
}

int func_002B0D20(int a0) {
    func_0041F690(a0);
    *(int*)((char*)a0) = (int)D_004DDDE0;
    return a0;
}
