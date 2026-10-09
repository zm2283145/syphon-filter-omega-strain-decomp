/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "types.h"
#include "tank_types.h"

extern void* D_004FFD30; /* weapon definition table */

/* Sets the turret weapon id and caches its definition. */
void cTurret_SetWeapon(cTankTurret* turret, int weaponId) {
    void* table = D_004FFD30;

    turret->weaponId = weaponId;
    turret->weaponDef = WeaponDb_Get(table, weaponId);
}
