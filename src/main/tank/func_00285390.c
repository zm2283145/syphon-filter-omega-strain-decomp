/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "types.h"
#include "tank_types.h"

/* Sets the turret acceleration (no-op without a turret). */
void cTank_SetTurretAccel(cTank* tank, float accel) {
    cTankTurret* turret = tank->turret;

    if (turret != 0) {
        turret->accel = accel;
    }
}
