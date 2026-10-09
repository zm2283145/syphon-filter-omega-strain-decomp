/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "types.h"
#include "tank_types.h"

extern int func_003CC990(void* gobj, int hitpoints, int unk);

int Script_cTank_SetHitpoints(TankScriptArg* args) {
    volatile int hitpoints = args[1].i; /* mirrors the original stack temporary */
    func_003CC990(((cTank*)args[0].p)->gobj, hitpoints, 0);
    return 0;
}
