/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 * cSoundGOBJ script type and cInteractGOBJ script natives.
 */

#include "gobj_types.h"

extern int D_004F5680;   /* cSoundGOBJ script-type value */
extern int D_004F5688;   /* cSoundGOBJ script-type key */
extern char D_00555070[];
extern int GObj_IdentityA(int obj);
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int base);

/* Registers the cSoundGOBJ script type under cGOBJ. */
void ScriptType_cSoundGOBJ_Init(void) {
    int* base;

    base = cGOBJ_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F5688, *base);
}

int cSoundGOBJ_v0B(void) {
    return D_004F5680;
}

int cSoundGOBJ_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}

/* GetLocationObj(interact): returns the object stored at +0xA8. */
int Script_cInteractGOBJ_GetLocationObj(ScriptArg* args) {
    return GObj_IdentityA(*(int*)((char*)args[0].p + 0xA8));
}
