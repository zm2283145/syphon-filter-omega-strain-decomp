#ifndef CHECKPOINT_TYPES_H
#define CHECKPOINT_TYPES_H

/*
 * Types for the checkpoint script class (cCheckpoint) and its messages
 * (cRespawnMsg, cNotifyCheckpointMsg, cAddCheckpointMsg).
 */

/* One script-native argument slot (4 bytes). */
typedef union CheckpointScriptArg {
    int i;
    float f;
    void* p;
    unsigned char u8;
} CheckpointScriptArg;

/*
 * Script type registration helpers:
 *  cGOBJ_GetScriptTypeKeyPtr returns the address of the cGObj script type key,
 *  Message_GetScriptTypeKeyPtr returns the address of the message base type key,
 *  ScriptType_SetParent(type, parent) records the parent type of a script type.
 */
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern int* Message_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int parentType);

/* Global script filter used by v0C dispatch slots. */
extern char D_00555070[];
extern int ScriptFilter_Dispatch(void* filter, int a1, int a2);

/* Script object handle -> object (identity in retail). */
extern int GObj_IdentityB(int handle);
extern int func_00175FA0(int handle);

#endif
