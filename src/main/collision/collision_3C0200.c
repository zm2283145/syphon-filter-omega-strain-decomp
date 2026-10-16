/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Address of element `index` in a vector of 112-byte elements. */
Elem112* func_003C0200(Vec112* v, int index) {
    return &v->data[index];
}
