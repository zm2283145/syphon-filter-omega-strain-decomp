/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00173970(int);

int func_003ECAF0(int a0) {
    *(int*)((char*)a0) = 0;
    func_00173970(a0);
    *(int*)((char*)a0 + 8) = (a0 + 4);
    *(int*)((char*)a0 + 4) = (a0 + 4);
    return a0;
}

int func_003ECB30(int a0) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = 0;
    *(int*)((char*)a0 + 8) = 0;
    *(char*)((char*)a0 + 12) = 0;
    return a0;
}
