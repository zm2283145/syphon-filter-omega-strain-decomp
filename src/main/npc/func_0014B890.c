/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int func_00143DF0(NpcWeaponSet* weapons, int weapon, int a2, int a3, int a4, int a5);

/* vtable slot 0x6C: AddWeapon. */
int cNPC_AddWeapon(cNPC* self, int weapon) {
    NpcActor* actor;

    actor = self->actor;
    return func_00143DF0(actor->weapons, weapon, 1, 0, 0, 0);
}
