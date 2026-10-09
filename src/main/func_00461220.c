/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004C25C0[];
extern char D_004F2CC0[];

int func_00461220(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 8);
    return (tmp0 + (a1 * 12));
}

int func_00461240(char* self) {
    return *(int*)(self + 4);
}

int func_00461250(void) {
    return (int)D_004F2CC0;
}

int func_00461260(void) {
    return (int)D_004C25C0;
}
