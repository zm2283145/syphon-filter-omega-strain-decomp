/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

/* Clears all 14 slots (handle at 0x00 is left untouched). */
void func_00272170(SlotTable14* self) {
    self->slots[0] = 0;
    self->slots[1] = 0;
    self->slots[2] = 0;
    self->slots[3] = 0;
    self->slots[4] = 0;
    self->slots[5] = 0;
    self->slots[6] = 0;
    self->slots[7] = 0;
    self->slots[8] = 0;
    self->slots[9] = 0;
    self->slots[10] = 0;
    self->slots[11] = 0;
    self->slots[12] = 0;
    self->slots[13] = 0;
}
