/*
 * Matched functions (byte-identical with the retail executable).
 * Player input-state helpers and small value types used by the input code.
 */

#include "types.h"
#include "playerControls_types.h"

extern int PlayerInput_OnCrouchZoneExit(InputState* self, int a1);
extern int PlayerInput_OnCrouchZoneEnter(InputState* self, int a1);

void InputState_LeaveJumpZone(InputState* self) {
    self->unk26 = 0;
}

void InputState_EnterJumpZone(InputState* self, int unk27, int* unk28) {
    self->unk26 = 1;
    self->unk27 = unk27;
    self->unk28 = *unk28;
}

/* Leaving a code-9 (crouch) zone. */
int InputState_LeaveCrouchZone(InputState* self, int a1) {
    self->crouchZone = 0;
    return PlayerInput_OnCrouchZoneExit(self, a1);
}

/* Entering a code-9 (crouch) zone. */
int InputState_EnterCrouchZone(InputState* self, int a1) {
    self->crouchZone = 1;
    return PlayerInput_OnCrouchZoneEnter(self, a1);
}
