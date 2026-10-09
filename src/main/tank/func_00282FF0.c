/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "types.h"
#include "tank_types.h"

extern int func_00285590(cTank* tank, void* target);

int Script_cTank_ClearEnemy(TankScriptArg* args) {
    func_00285590((cTank*)args[0].p, 0);
    return 0;
}
