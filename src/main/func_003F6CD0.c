/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003A6C80(void);

void func_003F6CD0(int a0) {
    func_003A6C80();
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 48) = 0;
    *(int*)((char*)a0 + 56) = 0;
    *(int*)((char*)a0 + 60) = 0;
    *(int*)((char*)a0 + 68) = 0;
    *(int*)((char*)a0 + 80) = 0;
    *(int*)((char*)a0 + 88) = 0;
    *(int*)((char*)a0 + 92) = 0;
}
