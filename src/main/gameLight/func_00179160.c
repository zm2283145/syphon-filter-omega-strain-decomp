/*
 * Matched functions (byte-identical with the retail executable).
 * cGameLight script type registration and class helpers.
 */

#include "types.h"

extern int D_004EE898;   /* cGameLight class type id */
extern int D_004EE8A0;   /* cGameLight script type */
extern char D_00555070[];
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int parentType);

/* Registers the cGameLight script type under its parent type. */
void ScriptType_cGameLight_Init(void) {
    int* parent = cGOBJ_GetScriptTypeKeyPtr();

    ScriptType_SetParent(D_004EE8A0, *parent);
}

int cGameLight_v0B(void) {
    return D_004EE898;
}

int cGameLight_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
