/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern float Math_Clampf(float, float, float);

/* Sets a range and clamps it: x into [0,1], y into [x,1]. */
Vec2f* func_001EFE10(Vec2f* self, float x, float y) {
    self->x = x;
    self->y = y;
    self->x = Math_Clampf(self->x, 0.0f, 1.0f);
    self->y = Math_Clampf(self->y, self->x, 1.0f);
    return self;
}
