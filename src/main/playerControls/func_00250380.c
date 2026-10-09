/*
 * Matched functions (byte-identical with the retail executable).
 * Player input-state helpers and small value types used by the input code.
 */

#include "types.h"
#include "playerControls_types.h"

float func_00250380(ControlsUnk934* self) {
    return -self->unk934;
}

Vec2f* func_00250390(Vec2f* dst, Vec2f* src) {
    dst->x = src->x;
    dst->y = src->y;
    return dst;
}
