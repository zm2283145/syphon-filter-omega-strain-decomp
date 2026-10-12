#include "types.h"
extern char* D_004F7930;
extern char* D_004F7938;
extern char* D_004F7940;
extern char* D_004F7980;
extern int D_004F7968, D_004F7988, D_004F7990, D_004F7998, D_004F79A0, D_004F79A8, D_004F79B0, D_004F79B8, D_004F79C0, D_004F79C8, D_004F79D0, D_004F79D8;
extern char D_004A66C0[], D_004A66E0[], D_004A6700[], D_004A6710[], D_004A6728[], D_004A6730[], D_004A6738[], D_004A6750[];
extern char D_004A6770[], D_004A6790[], D_004A67A8[], D_004A67B8[];
extern char D_00493880[], D_00493898[], D_004EE538[], D_004F7970[];
extern char Script_SetCheckpointFont[], Script_ReSpawn[], Script_SetCheckpoint[], Script_SetPlayersCheckpoint[];
extern char ScriptType_cAddCheckpointMsg_Init[], ScriptType_cNotifyCheckpointMsg_Init[], ScriptType_cRespawnMsg_Init[], ScriptType_cCheckpoint_Init[];
extern char func_00144930[];
extern int func_003D8740(void* fn, void* name, void* desc, int n, ...);
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
    D_004F7930 = D_004A66C0;
    D_004F7938 = D_004A66E0;
    D_004F7940 = D_004A6700;
    D_004F7968 = func_003D8740(Script_SetCheckpointFont, D_00493880, D_004A6710, 1, D_004EE538);
    D_004F7980 = D_004A6728;
    __register_global_object(&D_004F7980, func_00144930, D_004F7970);
    D_004F7988 = func_003D8740(Script_ReSpawn, D_00493880, D_004A6730, 1, func_00175FB0());
    D_004F7990 = func_003D8740(Script_SetCheckpoint, D_00493880, D_004A6738, 3, func_00175FB0(), cGOBJ_GetScriptTypeKeyPtr(), D_00493898);
    D_004F7998 = func_003D8740(Script_SetPlayersCheckpoint, D_00493880, D_004A6750, 2, cGOBJ_GetScriptTypeKeyPtr(), D_00493898);
    D_004F79A0 = Script_RegisterType(D_004A6770, ScriptType_cAddCheckpointMsg_Init, 1, 0);
    D_004F79A8 = *func_0022DE60();
    D_004F79B0 = Script_RegisterType(D_004A6790, ScriptType_cNotifyCheckpointMsg_Init, 1, 0);
    D_004F79B8 = *func_0022DE00();
    D_004F79C0 = Script_RegisterType(D_004A67A8, ScriptType_cRespawnMsg_Init, 1, 0);
    D_004F79C8 = *func_0022DDA0();
    D_004F79D0 = Script_RegisterType(D_004A67B8, ScriptType_cCheckpoint_Init, 0, 1);
    D_004F79D8 = *Checkpoint_GetScriptTypeKeyPtr();
}