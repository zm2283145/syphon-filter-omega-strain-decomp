/*
 * Matched functions (byte-identical with the retail executable).
 * Script type registration for cPARTICLE_GOBJ (code follows the man.cc range).
 */

#include "loose03_types.h"

extern int D_0053B500;
extern int D_0053B508;          /* cPARTICLE_GOBJ script type */
extern char D_00555070[];       /* script filter context */
extern int ScriptFilter_Dispatch(void* ctx, int a0, int a1);
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int parent);

void ScriptType_cPARTICLE_GOBJ_Init(void) {
    ScriptType_SetParent(D_0053B508, *cGOBJ_GetScriptTypeKeyPtr());
}

int func_003926A0(void) {
    return D_0053B500;
}

int func_003926B0(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
