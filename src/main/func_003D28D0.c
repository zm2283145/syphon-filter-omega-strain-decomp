/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E00A8[];
extern int ScalarCollection_Init(int);

int func_003D28D0(int a0) {
    *(int*)((char*)a0 + 16) = (int)D_004E00A8;
    ScalarCollection_Init(a0);
    *(char*)((char*)a0 + 12) = 0;
    return a0;
}
