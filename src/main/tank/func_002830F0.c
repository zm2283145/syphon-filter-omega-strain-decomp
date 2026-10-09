/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "types.h"
#include "tank_types.h"

extern void* GObj_IdentityB(int);
extern int func_00285590(cTank* tank, void* target);

int Script_cTank_AimAt(TankScriptArg* args) {
    cTank* tank = (cTank*)args[0].p;

    func_00285590(tank, GObj_IdentityB(args[1].i));
    return 0;
}
