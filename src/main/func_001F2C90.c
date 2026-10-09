/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001F2CA0(int, int);
extern int func_001F2CF0(int);
extern int func_001F2D20(int);
extern void func_001F2D50(void);

int func_001F2C90(int a0, int a1) {
    return func_001F2CA0(a0, a1);
}

int func_001F2CA0(int a0, int a1) {
    return ((unsigned int)(0) < (unsigned int)((*(int*)(char*)a0 ^ *(int*)(char*)a1)));
}

int func_001F2CC0(int a0) {
    func_001F2CF0(a0);
    return a0;
}

int func_001F2CF0(int a0) {
    func_001F2D20(a0);
    return a0;
}

int func_001F2D20(int a0) {
    *(int*)((char*)a0) = *(int*)((char*)*(int*)(char*)a0 + 4);
    return a0;
}

void func_001F2D40(void) {
    func_001F2D50();
}
