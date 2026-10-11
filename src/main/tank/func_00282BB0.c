#pragma cplusplus on
#include "types.h"
#include "tank_reset.h"

/* Script binding: reset the tank in the first argument. */
extern "C" int Script_cTank_Reset(TankResetTank** args) { TankReset_Do(*args); return 0; }
