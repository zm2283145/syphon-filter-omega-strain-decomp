/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 * Pathed object (mover) script natives.
 */

#include "gobj_types.h"

extern int PathObj_ResetAndTrigger(Mover* obj);

/* GetPos(mover): current path index (first word of the path state at +0xD0). */
int Script_Mover_GetPos(Args* a) {
    volatile int pos = a->obj->path[0];
    return pos;
}

int PathObj_ScriptResetAndTrigger(Args* a) {
    PathObj_ResetAndTrigger(a->obj);
    return 0;
}
