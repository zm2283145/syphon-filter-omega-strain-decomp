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

DEFINE_VTABLE_BASE_DTOR(func_00177890, D_004D9DA0, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00177890 */

/* merge_units: begin func_001778F0 */
#pragma push /* merge_units */
extern void Actor_VirtualNop1753D0();
extern void Actor_VirtualNop1753E0();
extern void Component_AttachOwner();
extern void Controller_GetShooterMotion();
extern void Controller_IsEnemy();
extern void Controller_IsEnemyTeam();
extern void Controller_ToHit();
extern void Player_DispatchMessage();
extern void Player_IsPlayer();
extern void Player_Update();
extern void cPlayer_v0B();
extern void cPlayer_v0C();
extern void cPlayer_v12();
extern void cPlayer_v17();
extern void cPlayer_v18();
extern void cPlayer_v1D();
extern void cPlayer_v1E();
extern void cPlayer_v26();
extern void func_0012ECF0();
extern void func_0012ED00();
extern void func_0012ED10();
extern void func_0012ED20();
extern void func_0012ED30();
extern void func_0012ED40();
extern void func_0012ED50();
extern void func_001383D0();
extern void func_00140E10();
extern void func_0014FC00();
extern void func_001535D0();
extern void func_0015B840();
extern void func_0015B850();
extern void func_0016F9E0();
extern void PlayerComp_OnHitNop();
extern void PlayerComp_GetDeathCode();
extern void func_0016FA20();
extern void func_001753F0();
extern void func_003EA430();
extern void Component_GetOwnerId();
extern void * const D_004D9CF0[];
extern void func_00177A30(void* p, int f);
extern void func_001779E0(void* p, int f);
extern void func_00177990(void* p, int f);
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
            func_00177A30((char*)self + 0x13C, -1);
            func_001779E0((char*)self + 0x98, -1);
            func_00177990((char*)self + 0x80, -1);
        }
        cGameGobjController_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D9CF0[44] = { (void*)0x0, (void*)0x0, (void*)cPlayer_dtor, (void*)Player_DispatchMessage, (void*)Component_GetOwnerId, (void*)func_0012ECF0, (void*)func_001383D0, (void*)func_0012ED00, (void*)func_0012ED10, (void*)func_0012ED20, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cPlayer_v0B, (void*)cPlayer_v0C, (void*)func_0016F9E0, (void*)Player_Update, (void*)func_003EA430, (void*)Actor_VirtualNop1753D0, (void*)Actor_VirtualNop1753E0, (void*)cPlayer_v12, (void*)Player_IsPlayer, (void*)func_00140E10, (void*)func_001535D0, (void*)Controller_ToHit, (void*)cPlayer_v17, (void*)cPlayer_v18, (void*)Controller_IsEnemyTeam, (void*)Controller_IsEnemy, (void*)Controller_GetShooterMotion, (void*)PlayerComp_OnHitNop, (void*)cPlayer_v1D, (void*)cPlayer_v1E, (void*)PlayerComp_GetDeathCode, (void*)func_0014FC00, (void*)Component_AttachOwner, (void*)func_0016FA20, (void*)func_0015B840, (void*)func_001753F0, (void*)func_0015B850, (void*)cPlayer_v26, (void*)0x0, (void*)0x0, (void*)0x0 };
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001778F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001778F0 */
