/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

void* func_001AE140(char* self) {
    return self + 96;
}

/* Clear byte +0x3A5 of the 0x70-byte record i. */
void func_001AE150(char* self, int i) {
    i = i & 255;
    self[(((i << 3) - i) << 4) + 933] = 0;
}
