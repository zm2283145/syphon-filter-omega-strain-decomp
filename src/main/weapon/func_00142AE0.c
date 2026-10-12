/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

extern int WeaponInv_ClipsForActor(void* a0, int key);

/* def->unk70 * WeaponInv_ClipsForActor(inv->unk88, def->unk74) - slot->unkC for the given slot. */
int func_00142AE0(Inventory* inv, unsigned char index) {
    WeaponDef* def;
    InventorySlot* slot = &inv->slots[index];

    def = WeaponDb_Get(D_004FFD30, slot->id);
    return def->unk70 * WeaponInv_ClipsForActor(inv->unk88, def->unk74) - slot->unkC;
}
