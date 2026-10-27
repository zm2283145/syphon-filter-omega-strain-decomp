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
