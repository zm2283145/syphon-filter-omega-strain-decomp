/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFB50[];
extern int ActiveList_RemoveObject(int, int);
extern int func_00131320(int, int);

int func_0017A5D0(int a0) {
    return ActiveList_RemoveObject((int)D_004FFB50, a0);
}

int func_0017A5E0(int a0) {
    return func_00131320((int)D_004FFB50, a0);
}

void* func_0017A5F0(char* self) {
    return self + 2832;
}
