/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EA778[];
extern char D_00555070[];
extern int func_003E1AA0(int, int, int);

void* func_0015C120(void* self) {
    return self;
}

int func_0015C130(void) {
    return (int)D_004EA778;
}

int func_0015C140(void) {
    int tmp0;

    tmp0 = *(int*)D_004EA778;
    return tmp0;
}

int func_0015C150(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}
