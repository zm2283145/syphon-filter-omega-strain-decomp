/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Reads one byte from src into out; returns 2 on a null argument. */
int func_00301900(unsigned char* src, unsigned char* out) {
    int result = 2;

    if (src != 0 && out != 0) {
        result = 0;
        *out = *src;
    }
    return result;
}
