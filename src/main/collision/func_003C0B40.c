/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Byte copy-assign. */
unsigned char* func_003C0B40(unsigned char* dst, unsigned char* src) {
    *dst = *src;
    return dst;
}
