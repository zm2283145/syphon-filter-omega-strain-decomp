/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 * cGameGOBJ script type registration and accessors.
 */

#include "gobj_types.h"

extern int D_004F54D0;   /* cGameGOBJ script-type value */
extern int D_004F54D8;   /* cGameGOBJ script-type key */
extern int D_004F55D8;   /* cGOBJTriggerEventMsg script-type value */
extern char D_00555070[];
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern int ScriptType_AddAccepted(int type, int iface);
extern void ScriptType_SetParent(int type, int base);

/* Registers the cGameGOBJ script type under cGOBJ; accepts cGOBJTriggerEventMsg. */
int ScriptType_cGameGOBJ_Init(void) {
    int* base;

    base = cGOBJ_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F54D8, *base);
    return ScriptType_AddAccepted(D_004F54D8, D_004F55D8);
}

int cGameGOBJ_v0B(void) {
    return D_004F54D0;
}

int cGameGOBJ_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
