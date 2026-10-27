/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

extern int cHuman_AdjustMaxClips(void* a0, int key);

/* def->unk70 * cHuman_AdjustMaxClips(inv->unk88, def->unk74) - slot->unkC for the given slot. */
int cWeapon_NeededAmmo(Inventory* inv, unsigned char index) {
    WeaponDef* def;
    InventorySlot* slot = &inv->slots[index];

    def = cWeaponDB_GetEntry(g_WeaponDatabase, slot->id);
    return def->unk70 * cHuman_AdjustMaxClips(inv->unk88, def->unk74) - slot->unkC;
}
