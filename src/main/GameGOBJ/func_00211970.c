/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern int Lift_CreateInfoObject(cElevatorGOBJ* lift);

int cElevatorGOBJ_v3D(cElevatorGOBJ* lift) {
    return Lift_CreateInfoObject(lift);
}
