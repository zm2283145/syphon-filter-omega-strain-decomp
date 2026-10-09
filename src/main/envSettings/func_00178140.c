/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int D_004EE860;      /* cEnvSettings script type key */
extern int D_004EE868;      /* cEnvSettings script type id */
extern char D_00555070[];   /* global script filter */
extern int ScriptFilter_Dispatch(void* filter, int a1, int a2);
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int parentType);

/* cEnvSettings derives from cGObj. */
void ScriptType_cEnvSettings_Init(void) {
    ScriptType_SetParent(D_004EE868, *cGOBJ_GetScriptTypeKeyPtr());
}

int cEnvSettings_v0B(void) {
    return D_004EE860;
}

int cEnvSettings_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
