/*
 * SFOGame/Source/weapon: 1 file, 00142AE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00142AE0 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_00142AE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00142AE0 */
