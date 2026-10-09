/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EE788[];
extern char D_00555070[];
extern int func_003E1AA0(int, int, int);

void* func_00175FA0(void* self) {
    return self;
}

int func_00175FB0(void) {
    return (int)D_004EE788;
}

int func_00175FC0(void) {
    int tmp0;

    tmp0 = *(int*)D_004EE788;
    return tmp0;
}

int func_00175FD0(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}
