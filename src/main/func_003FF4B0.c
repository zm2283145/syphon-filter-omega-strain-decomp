/*
 * Matched functions (byte-identical with the retail executable).
 * cDisableMsg script type registration and type-id slot.
 */

#include "types.h"

extern int D_0055D4A8;
extern int D_0055D4B0;
extern int* Message_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int baseType);

void ScriptType_cDisableMsg_Init(void) {
    int* base = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_0055D4B0, *base);
}

int cDisableMsg_v03(void) {
    return D_0055D4A8;
}
