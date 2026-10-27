/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

extern int cHuman_AdjustMaxClips(void* a0, int key);

int cWeapon_AdjustMaxClips(Inventory* inv, int key) {
    return cHuman_AdjustMaxClips(inv->unk88, key);
}
