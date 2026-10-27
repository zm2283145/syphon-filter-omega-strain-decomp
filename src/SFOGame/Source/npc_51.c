/*
 * main/npc: range (3 files, 00158550-00158800)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

/* merge_units: begin func_00158550 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
struct V158 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual int v25(); virtual int v26(); virtual int v27(); virtual int v28(); virtual int v29(); };
extern "C" {
int cSystemContainer_GetSystem(char *, char *);
int cAI_dtor(char *, int);
int func_00161680(int, int);
int cPathSystem_ClearRequests(int, V158 *);
int func_0016DFD0(int, int);
int cNetObjectMgr_Delete(char *);
int operator_delete(char *);
extern char D_0049B670;
extern "C" void cGameGobjController_SetGobj();
extern "C" void cGameGobjController_GetVelocity();
extern "C" void cGameGobjController_Enemy_cGOBJP();
extern "C" void cGameGobjController_Enemy_int();
extern "C" void cGameGobjController_UpdateToHitProbability();
extern "C" void cNPC_DeactivateGlobal();
extern "C" void cNPC_SetAimMode_eAimMode_int();
extern "C" void cNPC_WeaponFired();
extern "C" void Npc_IsCorpseRemovable();
extern "C" void cNPC_AddAwareness();
extern "C" void cNPC_AddItem();
extern "C" void cNPC_AddWeapon();
extern "C" void cNPC_CriticalNextFrame();
extern "C" void cNPC_DontDropWeapons();
extern "C" void cNPC_EquipGoggles();
extern "C" void cNPC_ForceWeaponFire();
extern "C" void cNPC_GetActiveWeapon();
extern "C" void cNPC_GetAimPercent();
extern "C" void cNPC_GetClosestPlayer();
extern "C" void cNPC_GetDarkness();
extern "C" void cNPC_GetItemCount();
extern "C" void cNPC_GetWeapon();
extern "C" void cNPC_InViewCone();
extern "C" void cNPC_Kill();
extern "C" void cNPC_MoveToGobj();
extern "C" void cNPC_MoveToNode();
extern "C" void cNPC_RemoveAwareness();
extern "C" void cNPC_RemoveItem();
extern "C" void cNPC_RemoveWeapon();
extern "C" void cNPC_RequestAction();
extern "C" void cNPC_RequestDeathAnimation();
extern "C" void cNPC_ResendNewAwarenessMessage();
extern "C" void cNPC_ResumeAIAiming();
extern "C" void cNPC_ResumeAITravelSpeed();
extern "C" void cNPC_SetAggressiveness();
extern "C" void cNPC_SetAimSubtarget();
extern "C" void cNPC_SetDarkness();
extern "C" void cNPC_SetFireInvulnerability();
extern "C" void cNPC_SetFiringThreshold();
extern "C" void cNPC_SetGrenadeThrowAngle();
extern "C" void cNPC_SetHasDisguise();
extern "C" void cNPC_SetInvulnerable();
extern "C" void cNPC_SetNotGasable();
extern "C" void cNPC_SetNotTargetable();
extern "C" void cNPC_SetNotTaserable();
extern "C" void cNPC_SetOnFire();
extern "C" void cNPC_SetUnconscious();
extern "C" void cNPC_SetViewConeAngle();
extern "C" void cNPC_SetViewConeRadius();
extern "C" void cNPC_SetWeaponPreference();
extern "C" void cNPC_SetWeaponPreferenceDistance();
extern "C" void cNPC_StopAndLookAround();
extern "C" void cNPC_StopMovement();
extern "C" void cNPC_HandleMessage();
extern "C" void cNPC_NextFrame();
extern "C" void cNPC_Activate_void();
extern "C" void cNPC_Deactivate_void();
extern "C" void cNPC_IsNPC();
extern "C" void cNPC_GetBulletDir();
extern "C" void cNPC_NoticeDamage();
extern "C" void cNPC_NoticeDeath();
extern "C" void cNPC_DetermineDeathType();
extern "C" void cNPC_GetControllerType();
extern "C" void cNPC_v27();
extern "C" void cNPC_UseCurrentLookAt();
extern "C" void cNPC_TargetPositionValid();
extern "C" void cLList_cCAMERA_GOBJPtr_Size();
extern "C" void cNPC_IsTargetVisible();
extern "C" void cNPC_GetTargetGobj();
extern "C" void cNPC_Sound();
extern "C" void cNPC_SelectTravelMode();
extern "C" void cNPC_GetRawTravelSpeed();
extern "C" void cNPC_SetMode();
extern "C" void cNPC_ResumeAIMode();
extern "C" void cNPC_AddAwarenessOfPlayers();
extern "C" void cNPC_SendNewAwarenessOfPlayers();
extern "C" void cNPC_Follow_cGOBJP_float_float();
extern "C" void cNPC_CarryBodyToNode();
extern "C" void cNPC_Teleport();
extern "C" void cNPC_SetAimMode_eAimMode();
extern "C" void cNPC_SetFireMode();
extern "C" void cNPC_ResumeAIFiring();
extern "C" void cNPC_RequestLookAt_cGOBJP_float_int();
extern "C" void cNPC_RequestFacial();
extern "C" void cNPC_RequestLookAt_cVector_float_int();
extern "C" void cNPC_LookAround();
extern "C" void cNPC_ResumeAILookAt();
extern "C" void cNPC_SetTravelSpeed();
extern "C" void cNPC_GetTravelSpeed_eTravelSpeed();
extern "C" void cNPC_GetTravelSpeed_void();
extern "C" void cNPC_ResumeMovement();
extern "C" void cNPC_SetDesiredDistance();
extern "C" void cNPC_DeactivateDead();
extern "C" void cNPC_GetHitPoints();
extern "C" void cNPC_SetHitPoints();
extern "C" void cNPC_CheckHotbox();
extern "C" void cNPC_GetCurrentNode();
extern "C" void cNPC_GetNextNode();
extern "C" void cNPC_GetDestinationNode();
extern "C" void cNPC_SetGrenadeTarget();
extern "C" void cNPC_StoreWeapon();
extern "C" void cNPC_DrawWeapon();
extern "C" void cNPC_ChangeWeapon();
extern "C" void cNPC_DropWeapon();
extern "C" void cNPC_ActivateByRadius();
extern "C" void cNPC_ActivateByRadiusOff();
extern "C" void cNPC_SetPickupable();
extern "C" void cNPC_RestrictMovementToNodeGroup();
extern "C" void cNPC_AddGroupToPathRegion();
extern "C" void cNPC_RemoveGroupFromPathRegion();
extern "C" void cSystem_ScriptGetRealObj();
extern "C" void cSystem_SendCreated();
extern "C" void cSystem_NetActivate();
extern "C" void cSystem_NetDeactivate();
extern "C" void cSystem_NetEnable();
extern "C" void cSystem_NetDisable();
extern "C" void cSystem_IsDeliverable();
extern "C" void cGobjController_IsPlayer();
extern "C" void cSystem_IsNetworked();
extern "C" void cNPC_getSOBJClassId();
extern "C" void cNPC_ScriptHandleMessage();
extern "C" void cGobjController_IsNetNPC();
extern "C" void cNPC_DeactivateLocal();
extern "C" void cNPC_Activate_int();
extern "C" void cNPC_WantsToBeActive();
extern "C" void cNPC_GetCopyMsg();
extern "C" void cAI_Team();
extern "C" void cNPC_v24();
extern "C" void func_0015B820();
extern "C" void cGobjController_CleanUpAfterTeleportationOfGobj();
extern "C" void cGobjController_GetCopyMsg();
extern "C" void cGobjController_NoticeEnvironmentalDanger();
extern "C" void cAI_SetTeam();
extern "C" void cGobjController_ScriptGetObjectId();
extern void * const D_004D9380[];
extern char g_NpcRouteMgr;
extern char g_Game;
}
typedef struct { void *f0; char p4[44]; V158 *f30; char p34[293]; unsigned char f159; char p15A[82]; int f1AC; int f1B0; } PS0_00158550;
extern "C" char *cNPC_dtor(PS0_00158550 *arg0, long long arg1) {
    int temp_s2;

    if (arg0 != NULL) {
        arg0->f0 = &(*(char*)D_004D9380);
        if (arg0->f159 == 0) {
            ((V158 *)arg0)->v17();
        } else {
            cPathSystem_ClearRequests(cSystemContainer_GetSystem(&g_Game, &g_NpcRouteMgr), arg0->f30);
        }
        if (arg0->f30->v29() != 0) {
            cNetObjectMgr_Delete((char *)arg0->f30 + 0xC);
        }
        temp_s2 = arg0->f1B0;
        if (temp_s2 != 0) {
            {
                AllocGuard g;
                func_00161680(temp_s2, -1);
                cMemMan_Deallocate(0, temp_s2, &D_0049B670, 0x7E3);
            }
            arg0->f1B0 = 0;
        }
        temp_s2 = arg0->f1AC;
        if (temp_s2 != 0) {
            {
                AllocGuard g;
                func_0016DFD0(temp_s2, -1);
                cMemMan_Deallocate(0, temp_s2, &D_0049B670, 0x7E8);
            }
            arg0->f1AC = 0;
        }
        cAI_dtor((char *)arg0, 0);
        if (((long long)(arg1 << 0x30) >> 0x30) > 0) {
            operator_delete((char *)arg0);
        }
    }
    return (char *)arg0;
}
void * const D_004D9380[140] = { (void*)0x0, (void*)0x0, (void*)cNPC_dtor, (void*)cNPC_HandleMessage, (void*)cGobjController_ScriptGetObjectId, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cNPC_getSOBJClassId, (void*)cNPC_ScriptHandleMessage, (void*)cNPC_CriticalNextFrame, (void*)cNPC_NextFrame, (void*)cNPC_WantsToBeActive, (void*)cNPC_Activate_void, (void*)cNPC_Deactivate_void, (void*)func_0015B820, (void*)cGobjController_IsPlayer, (void*)cNPC_IsNPC, (void*)cGobjController_IsNetNPC, (void*)cGameGobjController_UpdateToHitProbability, (void*)cNPC_GetBulletDir, (void*)cAI_Team, (void*)cGameGobjController_Enemy_int, (void*)cGameGobjController_Enemy_cGOBJP, (void*)cGameGobjController_GetVelocity, (void*)cNPC_NoticeDamage, (void*)cNPC_NoticeDeath, (void*)cGobjController_CleanUpAfterTeleportationOfGobj, (void*)cNPC_DetermineDeathType, (void*)cNPC_GetControllerType, (void*)cGameGobjController_SetGobj, (void*)cNPC_GetCopyMsg, (void*)cGobjController_GetCopyMsg, (void*)cNPC_v24, (void*)cGobjController_NoticeEnvironmentalDanger, (void*)cAI_SetTeam, (void*)cNPC_v27, (void*)cNPC_UseCurrentLookAt, (void*)cNPC_TargetPositionValid, (void*)cLList_cCAMERA_GOBJPtr_Size, (void*)cNPC_IsTargetVisible, (void*)cNPC_GetTargetGobj, (void*)cNPC_SetAimMode_eAimMode_int, (void*)cNPC_DeactivateGlobal, (void*)cNPC_DeactivateLocal, (void*)cNPC_Activate_int, (void*)cNPC_WeaponFired, (void*)cNPC_Sound, (void*)cNPC_SelectTravelMode, (void*)cNPC_GetRawTravelSpeed, (void*)cNPC_SetMode, (void*)cNPC_ResumeAIMode, (void*)cNPC_AddAwareness, (void*)cNPC_RemoveAwareness, (void*)cNPC_AddAwarenessOfPlayers, (void*)cNPC_GetClosestPlayer, (void*)cNPC_ResendNewAwarenessMessage, (void*)cNPC_SendNewAwarenessOfPlayers, (void*)cNPC_Follow_cGOBJP_float_float, (void*)cNPC_MoveToNode, (void*)cNPC_MoveToGobj, (void*)cNPC_CarryBodyToNode, (void*)cNPC_Teleport, (void*)cNPC_SetAggressiveness, (void*)cNPC_SetAimMode_eAimMode, (void*)cNPC_SetAimSubtarget, (void*)cNPC_ResumeAIAiming, (void*)cNPC_SetFireMode, (void*)cNPC_ResumeAIFiring, (void*)cNPC_RequestLookAt_cGOBJP_float_int, (void*)cNPC_RequestFacial, (void*)cNPC_RequestLookAt_cVector_float_int, (void*)cNPC_LookAround, (void*)cNPC_StopAndLookAround, (void*)cNPC_ResumeAILookAt, (void*)cNPC_SetTravelSpeed, (void*)cNPC_ResumeAITravelSpeed, (void*)cNPC_GetTravelSpeed_eTravelSpeed, (void*)cNPC_GetTravelSpeed_void, (void*)cNPC_RequestAction, (void*)cNPC_StopMovement, (void*)cNPC_ResumeMovement, (void*)cNPC_SetDesiredDistance, (void*)cNPC_DeactivateDead, (void*)Npc_IsCorpseRemovable, (void*)cNPC_Kill, (void*)cNPC_SetFiringThreshold, (void*)cNPC_GetHitPoints, (void*)cNPC_SetHitPoints, (void*)cNPC_CheckHotbox, (void*)cNPC_SetOnFire, (void*)cNPC_SetViewConeRadius, (void*)cNPC_SetViewConeAngle, (void*)cNPC_InViewCone, (void*)cNPC_GetCurrentNode, (void*)cNPC_GetNextNode, (void*)cNPC_GetDestinationNode, (void*)cNPC_ForceWeaponFire, (void*)cNPC_SetGrenadeTarget, (void*)cNPC_SetGrenadeThrowAngle, (void*)cNPC_GetActiveWeapon, (void*)cNPC_StoreWeapon, (void*)cNPC_DrawWeapon, (void*)cNPC_ChangeWeapon, (void*)cNPC_DropWeapon, (void*)cNPC_AddWeapon, (void*)cNPC_RemoveWeapon, (void*)cNPC_GetWeapon, (void*)cNPC_SetWeaponPreference, (void*)cNPC_SetWeaponPreferenceDistance, (void*)cNPC_ActivateByRadius, (void*)cNPC_ActivateByRadiusOff, (void*)cNPC_SetPickupable, (void*)cNPC_SetHasDisguise, (void*)cNPC_SetDarkness, (void*)cNPC_GetDarkness, (void*)cNPC_GetAimPercent, (void*)cNPC_SetInvulnerable, (void*)cNPC_RequestDeathAnimation, (void*)cNPC_EquipGoggles, (void*)cNPC_RestrictMovementToNodeGroup, (void*)cNPC_AddGroupToPathRegion, (void*)cNPC_RemoveGroupFromPathRegion, (void*)cNPC_DontDropWeapons, (void*)cNPC_SetFireInvulnerability, (void*)cNPC_SetUnconscious, (void*)cNPC_SetNotTaserable, (void*)cNPC_SetNotGasable, (void*)cNPC_SetNotTargetable, (void*)cNPC_AddItem, (void*)cNPC_RemoveItem, (void*)cNPC_GetItemCount, (void*)0x0, (void*)0x0, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00158550(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00158550 */

