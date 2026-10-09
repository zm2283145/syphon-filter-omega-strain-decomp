/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001748F0(int, int, int);
extern int func_00174A20(int, int, int);

int func_00174770(int a0, int a1, int a2) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = 0;
    *(int*)((char*)a0 + 8) = 0;
    func_00174A20(a0, a1, a2);
    return a0;
}

int func_001747B0(int a0, int a1, int a2) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = 0;
    *(int*)((char*)a0 + 8) = 0;
    func_001748F0(a0, a1, a2);
    return a0;
}
