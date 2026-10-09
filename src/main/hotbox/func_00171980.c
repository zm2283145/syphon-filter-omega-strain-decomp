/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004D99A0[];
extern int cHotbox_ctor(int, int, int);

int func_00171980(int a0, int a1) {
    cHotbox_ctor(a0, a1, 12);
    *(int*)((char*)a0) = (int)D_004D99A0;
    return a0;
}