/* merge_units: begin func_00158740 */
#pragma push /* merge_units */
#pragma cplusplus on
struct C6Slot_e8_1588D0 { int handle; int id; int pad[3]; };
struct C6B1_e8_1588D0 { void* vtable; char pad04[0x5C]; };
struct C6B2_e8_1588D0 { char pad[0x5C]; int regs[9]; void Clear() { for (int i = 0; i < 9; i++) regs[i] = 0; } };
struct C6AiComp_e8_1588D0 : C6B1_e8_1588D0, C6B2_e8_1588D0 {
    char padE0[0x150 - 0xE0];
    int kind;
    char pad154[0x16C - 0x154];
    C6Slot_e8_1588D0 slots[3];
    int pad1A8;
    int m1AC;
    int m1B0;
    char pad1B4[4]; int m1B8; char pad1BC[0x1C8 - 0x1BC];
    int m1C8;
    int m1CC;
};
extern "C" void cAI_ctor(C6AiComp_e8_1588D0*, void*, int);
extern "C" void cNPC_Init(C6AiComp_e8_1588D0*, void*);
#if 0 /* merge_units */
extern "C" char D_004D9380[];
#endif /* merge_units */
#define D_004D9380 ((char*)&D_004D9380) /* merge_units */

extern "C" C6AiComp_e8_1588D0* cNPC_ctor_cGOBJP(C6AiComp_e8_1588D0* self, void* owner) {
    cAI_ctor(self, owner, 0);
    C6B2_e8_1588D0& b = *self;
    b.Clear();
    self->vtable = D_004D9380;
    self->kind = 0;
    C6Slot_e8_1588D0* s = self->slots;
    do { s->id = -2; s->handle = 0; s++; } while (s != self->slots + 3);
    self->m1B8 = 0;
    self->m1CC = -2;
    self->m1C8 = 0;
    self->m1B0 = 0;
    self->m1AC = 0;
    cNPC_Init(self, owner);
    return self;
}
#undef D_004D9380 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00158740(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00158740 */

