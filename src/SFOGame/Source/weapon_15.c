/*
 * SFOGame/Source/weapon: 1 file, 00143510
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00143510 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

/* Equip mode of the selected weapon; 0 when holstered (slot 6). */
int cWeapon_GetPoseType(Inventory* inv) {
    int selected = inv->selected;
    int mode = 0;

    if (selected != 6) {
        InventorySlot* slot = &inv->slots[selected];

        mode = cWeaponDB_GetEntry(g_WeaponDatabase, slot->id)->equipMode;
    }
    return mode;
}
static inline void merge_flush_func_00143510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00143510 */
