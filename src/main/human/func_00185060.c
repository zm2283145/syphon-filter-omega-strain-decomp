/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0049D010[];

int func_00185060(int a0, int a1) {
    return ((unsigned int)((*(int*)((char*)a0 + 76) ^ *(int*)(char*)a1)) < (unsigned int)(1));
}

int func_00185080(void) {
    return (int)D_0049D010;
}
