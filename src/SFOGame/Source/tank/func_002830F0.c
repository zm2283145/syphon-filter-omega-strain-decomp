/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "types.h"
#include "tank_types.h"

extern void* cGOBJ_SOBJ_convert(int);
extern int cTank_AimAt(cTank* tank, void* target);

int Script_cTank_AimAt(TankScriptArg* args) {
    cTank* tank = (cTank*)args[0].p;

    cTank_AimAt(tank, cGOBJ_SOBJ_convert(args[1].i));
    return 0;
}
