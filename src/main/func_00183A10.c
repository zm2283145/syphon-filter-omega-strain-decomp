/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Builds a zeroed 4-byte local and returns its first byte; always 0
 * (research COL_GATHER_NATIVE.md: no triangle or mask inspection). */
int ColTri_FilterStub(void) {
    unsigned char buf[4];
    unsigned char* p;

    buf[0] = 0;
    p = buf + 1;
    do {
        *p = 0;
        p = p + 1;
    } while (p != buf + 4);
    return buf[0];
}
