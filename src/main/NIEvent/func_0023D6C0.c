/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Address of element i in an array of 0x40-byte records whose base pointer is at +8. */
char* func_0023D6C0(char* self, int i) {
    return *(char**)(self + 8) + (i << 6);
}
