/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004D9700[];
extern char D_004D9710[];
extern char D_004D9720[];

int func_00163890(int a0) {
    *(int*)((char*)a0) = (int)D_004D9720;
    *(int*)((char*)a0) = (int)D_004D9700;
    *(int*)((char*)a0) = (int)D_004D9710;
    return a0;
}
