/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0049D010[];

int func_00185060(char* self, int* key) {
    return *(int*)(self + 76) == *key;
}

void* func_00185080(void) {
    return D_0049D010;
}
