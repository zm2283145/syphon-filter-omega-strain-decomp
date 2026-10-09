/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* vtable slot 0x70: SetWeaponPreferenceDistance. */
void cNPC_SetWeaponPreferenceDistance(cNPC* self, float distance) {
    self->weaponPreferenceDistance = distance;
}
