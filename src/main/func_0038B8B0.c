/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004933D0[];

void func_0038B8B0(int a0, int a1) {
    *(int*)((char*)((int)D_004933D0 + ((a0 & 255) << 2))) = a1;
}
