/*
 * Matched functions (byte-identical with the retail executable).
 * Player input-state helpers and small value types used by the input code.
 */

#include "types.h"
#include "playerControls_types.h"

Vec3f* func_00250190(Vec3f* self, float x, float y, float z) {
    self->x = x;
    self->y = y;
    self->z = z;
    return self;
}
