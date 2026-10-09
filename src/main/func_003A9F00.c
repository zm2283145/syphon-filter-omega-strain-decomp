/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int SkelNodes_Construct(int);
extern void func_003A9450(int);

void func_003A9F00(int a0) {
    *(char*)((char*)a0 + 20) = 0;
    func_003A9450(a0);
}

int func_003A9F10(int a0) {
    *(char*)((char*)a0 + 20) = 1;
    return SkelNodes_Construct(a0);
}
