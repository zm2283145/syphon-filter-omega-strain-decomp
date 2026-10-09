/*
 * Matched functions (byte-identical with the retail executable).
 * cCrateInteractMsg script natives and script type registration.
 */

#include "types.h"
#include "backpack_types.h"

extern int D_004F7EB8;
extern int D_004F7EC0;
extern int GObj_IdentityA(int who);
extern int* Message_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int baseType);

int Script_cCrateInteractMsg_Who(cItemMsg** msg) {
    return GObj_IdentityA((*msg)->who);
}

/* Volatile locals mirror the original stack temporaries. */
int Script_cCrateInteractMsg_Taken(cItemMsg** msg) {
    volatile int taken = (*msg)->taken;
    return taken;
}

int Script_cCrateInteractMsg_Given(cItemMsg** msg) {
    volatile int given = (*msg)->count;
    return given;
}

void ScriptType_cCrateInteractMsg_Init(void) {
    int* base = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F7EC0, *base);
}

int cCrateInteractMsg_v03(void) {
    return D_004F7EB8;
}
