/*
 * Matched functions (byte-identical with the retail executable).
 * cObjective virtuals that clear/set the active byte (+0x25).
 */

#include "types.h"
#include "Objective_types.h"

void cObjective_v07(cObjective* self) {
    self->active = 0;
}

void cObjective_v06(cObjective* self) {
    self->active = 1;
}
