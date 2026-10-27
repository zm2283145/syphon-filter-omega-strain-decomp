/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Address of 32-byte element i. */
char* cHermiteSpline_cVector_ControlPoint(char* base, int i) {
    return base + (i << 5);
}
