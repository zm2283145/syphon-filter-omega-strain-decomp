/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int g_MaxActiveNpcCount;          /* maximum number of active NPCs */
extern int Actor_Ignite(NpcActor* actor, int a1, int a2, int a3, int a4, float f12);

/* Sets the maximum number of active NPCs. */
void cNPC_SetMaxActiveNpcCount(int count) {
    g_MaxActiveNpcCount = count;
}

/* vtable slot 0x5D: SetOnFire. */
int cNPC_SetOnFire(cNPC* self, float f12) {
    return Actor_Ignite(self->actor, 1, 0, 0, 0, f12);
}
