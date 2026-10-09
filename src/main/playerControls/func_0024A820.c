/*
 * Matched functions (byte-identical with the retail executable).
 * Player input-state helpers and small value types used by the input code.
 */

#include "types.h"
#include "playerControls_types.h"

/* True when crouchZone is set and unk25 is clear. */
int func_0024A820(InputState* self) {
    int result = !(self->unk25 != 0);

    if (result) {
        result = self->crouchZone != 0;
    }
    return result;
}
