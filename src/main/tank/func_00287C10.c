/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "types.h"
#include "tank_types.h"

extern int D_00506250;

TankLink* func_00287C10(TankLink* self, int unk00, char* source) {
    self->source = source;
    self->unk00 = unk00;
    self->unk24 = *(float*)(self->source + 0x144);
    self->unk28 = 0;
    return self;
}

/* Message type id for cNetCreateTankMsg. */
int cNetCreateTankMsg_v05(void) {
    return D_00506250;
}
