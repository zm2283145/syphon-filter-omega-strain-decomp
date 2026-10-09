/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* vtable slot 0x66: SetGrenadeThrowAngle. */
void cNPC_SetGrenadeThrowAngle(cNPC* self, float angle) {
    self->grenadeThrowAngle = angle;
}
