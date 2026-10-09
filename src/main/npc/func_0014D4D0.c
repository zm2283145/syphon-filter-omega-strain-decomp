/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int func_0014D510(cNPC* npc, int a1, int a2);

/* vtable slot 0x53: StopMovement. */
int cNPC_StopMovement(cNPC* self, int a1, float f12) {
    int result;

    result = func_0014D510(self, 0, a1);
    self->unk07C = f12;
    self->unk168 = 0;
    return result;
}
