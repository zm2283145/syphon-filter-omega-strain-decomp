/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Set w = 1.0 (homogeneous position). */
Vec4* Vec_SetPositionW1(Vec4* v) {
    v->w = 1.0f;
    return v;
}
