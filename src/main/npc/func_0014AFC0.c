/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int func_0016C1E0(NpcAi* ai, int gobj, int a2);
extern int func_003CE850(NpcActor* actor, int a1);

/* vtable slot 0x60: InViewCone. */
int cNPC_InViewCone(cNPC* self, int gobj) {
    return func_0016C1E0(self->ai, gobj, 1);
}

/* vtable slot 0x3A: GetClosestPlayer. */
int cNPC_GetClosestPlayer(cNPC* self) {
    return func_003CE850(self->actor, 0);
}
