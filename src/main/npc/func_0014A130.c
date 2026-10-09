/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* vtable slot 0x45: ResumeAIAiming. */
void cNPC_ResumeAIAiming(cNPC* self) {
    self->aimOverride = 0;
    self->aiAiming = 1;
    self->aimSubtarget = -1;
}
