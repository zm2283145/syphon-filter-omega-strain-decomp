/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

extern signed char WeaponClassToSlot[];

/* Maps a weapon id through definition byte +0x30 and the WeaponClassToSlot table. */
int cWeapon_GetWeaponSlot(int id) {
    WeaponDef* def = cWeaponDB_GetEntry(g_WeaponDatabase, id);

    return WeaponClassToSlot[def->unk30];
}
