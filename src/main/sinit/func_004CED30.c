#include "types.h"
extern char* D_004F7930;
extern char* g_NotifyCheckpointMsgClass;
extern char* D_004F7940;
extern char* D_004F7980;
extern int D_004F7968, D_004F7988, D_004F7990, D_004F7998, D_004F79A0, D_004F79A8, D_004F79B0, D_004F79B8, D_004F79C0, D_004F79C8, D_004F79D0, D_004F79D8;
extern char D_00493880[], D_00493898[], D_004EE538[], D_004F7970[];
extern char Script_SetCheckpointFont[], Script_ReSpawn[], Script_SetCheckpoint[], Script_SetPlayersCheckpoint[];
extern char cAddCheckpointMsg_SOBJ_init[], cNotifyCheckpointMsg_SOBJ_init[], cRespawnMsg_SOBJ_init[], cCheckpoint_SOBJ_init[];
extern char cSubclassId_dtor[];
extern int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(void* fn, void* name, void* desc, int n, ...);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern int cPlayer_SOBJ_getClassId(void);
extern int cGOBJ_SOBJ_getClassId(void);
extern int cScriptBase_addClass(void* name, void* init, int a, int b);
extern int* cAddCheckpointMsg_SOBJ_getClassId(void);
extern int* cNotifyCheckpointMsg_SOBJ_getClassId(void);
extern int* cRespawnMsg_SOBJ_getClassId(void);
extern int* cCheckpoint_SOBJ_getClassId(void);
void StaticInit_Checkpoint(void)
{
    D_004F7930 = "MSGGAME_ADD_CHECKPOINT";
    g_NotifyCheckpointMsgClass = "MSGGAME_NOTIFY_CHECKPOINT";
    D_004F7940 = "MSGGAME_RESPAWN";
    D_004F7968 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetCheckpointFont, D_00493880, "SetCheckpointFont", 1, D_004EE538);
    D_004F7980 = "CHKP";
    __register_global_object(&D_004F7980, cSubclassId_dtor, D_004F7970);
    D_004F7988 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_ReSpawn, D_00493880, "ReSpawn", 1, cPlayer_SOBJ_getClassId());
    D_004F7990 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetCheckpoint, D_00493880, "SetCheckpoint", 3, cPlayer_SOBJ_getClassId(), cGOBJ_SOBJ_getClassId(), D_00493898);
    D_004F7998 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_SetPlayersCheckpoint, D_00493880, "SetPlayersCheckpoint", 2, cGOBJ_SOBJ_getClassId(), D_00493898);
    D_004F79A0 = cScriptBase_addClass("cAddCheckpointMsg", cAddCheckpointMsg_SOBJ_init, 1, 0);
    D_004F79A8 = *cAddCheckpointMsg_SOBJ_getClassId();
    D_004F79B0 = cScriptBase_addClass("cNotifyCheckpointMsg", cNotifyCheckpointMsg_SOBJ_init, 1, 0);
    D_004F79B8 = *cNotifyCheckpointMsg_SOBJ_getClassId();
    D_004F79C0 = cScriptBase_addClass("cRespawnMsg", cRespawnMsg_SOBJ_init, 1, 0);
    D_004F79C8 = *cRespawnMsg_SOBJ_getClassId();
    D_004F79D0 = cScriptBase_addClass("cCheckpoint", cCheckpoint_SOBJ_init, 0, 1);
    D_004F79D8 = *cCheckpoint_SOBJ_getClassId();
}