/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Returns true if byte +0x64 or byte +0x62 of the object is set. */
int func_0012FD40(unsigned char* self) {
    return self[100] != 0 || self[98] != 0;
}
