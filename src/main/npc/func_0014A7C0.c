/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int func_0018C9D0(NpcActor* actor, int a1, int a2);
extern int func_001992B0(NpcActor* actor, int a1, int a2);

/* vtable slot 0x7F: SetFireInvulnerability. */
void cNPC_SetFireInvulnerability(cNPC* self, char on) {
    self->actor->fireInvulnerable = on;
}

/* vtable slot 0x7E: DontDropWeapons. */
void cNPC_DontDropWeapons(cNPC* self) {
    self->actor->weapons->dontDropWeapons = 1;
}

/* vtable slot 0x7A: EquipGoggles. */
int cNPC_EquipGoggles(cNPC* self, int a1) {
    return func_001992B0(self->actor, a1, 0);
}

/* vtable slot 0x79: RequestDeathAnimation. */
int cNPC_RequestDeathAnimation(cNPC* self, int a1) {
    return func_0018C9D0(self->actor, a1, 0);
}
