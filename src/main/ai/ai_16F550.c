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
extern "C" void Component_AttachOwner();
extern "C" void Controller_GetShooterMotion();
extern "C" void Controller_IsEnemy();
extern "C" void Controller_IsEnemyTeam();
extern "C" void Controller_ToHit();
extern "C" void Receiver_HandleEventBase();
extern "C" void cAI_v0B();
extern "C" void cAI_v0C();
extern "C" void cAI_v0E();
extern "C" void cAI_v10();
extern "C" void cAI_v11();
extern "C" void func_0012ECF0();
extern "C" void func_0012ED00();
extern "C" void func_0012ED10();
extern "C" void func_0012ED20();
extern "C" void func_0012ED30();
extern "C" void func_0012ED40();
extern "C" void func_0012ED50();
extern "C" void NpcAi_IsPlayer();
extern "C" void func_001383D0();
extern "C" void func_00140E10();
extern "C" void func_0014FC00();
extern "C" void func_001535D0();
extern "C" void NpcAi_GetTeam();
extern "C" void cNPC_v24();
extern "C" void func_0015B820();
extern "C" void func_0015B830();
extern "C" void func_0015B840();
extern "C" void func_0015B850();
extern "C" void NpcAi_SetTeam();
extern "C" void func_0016F9E0();
extern "C" void PlayerComp_OnHitNop();
extern "C" void func_0016FA00();
extern "C" void PlayerComp_GetDeathCode();
extern "C" void func_0016FA20();
extern "C" void func_003EA430();
extern "C" void Component_GetOwnerId();
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
void * const D_004D9890[44] = { (void*)0x0, (void*)0x0, (void*)cAI_dtor, (void*)Receiver_HandleEventBase, (void*)Component_GetOwnerId, (void*)func_0012ECF0, (void*)func_001383D0, (void*)func_0012ED00, (void*)func_0012ED10, (void*)func_0012ED20, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cAI_v0B, (void*)cAI_v0C, (void*)func_0016F9E0, (void*)cAI_v0E, (void*)func_003EA430, (void*)cAI_v10, (void*)cAI_v11, (void*)func_0015B820, (void*)NpcAi_IsPlayer, (void*)func_00140E10, (void*)func_001535D0, (void*)Controller_ToHit, (void*)0x0, (void*)NpcAi_GetTeam, (void*)Controller_IsEnemyTeam, (void*)Controller_IsEnemy, (void*)Controller_GetShooterMotion, (void*)PlayerComp_OnHitNop, (void*)func_0016FA00, (void*)func_0015B830, (void*)PlayerComp_GetDeathCode, (void*)func_0014FC00, (void*)Component_AttachOwner, (void*)func_0016FA20, (void*)func_0015B840, (void*)cNPC_v24, (void*)func_0015B850, (void*)NpcAi_SetTeam, (void*)0x0, (void*)0x0, (void*)0x0 };
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
extern "C" void Component_BaseInit(AiData*);
extern "C" int Controller_NotifySeen(AiSpawn*);
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
    Component_BaseInit(self);
    AiTimer_Init(&self->t);
    self->vt = D_004D9890;
    if (s && AiSpawn_Ready(s)) mode = Controller_NotifySeen(s);
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
DEFINE_VTABLE3_BASE_DTOR(func_0016F690, D_004D9850, D_004D92C0, D_004D92A0, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0016F690 */
