/*
 * Matched functions (byte-identical with the retail executable).
 * cInventoryMsg script natives and script type registration.
 */

#include "types.h"
#include "backpack_types.h"

extern int D_004F7EF8;
extern int D_004F7F00;
extern int GObj_IdentityA(int who);
extern int* Message_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int baseType);

int Script_cInventoryMsg_Who(cItemMsg** msg) {
    return GObj_IdentityA((*msg)->who);
}

/* Volatile locals mirror the original stack temporaries. */
int Script_cInventoryMsg_Count(cItemMsg** msg) {
    volatile int count = (*msg)->count;
    return count;
}

int Script_cInventoryMsg_Taken(cItemMsg** msg) {
    volatile int taken = (*msg)->taken;
    return taken;
}

void ScriptType_cInventoryMsg_Init(void) {
    int* base = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F7F00, *base);
}

int cInventoryMsg_v03(void) {
    return D_004F7EF8;
}
