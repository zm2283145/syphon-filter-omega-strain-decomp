/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DD6B0[];
extern void func_0041F690(int);

int func_002A0A50(int a0) {
    func_0041F690(a0);
    *(int*)((char*)a0) = (int)D_004DD6B0;
    *(char*)((char*)a0 + 72) = 0;
    return a0;
}
