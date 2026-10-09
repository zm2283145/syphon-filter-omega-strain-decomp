/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern int func_00213FE0(cElevatorGOBJ* lift);
extern int func_00214080(cElevatorGOBJ* lift);

/* Lift door predicate: func_00214080 OR func_00213FE0. */
int func_00213FA0(cElevatorGOBJ* lift) {
    return func_00214080(lift) != 0 || func_00213FE0(lift) != 0;
}
