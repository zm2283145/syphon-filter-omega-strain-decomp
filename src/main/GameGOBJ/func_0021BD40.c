/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

void cSoundGOBJ_v0E(void) {
}

void cSoundGOBJ_v0F(void) {
}

int cElevatorGOBJ_v04(void) {
    return 1;
}

/* Set / clear the cGOBJ byte at +0x2C (1 after construction). */
void func_0021BD70(cGOBJ* self) {
    self->unk2C = 1;
}

void func_0021BD80(cGOBJ* self) {
    self->unk2C = 0;
}
