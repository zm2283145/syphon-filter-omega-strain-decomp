/*
 * Matched functions from gobj.cc (byte-identical with the retail executable).
 * cGOBJ darkness script natives.
 */

#include "gobj_types.h"

/* GetDarkness(gobj); the volatile mirrors the original stack temporary. */
int Script_cGOBJ_GetDarkness(ScriptArg* args) {
    volatile int darkness = ((cGOBJ*)args[0].p)->darkness;
    return darkness;
}

/* SetDarkness(gobj, value). */
int Script_cGOBJ_SetDarkness(ScriptArg* args) {
    volatile int darkness = args[1].i;
    ((cGOBJ*)args[0].p)->darkness = darkness;
    return 0;
}
