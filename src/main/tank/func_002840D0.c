/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "types.h"
#include "tank_types.h"

extern int Global_CreateTank(void* gobj);
extern void* func_002379D0(int handle);

int Script_CreateTank(TankScriptArg* args) {
    volatile int tank = Global_CreateTank(func_002379D0(args[0].i)); /* mirrors the original stack temporary */
    return tank;
}
