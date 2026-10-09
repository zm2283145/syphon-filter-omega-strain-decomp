/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005436B8[];
extern char D_00555070[];
extern int func_003E1AA0(int, int, int);

void* func_003CC820(void* self) {
    return self;
}

int func_003CC830(void) {
    return (int)D_005436B8;
}

int func_003CC840(void) {
    int tmp0;

    tmp0 = *(int*)D_005436B8;
    return tmp0;
}

int func_003CC850(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}
