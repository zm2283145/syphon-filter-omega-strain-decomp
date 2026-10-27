/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern int cElevatorGOBJ_OutsideDoorsAreOpen(cElevatorGOBJ* lift);
extern int cElevatorGOBJ_InsideDoorsAreOpen(cElevatorGOBJ* lift);

/* Lift door predicate: cElevatorGOBJ_InsideDoorsAreOpen OR cElevatorGOBJ_OutsideDoorsAreOpen. */
int cElevatorGOBJ_DoorsAreOpen(cElevatorGOBJ* lift) {
    return cElevatorGOBJ_InsideDoorsAreOpen(lift) != 0 || cElevatorGOBJ_OutsideDoorsAreOpen(lift) != 0;
}
