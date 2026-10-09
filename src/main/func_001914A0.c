/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001914A0(int a0, int a1) {
    return ((unsigned int)(((a1 & 255) ^ *(unsigned char*)((char*)a0 + 4))) < (unsigned int)(1));
}
