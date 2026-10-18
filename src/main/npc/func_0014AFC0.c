/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int NpcPerception_InViewCone(NpcAi* ai, int gobj, int a2);
extern int Object_ClosestPlayerDistSq(NpcActor* actor, int a1);

/* vtable slot 0x60: InViewCone. */
int cNPC_InViewCone(cNPC* self, int gobj) {
    return NpcPerception_InViewCone(self->ai, gobj, 1);
}

/* vtable slot 0x3A: GetClosestPlayer. */
int cNPC_GetClosestPlayer(cNPC* self) {
    return Object_ClosestPlayerDistSq(self->actor, 0);
}
