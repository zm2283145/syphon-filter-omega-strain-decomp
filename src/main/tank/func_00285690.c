#pragma cplusplus on
#include "types.h"
#include "tank_reset.h"

/* cTank: reset controller and aim. */
extern "C" void func_00285690(TankResetTank* self) { TankReset_Do(self); }
