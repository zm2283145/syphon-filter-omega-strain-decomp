/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int D_004F7CF8; /* cNIEventLight script type key */
extern int D_004F7D00; /* cNIEventLight script type id */
extern int D_004F7D20; /* cNINotice script type key */
extern char D_00555070[]; /* global script filter */
extern int ScriptFilter_Dispatch(void* filter, int a1, int a2);
extern int* cGOBJ_GetScriptTypeKeyPtr(void); /* address of the cGObj type key */
extern int ScriptType_AddAccepted(int type, int acceptedType);
extern void ScriptType_SetParent(int type, int parentType);

/* cNIEventLight derives from cGObj and accepts cNINotice messages. */
int ScriptType_cNIEventLight_Init(void) {
    int* parent = cGOBJ_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F7D00, *parent);
    return ScriptType_AddAccepted(D_004F7D00, D_004F7D20);
}

int cNIEventLight_v0B(void) {
    return D_004F7CF8;
}

int cNIEventLight_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
