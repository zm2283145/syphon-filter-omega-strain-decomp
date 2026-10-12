/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

extern int WeaponInv_ClipsForActor(void* a0, int key);

int func_00143DE0(Inventory* inv, int key) {
    return WeaponInv_ClipsForActor(inv->unk88, key);
}
