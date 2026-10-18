/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern int cElevatorGOBJ_FloorExtrasOpen(cElevatorGOBJ* lift);
extern int cElevatorGOBJ_LinksOpen(cElevatorGOBJ* lift);

/* Lift door predicate: cElevatorGOBJ_LinksOpen OR cElevatorGOBJ_FloorExtrasOpen. */
int cElevatorGOBJ_DoorsOpen(cElevatorGOBJ* lift) {
    return cElevatorGOBJ_LinksOpen(lift) != 0 || cElevatorGOBJ_FloorExtrasOpen(lift) != 0;
}
