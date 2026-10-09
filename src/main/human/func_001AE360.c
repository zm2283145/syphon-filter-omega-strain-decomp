/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern int D_004EA0B8;

int func_001AE360(void) {
    return D_004EA0B8;
}

/* Set the float at +0x3C to 1.0 and clear the word at +0x4C. */
void func_001AE370(char* self) {
    *(float*)(self + 60) = 1.0f;
    *(int*)(self + 76) = 0;
}
