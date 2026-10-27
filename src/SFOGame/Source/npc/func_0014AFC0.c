/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int cAITarget_TestGobjInViewCone(NpcAi* ai, int gobj, int a2);
extern int cGOBJ_GetClosestPlayer(NpcActor* actor, int a1);

/* vtable slot 0x60: InViewCone. */
int cNPC_InViewCone(cNPC* self, int gobj) {
    return cAITarget_TestGobjInViewCone(self->ai, gobj, 1);
}

/* vtable slot 0x3A: GetClosestPlayer. */
int cNPC_GetClosestPlayer(cNPC* self) {
    return cGOBJ_GetClosestPlayer(self->actor, 0);
}
