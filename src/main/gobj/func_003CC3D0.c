/*
 * Matched functions from gobj.cc (byte-identical with the retail executable).
 * SubScript script type registration and script-type accessors.
 */

#include "gobj_types.h"

extern int D_005436B8;   /* cGOBJ script-type key */
extern int D_00543720;   /* SubScript script-type value */
extern int D_00543728;   /* SubScript script-type key */
extern char D_00555070[];
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern void ScriptType_SetParent(int type, int base);

/* Registers the SubScript script type under cGOBJ. */
void ScriptType_SubScript_Init(void) {
    ScriptType_SetParent(D_00543728, D_005436B8);
}

int SubScript_v0B(void) {
    return D_00543720;
}

int SubScript_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
