/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7E70[];
extern float func_003D0810(int, int);

float func_00251040(int a0) {
    *(char*)((char*)a0 + 16) = 1;
    *(char*)((char*)a0 + 17) = 1;
    return func_003D0810(a0, (int)D_004F7E70);
}
