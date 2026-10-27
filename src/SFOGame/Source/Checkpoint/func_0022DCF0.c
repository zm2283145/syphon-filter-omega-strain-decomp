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
extern int* cCheckpoint_SOBJ_getClassId(void);
extern int* cRespawnMsg_SOBJ_getClassId(void);
extern int* cNotifyCheckpointMsg_SOBJ_getClassId(void);
extern int* cAddCheckpointMsg_SOBJ_getClassId(void);

/* cCheckpoint derives from cGObj. */
void cCheckpoint_SOBJ_init(void) {
    int* parent = cGOBJ_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F79D8, *parent);
}

int* cCheckpoint_SOBJ_getClassId(void) {
    return &D_004F79D0;
}

int cCheckpoint_getSOBJClassId(void) {
    return *cCheckpoint_SOBJ_getClassId();
}

int cCheckpoint_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}

/* cRespawnMsg derives from the message base type. */
void cRespawnMsg_SOBJ_init(void) {
    int* parent = cMessage_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F79C8, *parent);
}

int* cRespawnMsg_SOBJ_getClassId(void) {
    return &D_004F79C0;
}

int cRespawnMsg_getSOBJClassId(void) {
    return *cRespawnMsg_SOBJ_getClassId();
}

void cNotifyCheckpointMsg_SOBJ_init(void) {
    int* parent = cMessage_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F79B8, *parent);
}

int* cNotifyCheckpointMsg_SOBJ_getClassId(void) {
    return &D_004F79B0;
}

int cNotifyCheckpointMsg_getSOBJClassId(void) {
    return *cNotifyCheckpointMsg_SOBJ_getClassId();
}

void cAddCheckpointMsg_SOBJ_init(void) {
    int* parent = cMessage_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F79A8, *parent);
}

int* cAddCheckpointMsg_SOBJ_getClassId(void) {
    return &D_004F79A0;
}

int cAddCheckpointMsg_getSOBJClassId(void) {
    return *cAddCheckpointMsg_SOBJ_getClassId();
}

/* SetPlayersCheckpoint(player, checkpoint) */
int Script_SetPlayersCheckpoint(CheckpointScriptArg* args) {
    volatile int checkpoint = args[1].i; /* original stack temporary */
    int player = cGOBJ_SOBJ_convert(args[0].i);
    Global_SetPlayersCheckpoint(player, checkpoint);
    return 0;
}
