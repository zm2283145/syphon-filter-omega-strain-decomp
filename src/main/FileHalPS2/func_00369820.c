/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00533860[];
extern int func_00369050(int, int, int);

int func_00369820(int a0, int a1, int a2) {
    *(int*)((char*)a0) = -1;
    *(int*)((char*)a0 + 40) = 0;
    *(int*)((char*)a0 + 196) = 0;
    *(char*)((char*)a0 + 65) = 0;
    *(char*)((char*)a0 + 64) = 0;
    *(int*)((char*)a0 + 60) = 0;
    func_00369050(a0, a1, a2);
    return a0;
}

int func_00369870(int a0) {
    *(int*)((char*)a0) = -1;
    *(int*)((char*)a0 + 40) = 0;
    *(int*)((char*)a0 + 196) = 0;
    *(char*)((char*)a0 + 65) = 0;
    *(char*)((char*)a0 + 64) = 0;
    *(int*)((char*)a0 + 60) = 0;
    return a0;
}

void func_003698A0(int a0) {
    *(int*)D_00533860 = a0;
}
