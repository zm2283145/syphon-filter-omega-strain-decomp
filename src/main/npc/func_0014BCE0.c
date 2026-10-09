/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* vtable slot 0x59: SetFiringThreshold; returns the previous value. */
float cNPC_SetFiringThreshold(cNPC* self, float threshold) {
    float old;

    old = self->firingThreshold;
    self->firingThreshold = threshold;
    return old;
}
