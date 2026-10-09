/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DFC50[];
extern int func_00132800(int, int);

void* func_001F31B0(void* self) {
    return self;
}

int MotionNode_BaseCtor(int a0, int a1, int a2) {
    *(int*)((char*)a0) = (int)D_004DFC50;
    *(char*)((char*)a0 + 4) = a1;
    func_00132800((a0 + 16), a2);
    return a0;
}
