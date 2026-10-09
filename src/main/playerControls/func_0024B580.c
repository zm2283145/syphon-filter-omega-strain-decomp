/*
 * Matched functions (byte-identical with the retail executable).
 * Player input-state helpers and small value types used by the input code.
 */

#include "types.h"
#include "playerControls_types.h"

extern int func_0024A600(InputState* self, int a1);
extern int func_0024A660(InputState* self, int a1);

void func_0024B580(InputState* self) {
    self->unk26 = 0;
}

void func_0024B590(InputState* self, int unk27, int* unk28) {
    self->unk26 = 1;
    self->unk27 = unk27;
    self->unk28 = *unk28;
}

/* Leaving a code-9 (crouch) zone. */
int InputState_LeaveCrouchZone(InputState* self, int a1) {
    self->crouchZone = 0;
    return func_0024A600(self, a1);
}

/* Entering a code-9 (crouch) zone. */
int InputState_EnterCrouchZone(InputState* self, int a1) {
    self->crouchZone = 1;
    return func_0024A660(self, a1);
}
