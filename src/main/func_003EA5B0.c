#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void Actor_VirtualNop1753D0();
extern "C" void Actor_VirtualNop1753E0();
extern "C" void cSystem_HandleMessage();
extern "C" void cSystem_ScriptGetRealObj();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_NetActivate();
extern "C" void cSystem_NetDeactivate();
extern "C" void cSystem_NetEnable();
extern "C" void cSystem_NetDisable();
extern "C" void cSystem_IsDeliverable();
extern "C" void cGobjController_IsPlayer();
extern "C" void cSystem_IsNetworked();
extern "C" void cGobjController_IsNPC();
extern "C" void cGobjController_DetermineDeathType_int();
extern "C" void cGobjController_IsNetNPC();
extern "C" void cGobjController_GetVelocity();
extern "C" void func_0015B820();
extern "C" void cGobjController_CleanUpAfterTeleportationOfGobj();
extern "C" void cGobjController_GetCopyMsg();
extern "C" void cGobjController_NoticeEnvironmentalDanger();
extern "C" void func_0016F9E0();
extern "C" void PlayerComp_OnHitNop();
extern "C" void func_0016FA00();
extern "C" void PlayerComp_GetDeathCode();
extern "C" void func_0016FA20();
extern "C" void func_001753F0();
extern "C" void cGobjController_Team();
extern "C" void cSystem_getSOBJClassId();
extern "C" void cSystem_ScriptHandleMessage();
extern "C" void cGobjController_Enemy_int();
extern "C" void cGobjController_SetGobj();
extern "C" void cGobjController_Enemy_cGOBJP();
extern "C" void cGobjController_WantsToBeActive();
extern "C" void cGobjController_ScriptGetObjectId();
extern void * const D_004E06C0[];
void cSystem_dtor(void* p, short f);
void operator_delete(void* p);
}
struct L3EA5B0 { char pad[0x58]; int x58; };
struct O3EA5B0 { void* vt; char pad[0x2C]; L3EA5B0* link; };
extern "C" O3EA5B0* cGobjController_dtor(O3EA5B0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004E06C0);
        {
            L3EA5B0* l = self->link;
            if (l) {
                l->x58 = 0;
                self->link = 0;
            }
        }
        cSystem_dtor(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}
void * const D_004E06C0[40] = { (void*)0x0, (void*)0x0, (void*)cGobjController_dtor, (void*)cSystem_HandleMessage, (void*)cGobjController_ScriptGetObjectId, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cSystem_getSOBJClassId, (void*)cSystem_ScriptHandleMessage, (void*)func_0016F9E0, (void*)0x0, (void*)cGobjController_WantsToBeActive, (void*)Actor_VirtualNop1753D0, (void*)Actor_VirtualNop1753E0, (void*)func_0015B820, (void*)cGobjController_IsPlayer, (void*)cGobjController_IsNPC, (void*)cGobjController_IsNetNPC, (void*)0x0, (void*)0x0, (void*)cGobjController_Team, (void*)cGobjController_Enemy_int, (void*)cGobjController_Enemy_cGOBJP, (void*)cGobjController_GetVelocity, (void*)PlayerComp_OnHitNop, (void*)func_0016FA00, (void*)cGobjController_CleanUpAfterTeleportationOfGobj, (void*)PlayerComp_GetDeathCode, (void*)cGobjController_DetermineDeathType_int, (void*)cGobjController_SetGobj, (void*)func_0016FA20, (void*)cGobjController_GetCopyMsg, (void*)func_001753F0, (void*)cGobjController_NoticeEnvironmentalDanger };
