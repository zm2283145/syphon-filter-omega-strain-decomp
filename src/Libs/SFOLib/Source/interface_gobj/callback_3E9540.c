/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

unsigned int D_00493980[2] = { 0x3F800000, 0x0 };

void cMAP_GOBJ_SetScale(float value) {
    (*(float*)D_00493980) = value;
}
