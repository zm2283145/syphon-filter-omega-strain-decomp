/*
 * Matched functions (byte-identical with the retail executable).
 * Script type registration for cCheckpoint and the checkpoint messages,
 * plus the SetPlayersCheckpoint script native.
 */

#include "types.h"
#include "Checkpoint_types.h"

/* Script type keys: each class has a key cell and a type id cell. */
extern int D_004F79A0; /* cAddCheckpointMsg key */
extern int D_004F79A8; /* cAddCheckpointMsg type id */
extern int D_004F79B0; /* cNotifyCheckpointMsg key */
extern int D_004F79B8; /* cNotifyCheckpointMsg type id */
extern int D_004F79C0; /* cRespawnMsg key */
extern int D_004F79C8; /* cRespawnMsg type id */
extern int D_004F79D0; /* cCheckpoint key */
extern int D_004F79D8; /* cCheckpoint type id */
extern int Global_SetPlayersCheckpoint(int player, int checkpoint);
extern int* Checkpoint_GetScriptTypeKeyPtr(void);
extern int* func_0022DDA0(void);
extern int* func_0022DE00(void);
extern int* func_0022DE60(void);

/* cCheckpoint derives from cGObj. */
void ScriptType_cCheckpoint_Init(void) {
    int* parent = cGOBJ_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F79D8, *parent);
}

int* Checkpoint_GetScriptTypeKeyPtr(void) {
    return &D_004F79D0;
}

int cCheckpoint_v0B(void) {
    return *Checkpoint_GetScriptTypeKeyPtr();
}

int cCheckpoint_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}

/* cRespawnMsg derives from the message base type. */
void ScriptType_cRespawnMsg_Init(void) {
    int* parent = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F79C8, *parent);
}

int* func_0022DDA0(void) {
    return &D_004F79C0;
}

int cRespawnMsg_v03(void) {
    return *func_0022DDA0();
}

void ScriptType_cNotifyCheckpointMsg_Init(void) {
    int* parent = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F79B8, *parent);
}

int* func_0022DE00(void) {
    return &D_004F79B0;
}

int cNotifyCheckpointMsg_v03(void) {
    return *func_0022DE00();
}

void ScriptType_cAddCheckpointMsg_Init(void) {
    int* parent = Message_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F79A8, *parent);
}

int* func_0022DE60(void) {
    return &D_004F79A0;
}

int cAddCheckpointMsg_v03(void) {
    return *func_0022DE60();
}

/* SetPlayersCheckpoint(player, checkpoint) */
int Script_SetPlayersCheckpoint(CheckpointScriptArg* args) {
    volatile int checkpoint = args[1].i; /* original stack temporary */
    int player = GObj_IdentityB(args[0].i);
    Global_SetPlayersCheckpoint(player, checkpoint);
    return 0;
}
