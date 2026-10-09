/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

extern int func_001861F0(void* a0, int key);

int func_00143DE0(Inventory* inv, int key) {
    return func_001861F0(inv->unk88, key);
}
