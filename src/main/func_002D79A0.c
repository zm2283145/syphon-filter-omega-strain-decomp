/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Writes the object's position as a homogeneous vector (w = 1). */
void func_002D79A0(PosObj38* self, Vec4* out) {
    float x;
    float y;
    float z;

    x = self->x;
    out->x = x;
    y = self->y;
    out->y = y;
    z = self->z;
    out->z = z;
    out->w = 1.0f;
}
