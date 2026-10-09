/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Sets the flag byte at +0xD0. */
void func_003796C0(unsigned char* self) {
    self[208] = 1;
}
