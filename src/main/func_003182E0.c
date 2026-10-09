/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Scales a value by the owner's scale factor. */
float func_003182E0(ParamOwner* self, float* value) {
    return *value * self->scale;
}
