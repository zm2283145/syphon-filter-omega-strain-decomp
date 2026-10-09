/*
 * Matched functions (byte-identical with the retail executable).
 * cGameDirectionalLight script type registration and class helpers.
 */

#include "types.h"

extern int D_004EE8D8;   /* cGameDirectionalLight class type id */
extern int D_004EE8E0;   /* cGameDirectionalLight script type */
extern int D_004EE898;   /* cGameLight class type id (parent) */
extern char D_00555070[];
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern void ScriptType_SetParent(int type, int parentType);

/* Registers the cGameDirectionalLight script type under its parent type. */
void ScriptType_cGameDirectionalLight_Init(void) {
    ScriptType_SetParent(D_004EE8E0, D_004EE898);
}

int cGameDirectionalLight_v0B(void) {
    return D_004EE8D8;
}

int cGameDirectionalLight_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
