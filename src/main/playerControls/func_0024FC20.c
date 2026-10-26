/*
 * Matched functions (byte-identical with the retail executable).
 * Player input-state helpers and small value types used by the input code.
 */

#include "types.h"
#include "playerControls_types.h"

void cGameCamera_SetDesiredFOV(PlayerCamera* self, float value) {
    self->fovTarget = value;
}
