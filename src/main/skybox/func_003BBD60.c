/*
 * Matched functions (byte-identical with the retail executable).
 * cSKYBOX_GOBJ script type registration and class helpers.
 */

#include "types.h"

extern int D_00542C98;   /* cSKYBOX_GOBJ class type id */
extern int D_00542CA0;   /* cSKYBOX_GOBJ script type */
extern char D_00555070[];
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int parentType);

/* Registers the cSKYBOX_GOBJ script type under its parent type. */
void ScriptType_cSKYBOX_GOBJ_Init(void) {
    int* parent = cGOBJ_GetScriptTypeKeyPtr();

    ScriptType_SetParent(D_00542CA0, *parent);
}

int func_003BBD90(void) {
    return D_00542C98;
}

int func_003BBDA0(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
