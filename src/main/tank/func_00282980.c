/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "types.h"
#include "tank_types.h"

extern int D_00506268;

/* Message type id for cNetUpdateTankMsg. */
int cNetUpdateTankMsg_v05(void) {
    return D_00506268;
}
