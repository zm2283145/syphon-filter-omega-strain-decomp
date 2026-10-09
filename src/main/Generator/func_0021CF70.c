/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int D_004F56D8;      /* NPC message base script type key */
extern int D_004F56F0;      /* cSpawnedNPCMsg type key */
extern int D_004F56F8;      /* cSpawnedNPCMsg script type id */
extern int D_004F5700;      /* cDespawnedNPCMsg type key */
extern int D_004F5708;      /* cDespawnedNPCMsg script type id */
extern int D_004F5710;      /* cGenerator script type key */
extern int D_004F5718;      /* cGenerator script type id */
extern char D_00555070[];   /* global script filter */
extern int ScriptFilter_Dispatch(void* filter, int a1, int a2);
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern int ScriptType_AddAccepted(int type, int iface);
extern void ScriptType_SetParent(int type, int parentType);

/* cGenerator derives from cGObj and accepts the spawned/despawned messages. */
int ScriptType_cGenerator_Init(void) {
    ScriptType_SetParent(D_004F5718, *cGOBJ_GetScriptTypeKeyPtr());
    ScriptType_AddAccepted(D_004F5718, D_004F56F0);
    return ScriptType_AddAccepted(D_004F5718, D_004F5700);
}

int cGenerator_v0B(void) {
    return D_004F5710;
}

int cGenerator_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}

void ScriptType_cDespawnedNPCMsg_Init(void) {
    ScriptType_SetParent(D_004F5708, D_004F56D8);
}

int cDespawnedNPCMsg_v03(void) {
    return D_004F5700;
}

void ScriptType_cSpawnedNPCMsg_Init(void) {
    ScriptType_SetParent(D_004F56F8, D_004F56D8);
}

int cSpawnedNPCMsg_v03(void) {
    return D_004F56F0;
}
