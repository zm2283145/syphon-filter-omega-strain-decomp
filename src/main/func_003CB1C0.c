/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00543640[];
extern char D_00555070[];
extern int func_003E1AA0(int, int, int);

void* func_003CB1C0(void* self) {
    return self;
}

int func_003CB1D0(void) {
    return (int)D_00543640;
}

int func_003CB1E0(void) {
    int tmp0;

    tmp0 = *(int*)D_00543640;
    return tmp0;
}

int func_003CB1F0(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}

int func_003CB210(void) {
    return 0;
}

int func_003CB220(char* self) {
    return *(int*)(self + 8);
}
