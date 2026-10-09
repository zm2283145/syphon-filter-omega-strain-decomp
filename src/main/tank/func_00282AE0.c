/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "types.h"
#include "tank_types.h"

extern int GObj_IdentityA(void*);

int Script_cTank_GetGobj(TankScriptArg* args) {
    return GObj_IdentityA(((cTank*)args[0].p)->gobj);
}
