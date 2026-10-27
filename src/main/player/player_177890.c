/*
 * main/player: range (2 files, 00177890-001778F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "types.h"

/* merge_units: begin func_00177890 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cMoveMsg_Template_1_dtor, D_004D9DA0, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00177890 */

/* merge_units: begin func_001778F0 */
#pragma push /* merge_units */
extern void Actor_VirtualNop1753D0();
extern void Actor_VirtualNop1753E0();
extern void cGameGobjController_SetGobj();
extern void cGameGobjController_GetVelocity();
extern void cGameGobjController_Enemy_cGOBJP();
extern void cGameGobjController_Enemy_int();
extern void cGameGobjController_UpdateToHitProbability();
extern void cPlayer_HandleMessage();
extern void Player_IsPlayer();
extern void cPlayer_NextFrame();
extern void cPlayer_getSOBJClassId();
extern void cPlayer_ScriptHandleMessage();
extern void cPlayer_CleanUpAfterTeleportationOfGobj();
extern void cPlayer_GetBulletDir();
extern void cPlayer_Team();
extern void cPlayer_NoticeDeath();
extern void cPlayer_v1E();
extern void cPlayer_NoticeThreat_cGobjControllerP_int_float_int();
extern void cSystem_ScriptGetRealObj();
extern void cSystem_SendCreated();
extern void cSystem_NetActivate();
extern void cSystem_NetDeactivate();
extern void cSystem_NetEnable();
extern void cSystem_NetDisable();
extern void cSystem_IsDeliverable();
extern void cSystem_IsNetworked();
extern void cGobjController_IsNPC();
extern void cGobjController_DetermineDeathType_int();
extern void cGobjController_IsNetNPC();
extern void cGobjController_GetCopyMsg();
extern void cGobjController_NoticeEnvironmentalDanger();
extern void func_0016F9E0();
extern void PlayerComp_OnHitNop();
extern void PlayerComp_GetDeathCode();
extern void func_0016FA20();
extern void func_001753F0();
extern void cGobjController_WantsToBeActive();
extern void cGobjController_ScriptGetObjectId();
extern void * const D_004D9CF0[];
extern void cLList_cSafePtr_cGOBJ_dtor(void* p, int f);
extern void cModeSwitch_WithHistory_2_dtor(void* p, int f);
extern void cModeSwitch_WithHistory_12_dtor(void* p, int f);
extern void cGameGobjController_dtor(void* self, int flag);
#if 0 /* merge_units */
extern void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

typedef struct { void* vt; } S_78F0;
S_78F0* cPlayer_dtor(S_78F0* self, short flag)
{
    if (self) {
        self->vt = ((char*)D_004D9CF0);
        if ((char*)self + 0x50) {
            cLList_cSafePtr_cGOBJ_dtor((char*)self + 0x13C, -1);
            cModeSwitch_WithHistory_2_dtor((char*)self + 0x98, -1);
            cModeSwitch_WithHistory_12_dtor((char*)self + 0x80, -1);
        }
        cGameGobjController_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D9CF0[44] = { (void*)0x0, (void*)0x0, (void*)cPlayer_dtor, (void*)cPlayer_HandleMessage, (void*)cGobjController_ScriptGetObjectId, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cPlayer_getSOBJClassId, (void*)cPlayer_ScriptHandleMessage, (void*)func_0016F9E0, (void*)cPlayer_NextFrame, (void*)cGobjController_WantsToBeActive, (void*)Actor_VirtualNop1753D0, (void*)Actor_VirtualNop1753E0, (void*)cPlayer_CleanUpAfterTeleportationOfGobj, (void*)Player_IsPlayer, (void*)cGobjController_IsNPC, (void*)cGobjController_IsNetNPC, (void*)cGameGobjController_UpdateToHitProbability, (void*)cPlayer_GetBulletDir, (void*)cPlayer_Team, (void*)cGameGobjController_Enemy_int, (void*)cGameGobjController_Enemy_cGOBJP, (void*)cGameGobjController_GetVelocity, (void*)PlayerComp_OnHitNop, (void*)cPlayer_NoticeDeath, (void*)cPlayer_v1E, (void*)PlayerComp_GetDeathCode, (void*)cGobjController_DetermineDeathType_int, (void*)cGameGobjController_SetGobj, (void*)func_0016FA20, (void*)cGobjController_GetCopyMsg, (void*)func_001753F0, (void*)cGobjController_NoticeEnvironmentalDanger, (void*)cPlayer_NoticeThreat_cGobjControllerP_int_float_int, (void*)0x0, (void*)0x0, (void*)0x0 };
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001778F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001778F0 */
