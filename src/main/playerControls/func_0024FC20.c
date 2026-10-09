/*
 * Matched functions (byte-identical with the retail executable).
 * Player input-state helpers and small value types used by the input code.
 */

#include "types.h"
#include "playerControls_types.h"

void func_0024FC20(PlayerCamera* self, float value) {
    self->fovTarget = value;
}
