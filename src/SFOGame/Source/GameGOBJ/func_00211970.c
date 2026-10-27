/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern int cElevatorGOBJ_CreateElevatorInfo(cElevatorGOBJ* lift);

int cElevatorGOBJ_InitNetwork(cElevatorGOBJ* lift) {
    return cElevatorGOBJ_CreateElevatorInfo(lift);
}
