/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern void cGOBJ_NextFrame(cVUM_GOBJ* self);

void cSKM_GOBJ_NextFrame(cVUM_GOBJ* self) {
    cGOBJ_NextFrame(self);
}
