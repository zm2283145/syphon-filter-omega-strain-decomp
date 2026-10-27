/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Address of element index (0x20-byte records). */
Elem20* cHermiteSpline_cQuaternion_ControlPoint(Elem20* base, int index) {
    return base + index;
}

/* Address of element index (0x1C0-byte records). */
Elem1C0* cArray_FixedSize_cIkTargetWithSplinedTransition_2_opIndex(Elem1C0* base, int index) {
    return base + index;
}
