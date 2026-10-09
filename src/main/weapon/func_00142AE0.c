/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

extern int func_001861F0(void* a0, int key);

/* def->unk70 * func_001861F0(inv->unk88, def->unk74) - slot->unkC for the given slot. */
int func_00142AE0(Inventory* inv, unsigned char index) {
    WeaponDef* def;
    InventorySlot* slot = &inv->slots[index];

    def = WeaponDb_Get(D_004FFD30, slot->id);
    return def->unk70 * func_001861F0(inv->unk88, def->unk74) - slot->unkC;
}
