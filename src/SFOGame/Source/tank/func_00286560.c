/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "types.h"
#include "tank_types.h"

void cTurret_Reset(cTankTurret* self) {
    self->unk64 = 0;
}
