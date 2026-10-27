/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* vtable slot 0x14. */
int cNPC_IsNPC(void) {
    return 1;
}

/* vtable slot 0x47. */
void cNPC_ResumeAIFiring(cNPC* self) {
    self->unk13E = 1;
    self->unk118 = 0;
}
