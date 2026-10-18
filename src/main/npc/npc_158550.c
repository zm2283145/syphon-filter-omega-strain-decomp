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
int Mem_Free();

/* merge_units: begin func_00158550 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
struct V158 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual int v25(); virtual int v26(); virtual int v27(); virtual int v28(); virtual int v29(); };
extern "C" {
int Service_Lookup(char *, char *);
int cAI_dtor(char *, int);
int func_00161680(int, int);
int NpcRoute_Release(int, V158 *);
int func_0016DFD0(int, int);
int NetObjectMgr_Erase(char *);
int operator_delete(char *);
extern char D_0049B670;
extern "C" void Component_AttachOwner();
extern "C" void Controller_GetShooterMotion();
extern "C" void Controller_IsEnemy();
extern "C" void Controller_IsEnemyTeam();
extern "C" void Controller_ToHit();
extern "C" void NpcAi_DeactivateAnon();
extern "C" void NpcAi_RequestWeaponDraw();
extern "C" void NpcAttack_FireNotice();
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
extern "C" void cNPC_v01();
extern "C" void cNPC_v0E();
extern "C" void cNPC_v10();
extern "C" void cNPC_v11();
extern "C" void cNPC_v14();
extern "C" void cNPC_v17();
extern "C" void cNPC_v1C();
extern "C" void cNPC_v1D();
extern "C" void cNPC_v1F();
extern "C" void cNPC_v20();
extern "C" void cNPC_v27();
extern "C" void cNPC_v28();
extern "C" void cNPC_v29();
extern "C" void cNPC_v2A();
extern "C" void cNPC_v2B();
extern "C" void cNPC_v2C();
extern "C" void cNPC_v32();
extern "C" void cNPC_v33();
extern "C" void cNPC_v34();
extern "C" void cNPC_v35();
extern "C" void cNPC_v36();
extern "C" void cNPC_v39();
extern "C" void cNPC_v3C();
extern "C" void cNPC_v3D();
extern "C" void cNPC_v40();
extern "C" void cNPC_v41();
extern "C" void cNPC_v43();
extern "C" void cNPC_v46();
extern "C" void cNPC_v47();
extern "C" void cNPC_v48();
extern "C" void cNPC_v49();
extern "C" void cNPC_v4A();
extern "C" void cNPC_v4B();
extern "C" void cNPC_v4D();
extern "C" void cNPC_v4E();
extern "C" void cNPC_v50();
extern "C" void cNPC_v51();
extern "C" void cNPC_v54();
extern "C" void cNPC_v55();
extern "C" void cNPC_v56();
extern "C" void cNPC_v5A();
extern "C" void cNPC_v5B();
extern "C" void cNPC_v5C();
extern "C" void cNPC_v61();
extern "C" void cNPC_v62();
extern "C" void cNPC_v63();
extern "C" void cNPC_v65();
extern "C" void cNPC_v68();
extern "C" void cNPC_v69();
extern "C" void cNPC_v6A();
extern "C" void cNPC_v6B();
extern "C" void cNPC_v71();
extern "C" void cNPC_v72();
extern "C" void cNPC_v73();
extern "C" void cNPC_v7B();
extern "C" void cNPC_v7C();
extern "C" void cNPC_v7D();
extern "C" void func_0012ECF0();
extern "C" void func_0012ED00();
extern "C" void func_0012ED10();
extern "C" void func_0012ED20();
extern "C" void func_0012ED30();
extern "C" void func_0012ED40();
extern "C" void func_0012ED50();
extern "C" void NpcAi_IsPlayer();
extern "C" void func_001383D0();
extern "C" void func_0014A6B0();
extern "C" void AiComponent_ScriptFilter();
extern "C" void func_001535D0();
extern "C" void func_001577B0();
extern "C" void NpcAi_ActivateMultiplayer();
extern "C" void NpcAi_IsAliveOrEligible();
extern "C" void func_00158350();
extern "C" void NpcAi_GetTeam();
extern "C" void func_0015B810();
extern "C" void func_0015B820();
extern "C" void func_0015B830();
extern "C" void func_0015B840();
extern "C" void func_0015B850();
extern "C" void NpcAi_SetTeam();
extern "C" void Component_GetOwnerId();
extern void * const D_004D9380[];
extern char g_NpcRouteMgr;
extern char D_004FFB50;
}
typedef struct { void *f0; char p4[44]; V158 *f30; char p34[293]; unsigned char f159; char p15A[82]; int f1AC; int f1B0; } PS0_00158550;
extern "C" char *cNPC_dtor(PS0_00158550 *arg0, long long arg1) {
    int temp_s2;

    if (arg0 != NULL) {
        arg0->f0 = &(*(char*)D_004D9380);
        if (arg0->f159 == 0) {
            ((V158 *)arg0)->v17();
        } else {
            NpcRoute_Release(Service_Lookup(&D_004FFB50, &g_NpcRouteMgr), arg0->f30);
        }
        if (arg0->f30->v29() != 0) {
            NetObjectMgr_Erase((char *)arg0->f30 + 0xC);
        }
        temp_s2 = arg0->f1B0;
        if (temp_s2 != 0) {
            {
                AllocGuard g;
                func_00161680(temp_s2, -1);
                Mem_Free(0, temp_s2, &D_0049B670, 0x7E3);
            }
            arg0->f1B0 = 0;
        }
        temp_s2 = arg0->f1AC;
        if (temp_s2 != 0) {
            {
                AllocGuard g;
                func_0016DFD0(temp_s2, -1);
                Mem_Free(0, temp_s2, &D_0049B670, 0x7E8);
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
void * const D_004D9380[140] = { (void*)0x0, (void*)0x0, (void*)cNPC_dtor, (void*)cNPC_v01, (void*)Component_GetOwnerId, (void*)func_0012ECF0, (void*)func_001383D0, (void*)func_0012ED00, (void*)func_0012ED10, (void*)func_0012ED20, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)func_0014A6B0, (void*)AiComponent_ScriptFilter, (void*)cNPC_CriticalNextFrame, (void*)cNPC_v0E, (void*)NpcAi_IsAliveOrEligible, (void*)cNPC_v10, (void*)cNPC_v11, (void*)func_0015B820, (void*)NpcAi_IsPlayer, (void*)cNPC_v14, (void*)func_001535D0, (void*)Controller_ToHit, (void*)cNPC_v17, (void*)NpcAi_GetTeam, (void*)Controller_IsEnemyTeam, (void*)Controller_IsEnemy, (void*)Controller_GetShooterMotion, (void*)cNPC_v1C, (void*)cNPC_v1D, (void*)func_0015B830, (void*)cNPC_v1F, (void*)cNPC_v20, (void*)Component_AttachOwner, (void*)func_00158350, (void*)func_0015B840, (void*)func_0015B810, (void*)func_0015B850, (void*)NpcAi_SetTeam, (void*)cNPC_v27, (void*)cNPC_v28, (void*)cNPC_v29, (void*)cNPC_v2A, (void*)cNPC_v2B, (void*)cNPC_v2C, (void*)NpcAi_RequestWeaponDraw, (void*)NpcAi_DeactivateAnon, (void*)func_001577B0, (void*)NpcAi_ActivateMultiplayer, (void*)NpcAttack_FireNotice, (void*)cNPC_v32, (void*)cNPC_v33, (void*)cNPC_v34, (void*)cNPC_v35, (void*)cNPC_v36, (void*)cNPC_AddAwareness, (void*)cNPC_RemoveAwareness, (void*)cNPC_v39, (void*)cNPC_GetClosestPlayer, (void*)cNPC_ResendNewAwarenessMessage, (void*)cNPC_v3C, (void*)cNPC_v3D, (void*)cNPC_MoveToNode, (void*)cNPC_MoveToGobj, (void*)cNPC_v40, (void*)cNPC_v41, (void*)cNPC_SetAggressiveness, (void*)cNPC_v43, (void*)cNPC_SetAimSubtarget, (void*)cNPC_ResumeAIAiming, (void*)cNPC_v46, (void*)cNPC_v47, (void*)cNPC_v48, (void*)cNPC_v49, (void*)cNPC_v4A, (void*)cNPC_v4B, (void*)cNPC_StopAndLookAround, (void*)cNPC_v4D, (void*)cNPC_v4E, (void*)cNPC_ResumeAITravelSpeed, (void*)cNPC_v50, (void*)cNPC_v51, (void*)cNPC_RequestAction, (void*)cNPC_StopMovement, (void*)cNPC_v54, (void*)cNPC_v55, (void*)cNPC_v56, (void*)Npc_IsCorpseRemovable, (void*)cNPC_Kill, (void*)cNPC_SetFiringThreshold, (void*)cNPC_v5A, (void*)cNPC_v5B, (void*)cNPC_v5C, (void*)cNPC_SetOnFire, (void*)cNPC_SetViewConeRadius, (void*)cNPC_SetViewConeAngle, (void*)cNPC_InViewCone, (void*)cNPC_v61, (void*)cNPC_v62, (void*)cNPC_v63, (void*)cNPC_ForceWeaponFire, (void*)cNPC_v65, (void*)cNPC_SetGrenadeThrowAngle, (void*)cNPC_GetActiveWeapon, (void*)cNPC_v68, (void*)cNPC_v69, (void*)cNPC_v6A, (void*)cNPC_v6B, (void*)cNPC_AddWeapon, (void*)cNPC_RemoveWeapon, (void*)cNPC_GetWeapon, (void*)cNPC_SetWeaponPreference, (void*)cNPC_SetWeaponPreferenceDistance, (void*)cNPC_v71, (void*)cNPC_v72, (void*)cNPC_v73, (void*)cNPC_SetHasDisguise, (void*)cNPC_SetDarkness, (void*)cNPC_GetDarkness, (void*)cNPC_GetAimPercent, (void*)cNPC_SetInvulnerable, (void*)cNPC_RequestDeathAnimation, (void*)cNPC_EquipGoggles, (void*)cNPC_v7B, (void*)cNPC_v7C, (void*)cNPC_v7D, (void*)cNPC_DontDropWeapons, (void*)cNPC_SetFireInvulnerability, (void*)cNPC_SetUnconscious, (void*)cNPC_SetNotTaserable, (void*)cNPC_SetNotGasable, (void*)cNPC_SetNotTargetable, (void*)cNPC_AddItem, (void*)cNPC_RemoveItem, (void*)cNPC_GetItemCount, (void*)0x0, (void*)0x0, (void*)0x0 };
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
extern "C" void NpcAi_Construct(C6AiComp_e8_1588D0*, void*);
#if 0 /* merge_units */
extern "C" char D_004D9380[];
#endif /* merge_units */
#define D_004D9380 ((char*)&D_004D9380) /* merge_units */

extern "C" C6AiComp_e8_1588D0* cNPC_ctor(C6AiComp_e8_1588D0* self, void* owner) {
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
    NpcAi_Construct(self, owner);
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
extern "C" void NpcAi_Construct(C6AiComp_158800*, void*);
#endif /* merge_units */
#define NpcAi_Construct(a0, a1) (NpcAi_Construct((C6AiComp_e8_1588D0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern "C" char D_004D9380[];
#endif /* merge_units */
#define D_004D9380 ((char*)&D_004D9380) /* merge_units */

extern "C" C6AiComp_158800* AiComponent_Construct(C6AiComp_158800* self, void* owner, int* kind) {
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
    NpcAi_Construct(self, owner);
    return self;
}
#undef cAI_ctor /* merge_units */
#undef NpcAi_Construct /* merge_units */
#undef D_004D9380 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00158800(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00158800 */
