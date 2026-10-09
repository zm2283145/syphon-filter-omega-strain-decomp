/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* vtable slot 0x14. */
int cNPC_v14(void) {
    return 1;
}

/* vtable slot 0x47. */
void cNPC_v47(cNPC* self) {
    self->unk13E = 1;
    self->unk118 = 0;
}
