/*
 * main/ai: range (3 files, 0016F550-0016F690)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable3_base_dtor.h"
#pragma pop

/* merge_units: begin func_0016F550 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern "C" void cGameGobjController_SetGobj();
extern "C" void cGameGobjController_GetVelocity();
extern "C" void cGameGobjController_Enemy_cGOBJP();
extern "C" void cGameGobjController_Enemy_int();
extern "C" void cGameGobjController_UpdateToHitProbability();
extern "C" void cSystem_HandleMessage();
extern "C" void cAI_getSOBJClassId();
extern "C" void cAI_ScriptHandleMessage();
extern "C" void cAI_NextFrame();
extern "C" void cAI_Activate();
extern "C" void cAI_Deactivate();
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
extern "C" void cAI_Team();
extern "C" void cNPC_v24();
extern "C" void func_0015B820();
extern "C" void cGobjController_CleanUpAfterTeleportationOfGobj();
extern "C" void cGobjController_GetCopyMsg();
extern "C" void cGobjController_NoticeEnvironmentalDanger();
extern "C" void cAI_SetTeam();
extern "C" void func_0016F9E0();
extern "C" void PlayerComp_OnHitNop();
extern "C" void func_0016FA00();
extern "C" void PlayerComp_GetDeathCode();
extern "C" void func_0016FA20();
extern "C" void cGobjController_WantsToBeActive();
extern "C" void cGobjController_ScriptGetObjectId();
extern void * const D_004D9890[];
void* cGameGobjController_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* cAI_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004D9890);
        cGameGobjController_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D9890[44] = { (void*)0x0, (void*)0x0, (void*)cAI_dtor, (void*)cSystem_HandleMessage, (void*)cGobjController_ScriptGetObjectId, (void*)cSystem_ScriptGetRealObj, (void*)cSystem_IsNetworked, (void*)cSystem_SendCreated, (void*)cSystem_NetActivate, (void*)cSystem_NetDeactivate, (void*)cSystem_NetEnable, (void*)cSystem_NetDisable, (void*)cSystem_IsDeliverable, (void*)cAI_getSOBJClassId, (void*)cAI_ScriptHandleMessage, (void*)func_0016F9E0, (void*)cAI_NextFrame, (void*)cGobjController_WantsToBeActive, (void*)cAI_Activate, (void*)cAI_Deactivate, (void*)func_0015B820, (void*)cGobjController_IsPlayer, (void*)cGobjController_IsNPC, (void*)cGobjController_IsNetNPC, (void*)cGameGobjController_UpdateToHitProbability, (void*)0x0, (void*)cAI_Team, (void*)cGameGobjController_Enemy_int, (void*)cGameGobjController_Enemy_cGOBJP, (void*)cGameGobjController_GetVelocity, (void*)PlayerComp_OnHitNop, (void*)func_0016FA00, (void*)cGobjController_CleanUpAfterTeleportationOfGobj, (void*)PlayerComp_GetDeathCode, (void*)cGobjController_DetermineDeathType_int, (void*)cGameGobjController_SetGobj, (void*)func_0016FA20, (void*)cGobjController_GetCopyMsg, (void*)cNPC_v24, (void*)cGobjController_NoticeEnvironmentalDanger, (void*)cAI_SetTeam, (void*)0x0, (void*)0x0, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016F550(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016F550 */

/* merge_units: begin func_0016F5B0 */
#pragma push /* merge_units */
#pragma cplusplus on
class AiChk { public: virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5(); virtual void c6(); virtual void c7(); virtual void c8(); virtual void c9(); virtual void c10(); virtual void c11(); virtual void c12(); virtual void c13(); virtual void c14(); virtual void c15(); virtual void c16(); virtual void c17(); virtual void c18(); virtual unsigned char IsReady(); };
struct AiSpawn { char p[0x58]; AiChk* chk; };
class AiSelf { public: virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void SetMode(int m); };
struct AiTimer { int a; int b; int c; unsigned char done; };
struct AiData { void* vt; char p4[0x40]; AiTimer t; char p54[4]; float f58; unsigned char b5c, b5d; };
extern "C" void cGameGobjController_ctor(AiData*);
extern "C" int cGOBJ_Team(AiSpawn*);
#if 0 /* merge_units */
extern "C" char D_004D9890[];
#endif /* merge_units */
#define D_004D9890 ((char*)&D_004D9890) /* merge_units */

inline int AiTimer_Pos(AiTimer* t) { return t->c > 0; }
inline void AiTimer_Init(AiTimer* t) { t->a = 0; t->c = 0; if (!AiTimer_Pos(t)) { t->b = 0; t->done = 1; t->c = 0; } }
inline unsigned char AiSpawn_Ready(AiSpawn* s) { unsigned char r = 0; if (s->chk && s->chk->IsReady()) r = 1; return r; }
extern "C" AiData* cAI_ctor(AiData* self, AiSpawn* s)
{
    int mode;
    cGameGobjController_ctor(self);
    AiTimer_Init(&self->t);
    self->vt = D_004D9890;
    if (s && AiSpawn_Ready(s)) mode = cGOBJ_Team(s);
    else mode = 4;
    ((AiSelf*)self)->SetMode(mode);
    self->f58 = -1.0f;
    self->b5c = 0;
    self->b5d = 0;
    return self;
}
#undef D_004D9890 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016F5B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016F5B0 */

/* merge_units: begin func_0016F690 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Three-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE3_BASE_DTOR(cAISoundSystemGOBJPositionMessage_dtor, D_004D9850, D_004D92C0, D_004D92A0, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0016F690 */
