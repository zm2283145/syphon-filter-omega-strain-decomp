/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int func_0016C8D0(NpcAi* ai, int gobj);

/* vtable slot 0x38: RemoveAwareness. */
int cNPC_RemoveAwareness(cNPC* self, int gobj) {
    return func_0016C8D0(self->ai, gobj);
}
