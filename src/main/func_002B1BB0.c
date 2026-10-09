/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DDE60[];
extern void func_0041F690(int);

int func_002B1BB0(int a0) {
    func_0041F690(a0);
    *(int*)((char*)a0) = (int)D_004DDE60;
    *(int*)((char*)a0 + 72) = 0;
    return a0;
}
