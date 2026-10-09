/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern float func_00192740(float, float, float);

/* Sets a range and clamps it: x into [0,1], y into [x,1]. */
Vec2f* func_001EFE10(Vec2f* self, float x, float y) {
    self->x = x;
    self->y = y;
    self->x = func_00192740(self->x, 0.0f, 1.0f);
    self->y = func_00192740(self->y, self->x, 1.0f);
    return self;
}
