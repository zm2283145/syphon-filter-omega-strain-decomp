/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00506278[];
extern char D_00555070[];
extern int func_003E1AA0(int, int, int);

void* func_002837B0(void* self) {
    return self;
}

void* func_002837C0(void* self) {
    return self;
}

int func_002837D0(void) {
    return (int)D_00506278;
}

int func_002837E0(void) {
    return (int)D_00506278;
}

int func_002837F0(void) {
    int tmp0;

    tmp0 = *(int*)D_00506278;
    return tmp0;
}

int func_00283800(int a0, int a1) {
    return func_003E1AA0((int)D_00555070, a0, a1);
}
