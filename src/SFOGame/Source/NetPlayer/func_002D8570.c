#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void Actor_VirtualNop1753D0();
extern "C" void Actor_VirtualNop1753E0();
extern "C" void cGameGobjController_SetGobj();
extern "C" void cGameGobjController_GetVelocity();
extern "C" void cGameGobjController_Enemy_cGOBJP();
extern "C" void cGameGobjController_Enemy_int();
extern "C" void cGameGobjController_UpdateToHitProbability();
extern "C" void cSystem_ScriptGetRealObj();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_NetActivate();
extern "C" void cSystem_NetDeactivate();
extern "C" void cSystem_NetEnable();
extern "C" void cSystem_NetDisable();
extern "C" void cSystem_IsDeliverable();
extern "C" void cSystem_IsNetworked();
extern "C" void cGobjController_IsNPC();
extern "C" void cGobjController_IsNetNPC();
extern "C" void func_0015B820();
extern "C" void cGobjController_CleanUpAfterTeleportationOfGobj();
extern "C" void cGobjController_GetCopyMsg();
extern "C" void cGobjController_NoticeEnvironmentalDanger();
extern "C" void func_0016F9E0();
extern "C" void PlayerComp_OnHitNop();
extern "C" void PlayerComp_GetDeathCode();
extern "C" void func_0016FA20();
extern "C" void func_001753F0();
extern "C" void cGameGobjController_v0B();
extern "C" void cGameGobjController_ScriptHandleMessage();
extern "C" void cNetPlayer_GetControllerType();
extern "C" void cNetPlayer_IsPlayer();
extern "C" void cNetPlayer_Team();
extern "C" void cNetPlayer_NoticeDeath();
extern "C" void func_002D7E50();
extern "C" void cNetPlayer_HandleMessage();
extern "C" void cNetPlayer_NextFrame();
extern "C" void cGobjController_WantsToBeActive();
extern "C" void cGobjController_ScriptGetObjectId();
extern void * const D_004DE530[];
void* cGameGobjController_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* cNetPlayer_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DE530);
        cGameGobjController_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DE530[40] = { (void*)0x0, (void*)0x0, (void*)cNetPlayer_dtor, (void*)cNetPlayer_HandleMessage, (void*)cGobjController_ScriptGetObjectId, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGameGobjController_v0B, (void*)cGameGobjController_ScriptHandleMessage, (void*)func_0016F9E0, (void*)cNetPlayer_NextFrame, (void*)cGobjController_WantsToBeActive, (void*)Actor_VirtualNop1753D0, (void*)Actor_VirtualNop1753E0, (void*)func_0015B820, (void*)cNetPlayer_IsPlayer, (void*)cGobjController_IsNPC, (void*)cGobjController_IsNetNPC, (void*)cGameGobjController_UpdateToHitProbability, (void*)func_002D7E50, (void*)cNetPlayer_Team, (void*)cGameGobjController_Enemy_int, (void*)cGameGobjController_Enemy_cGOBJP, (void*)cGameGobjController_GetVelocity, (void*)PlayerComp_OnHitNop, (void*)cNetPlayer_NoticeDeath, (void*)cGobjController_CleanUpAfterTeleportationOfGobj, (void*)PlayerComp_GetDeathCode, (void*)cNetPlayer_GetControllerType, (void*)cGameGobjController_SetGobj, (void*)func_0016FA20, (void*)cGobjController_GetCopyMsg, (void*)func_001753F0, (void*)cGobjController_NoticeEnvironmentalDanger };
