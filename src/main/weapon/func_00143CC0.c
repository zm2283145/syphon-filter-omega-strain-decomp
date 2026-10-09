/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

extern void func_00143B60(Inventory* inv);

void Global_ForceHolster(Inventory* inv) {
    if (inv->selected != 6) {
        func_00143B60(inv);
    }
}
