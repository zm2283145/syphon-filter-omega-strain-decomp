/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int func_0016C9D0(NpcAi* ai, int gobj, int flag, float value);

/* vtable slot 0x37: AddAwareness. */
int cNPC_AddAwareness(cNPC* self, int gobj) {
    return func_0016C9D0(self->ai, gobj, 1, 0.0f);
}
