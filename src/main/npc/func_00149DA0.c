/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* vtable slot 0x4F: ResumeAITravelSpeed (drop the scripted override). */
void cNPC_ResumeAITravelSpeed(cNPC* self) {
    self->travelSpeedOverride = 0;
}
