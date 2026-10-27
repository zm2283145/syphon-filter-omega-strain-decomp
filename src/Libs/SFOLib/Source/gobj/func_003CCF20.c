/*
 * Matched functions from gobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

/* Sets cGOBJ +0x30 (initialized to -1 by the constructor). */
void cGobjController_SetGobj(cGOBJ* self, int value) {
    self->unk30 = value;
}
