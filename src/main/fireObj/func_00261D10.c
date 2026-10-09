/*
 * Matched functions (byte-identical with the retail executable).
 * cFireObj on/off virtuals.
 */

#include "types.h"
#include "fireObj_types.h"

void cFireObj_v08(cFireObj* self) {
    self->lit = 1;
}

void cFireObj_v09(cFireObj* self) {
    self->lit = 0;
}
