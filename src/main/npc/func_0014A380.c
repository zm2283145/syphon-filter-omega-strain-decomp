/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int func_0016C590(NpcAi* ai, int player);

/* vtable slot 0x3B: ResendNewAwarenessMessage. */
int cNPC_ResendNewAwarenessMessage(cNPC* self, int player) {
    return func_0016C590(self->ai, player);
}
