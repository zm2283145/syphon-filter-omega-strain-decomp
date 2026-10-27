/*
 * SFOGame/Source/gameGobjController: 2 files, 002301E0-00230240
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002301E0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void Actor_VirtualNop1753D0();
extern "C" void Actor_VirtualNop1753E0();
extern "C" void cGameGobjController_SetGobj();
extern "C" void cGameGobjController_GetVelocity();
extern "C" void cGameGobjController_Enemy_cGOBJP();
extern "C" void cGameGobjController_Enemy_int();
extern "C" void cGameGobjController_UpdateToHitProbability();
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
extern "C" void cGameGobjController_v0B();
extern "C" void cGameGobjController_ScriptHandleMessage();
extern "C" void cGobjController_Team();
extern "C" void cGobjController_WantsToBeActive();
extern "C" void cGobjController_ScriptGetObjectId();
extern void * const D_004DBA20[];
void* cGobjController_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* cGameGobjController_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DBA20);
        cGobjController_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DBA20[40] = { (void*)0x0, (void*)0x0, (void*)cGameGobjController_dtor, (void*)cSystem_HandleMessage, (void*)cGobjController_ScriptGetObjectId, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cGameGobjController_v0B, (void*)cGameGobjController_ScriptHandleMessage, (void*)func_0016F9E0, (void*)0x0, (void*)cGobjController_WantsToBeActive, (void*)Actor_VirtualNop1753D0, (void*)Actor_VirtualNop1753E0, (void*)func_0015B820, (void*)cGobjController_IsPlayer, (void*)cGobjController_IsNPC, (void*)cGobjController_IsNetNPC, (void*)cGameGobjController_UpdateToHitProbability, (void*)0x0, (void*)cGobjController_Team, (void*)cGameGobjController_Enemy_int, (void*)cGameGobjController_Enemy_cGOBJP, (void*)cGameGobjController_GetVelocity, (void*)PlayerComp_OnHitNop, (void*)func_0016FA00, (void*)cGobjController_CleanUpAfterTeleportationOfGobj, (void*)PlayerComp_GetDeathCode, (void*)cGobjController_DetermineDeathType_int, (void*)cGameGobjController_SetGobj, (void*)func_0016FA20, (void*)cGobjController_GetCopyMsg, (void*)func_001753F0, (void*)cGobjController_NoticeEnvironmentalDanger };
static inline void merge_flush_func_002301E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002301E0 */

/* merge_units: begin func_00230240 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Base component constructor.
 */

#include "gameGobjController_types.h"

#if 0 /* merge_units */
extern char D_004DBA20[];   /* component vtable */
#endif /* merge_units */
#define D_004DBA20 ((char*)&D_004DBA20) /* merge_units */

extern int cGobjController_ctor(Component* self);

Component* cGameGobjController_ctor(Component* self) {
    cGobjController_ctor(self);
    self->vtable = D_004DBA20;
    self->unk38 = 1.0f;
    self->unk3C = -1;
    self->unk40 = 0;
    return self;
}
#undef D_004DBA20 /* merge_units */
static inline void merge_flush_func_00230240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00230240 */
