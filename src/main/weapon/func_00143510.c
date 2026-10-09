/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

/* Equip mode of the selected weapon; 0 when holstered (slot 6). */
int Inventory_GetEquipMode(Inventory* inv) {
    int selected = inv->selected;
    int mode = 0;

    if (selected != 6) {
        InventorySlot* slot = &inv->slots[selected];

        mode = WeaponDb_Get(D_004FFD30, slot->id)->equipMode;
    }
    return mode;
}
