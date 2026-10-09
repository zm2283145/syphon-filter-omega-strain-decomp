/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* vtable slot 0x5E: SetViewConeRadius. */
void cNPC_SetViewConeRadius(cNPC* self, float radius) {
    self->ai->viewConeRadius = radius;
}
