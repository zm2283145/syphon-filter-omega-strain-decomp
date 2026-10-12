#include "types.h"
extern char* D_004F7930;
extern char* D_004F7938;
extern char* D_004F7940;
extern char* D_004F7980;
extern int D_004F7968, D_004F7988, D_004F7990, D_004F7998, D_004F79A0, D_004F79A8, D_004F79B0, D_004F79B8, D_004F79C0, D_004F79C8, D_004F79D0, D_004F79D8;
extern char D_00493880[], D_00493898[], D_004EE538[], D_004F7970[];
extern char Script_SetCheckpointFont[], Script_ReSpawn[], Script_SetCheckpoint[], Script_SetPlayersCheckpoint[];
extern char ScriptType_cAddCheckpointMsg_Init[], ScriptType_cNotifyCheckpointMsg_Init[], ScriptType_cRespawnMsg_Init[], ScriptType_cCheckpoint_Init[];
extern char func_00144930[];
extern int Script_RegisterNative_2(void* fn, void* name, void* desc, int n, ...);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern int func_00175FB0(void);
extern int cGOBJ_GetScriptTypeKeyPtr(void);
extern int Script_RegisterType(void* name, void* init, int a, int b);
extern int* func_0022DE60(void);
extern int* func_0022DE00(void);
extern int* func_0022DDA0(void);
extern int* Checkpoint_GetScriptTypeKeyPtr(void);
void func_004CED30(void)
{
    D_004F7930 = "MSGGAME_ADD_CHECKPOINT";
    D_004F7938 = "MSGGAME_NOTIFY_CHECKPOINT";
    D_004F7940 = "MSGGAME_RESPAWN";
    D_004F7968 = Script_RegisterNative_2(Script_SetCheckpointFont, D_00493880, "SetCheckpointFont", 1, D_004EE538);
    D_004F7980 = "CHKP";
    __register_global_object(&D_004F7980, func_00144930, D_004F7970);
    D_004F7988 = Script_RegisterNative_2(Script_ReSpawn, D_00493880, "ReSpawn", 1, func_00175FB0());
    D_004F7990 = Script_RegisterNative_2(Script_SetCheckpoint, D_00493880, "SetCheckpoint", 3, func_00175FB0(), cGOBJ_GetScriptTypeKeyPtr(), D_00493898);
    D_004F7998 = Script_RegisterNative_2(Script_SetPlayersCheckpoint, D_00493880, "SetPlayersCheckpoint", 2, cGOBJ_GetScriptTypeKeyPtr(), D_00493898);
    D_004F79A0 = Script_RegisterType("cAddCheckpointMsg", ScriptType_cAddCheckpointMsg_Init, 1, 0);
    D_004F79A8 = *func_0022DE60();
    D_004F79B0 = Script_RegisterType("cNotifyCheckpointMsg", ScriptType_cNotifyCheckpointMsg_Init, 1, 0);
    D_004F79B8 = *func_0022DE00();
    D_004F79C0 = Script_RegisterType("cRespawnMsg", ScriptType_cRespawnMsg_Init, 1, 0);
    D_004F79C8 = *func_0022DDA0();
    D_004F79D0 = Script_RegisterType("cCheckpoint", ScriptType_cCheckpoint_Init, 0, 1);
    D_004F79D8 = *Checkpoint_GetScriptTypeKeyPtr();
}