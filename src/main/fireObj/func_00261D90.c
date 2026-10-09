/*
 * Matched functions (byte-identical with the retail executable).
 * cFireObj script type registration and class helpers.
 */

#include "types.h"

extern int D_004F8310;   /* cFireObj class type id */
extern int D_004F8318;   /* cFireObj script type */
extern char D_00555070[];
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int parentType);

/* Registers the cFireObj script type under its parent type. */
void ScriptType_cFireObj_Init(void) {
    int* parent = cGOBJ_GetScriptTypeKeyPtr();

    ScriptType_SetParent(D_004F8318, *parent);
}

int cFireObj_v0B(void) {
    return D_004F8310;
}

int cFireObj_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
