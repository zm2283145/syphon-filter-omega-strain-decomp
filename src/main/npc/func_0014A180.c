/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* vtable slot 0x44: SetAimSubtarget. */
void cNPC_SetAimSubtarget(cNPC* self, signed char subtarget) {
    self->aimSubtarget = subtarget;
}
