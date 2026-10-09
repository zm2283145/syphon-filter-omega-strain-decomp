/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int D_004EA350;          /* maximum number of active NPCs */
extern int func_00186360(NpcActor* actor, int a1, int a2, int a3, int a4, float f12);

/* Sets the maximum number of active NPCs. */
void cNPC_SetMaxActiveNpcCount(int count) {
    D_004EA350 = count;
}

/* vtable slot 0x5D: SetOnFire. */
int cNPC_SetOnFire(cNPC* self, float f12) {
    return func_00186360(self->actor, 1, 0, 0, 0, f12);
}
