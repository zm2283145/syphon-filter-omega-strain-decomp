/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Reads a big-endian 16-bit value from src into out; returns 2 on a null argument. */
int func_00301BA0(unsigned char* src, short* out) {
    int result = 2;
    int v;

    if (src != 0 && out != 0) {
        v = src[0];
        result = 0;
        v = v << 8;
        *out = v;
        /* the low byte is loaded into src's register in the original */
        src = (unsigned char*)src[1];
        *out = v | (int)src;
    }
    return result;
}
