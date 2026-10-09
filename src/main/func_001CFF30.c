/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Address of element index of a 0x1D0-byte record array. */
Elem1D0* func_001CFF30(Vec1D0Array* v, int index) {
    Elem1D0* data;

    data = v->data;
    return data + index;
}
