/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern int D_004EE700;   /* cHotboxMsg type id */
extern int D_004EE738;   /* cHotbox class type id */
extern int D_004EE740;   /* cHotbox script type */
extern char D_00555070[];
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern int ScriptType_AddAccepted(int type, int messageType);
extern void ScriptType_SetParent(int type, int parentType);

/* Registers the cHotbox script type under its parent and adds cHotboxMsg to it. */
int ScriptType_cHotbox_Init(void) {
    int* parent = cGOBJ_GetScriptTypeKeyPtr();

    ScriptType_SetParent(D_004EE740, *parent);
    return ScriptType_AddAccepted(D_004EE740, D_004EE700);
}

void* func_0016FE30(void* self) {
    return self;
}

int* func_0016FE40(void) {
    return &D_004EE738;
}

int func_0016FE50(void) {
    return D_004EE738;
}

int func_0016FE60(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
