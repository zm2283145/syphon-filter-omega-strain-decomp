/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004D9778[];
extern char D_004D9788[];
extern char D_004D9798[];

int func_001652E0(int a0) {
    *(int*)((char*)a0) = (int)D_004D9778;
    *(int*)((char*)a0) = (int)D_004D9788;
    *(int*)((char*)a0) = (int)D_004D9798;
    return a0;
}
