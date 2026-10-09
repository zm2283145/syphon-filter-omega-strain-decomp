/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* vtable slot 0x5F: SetViewConeAngle(degrees); stores the half angle in radians. */
void cNPC_SetViewConeAngle(cNPC* self, float degrees) {
    NpcAi* ai;

    ai = self->ai;
    ai->viewConeHalfAngle = (0.01745329238474369f * (0.5f * degrees));
}
