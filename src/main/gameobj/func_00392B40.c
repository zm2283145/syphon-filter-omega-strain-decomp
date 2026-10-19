/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern void Actor_BaseLogicUpdate(cVUM_GOBJ* self);

void Actor_LogicUpdate(cVUM_GOBJ* self) {
    Actor_BaseLogicUpdate(self);
}
