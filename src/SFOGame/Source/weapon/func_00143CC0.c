/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

extern void cWeapon_StoreWeapon_void(Inventory* inv);

void cWeapon_ForceHolster(Inventory* inv) {
    if (inv->selected != 6) {
        cWeapon_StoreWeapon_void(inv);
    }
}
