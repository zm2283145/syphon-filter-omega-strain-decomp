/*
 * Matched functions (byte-identical with the retail executable).
 * cEnableMsg script type registration and type-id slot.
 */

#include "types.h"

extern int D_0055D4C8;
extern int D_0055D4D0;
extern int* Message_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int baseType);

void ScriptType_cEnableMsg_Init(void) {
    int* base = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_0055D4D0, *base);
}

int cEnableMsg_v03(void) {
    return D_0055D4C8;
}
