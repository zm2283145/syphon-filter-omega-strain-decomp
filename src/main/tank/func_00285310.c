/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "types.h"
#include "tank_types.h"

extern void* D_004FFD30; /* weapon definition table */
extern int func_003CC990(void* gobj, int hitpoints, int unk);

/* Sets the hitpoints of the tank's game object. */
int cTank_SetHitpoints(cTank* tank, int hitpoints) {
    return func_003CC990(tank->gobj, hitpoints, 0);
}

/* Selects the turret weapon (no-op without a turret). */
void cTank_SetWeapon(cTank* tank, int weaponId) {
    cTankTurret* turret = tank->turret;

    if (turret != 0) {
        void* table = D_004FFD30;

        turret->weaponId = weaponId;
        turret->weaponDef = WeaponDb_Get(table, weaponId);
    }
}