/* merge_units: begin func_00158800 */
#pragma push /* merge_units */
#pragma cplusplus on
struct C6Slot_158800 { int handle; int id; int pad[3]; };
struct C6B1_158800 { void* vtable; char pad04[0x5C]; };
struct C6B2_158800 { char pad[0x5C]; int regs[9]; void Clear() { for (int i = 0; i < 9; i++) regs[i] = 0; } };
struct C6AiComp_158800 : C6B1_158800, C6B2_158800 {
    char padE0[0x150 - 0xE0];
    int kind;
    char pad154[0x16C - 0x154];
    C6Slot_158800 slots[3];
    int pad1A8;
    int m1AC;
    int m1B0;
    char pad1B4[0x1C8 - 0x1B4];
    int m1C8;
    int m1CC;
};
#if 0 /* merge_units */
extern "C" void cAI_ctor(C6AiComp_158800*, void*, int);
#endif /* merge_units */
#define cAI_ctor(a0, a1, a2) (cAI_ctor((C6AiComp_e8_1588D0 *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern "C" void cNPC_Init(C6AiComp_158800*, void*);
#endif /* merge_units */
#define cNPC_Init(a0, a1) (cNPC_Init((C6AiComp_e8_1588D0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern "C" char D_004D9380[];
#endif /* merge_units */
#define D_004D9380 ((char*)&D_004D9380) /* merge_units */

extern "C" C6AiComp_158800* cNPC_ctor_cGOBJR_cObjectIdR_int(C6AiComp_158800* self, void* owner, int* kind) {
    cAI_ctor(self, owner, 0);
    C6B2_158800& b = *self;
    b.Clear();
    self->vtable = D_004D9380;
    self->kind = *kind;
    C6Slot_158800* s = self->slots;
    do { s->id = -2; s->handle = 0; s++; } while (s != self->slots + 3);
    self->m1CC = -2;
    self->m1C8 = 0;
    self->m1B0 = 0;
    self->m1AC = 0;
    cNPC_Init(self, owner);
    return self;
}
#undef cAI_ctor /* merge_units */
#undef cNPC_Init /* merge_units */
#undef D_004D9380 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00158800(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00158800 */
