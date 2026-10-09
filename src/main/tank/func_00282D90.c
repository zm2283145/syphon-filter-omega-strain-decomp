/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "types.h"
#include "tank_types.h"

int Script_cTank_SetTurretAccel(TankScriptArg* args) {
    volatile int bits = args[1].i; /* mirrors the original stack temporary */
    cTankTurret* turret = ((cTank*)args[0].p)->turret;
    float accel = *(float*)&bits;

    if (turret != 0) {
        turret->accel = accel;
    }
    return 0;
}
