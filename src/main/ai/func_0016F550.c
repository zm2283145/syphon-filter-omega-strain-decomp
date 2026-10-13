#pragma cplusplus on
#include "vtable_base_dtor.h"

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
extern "C" void func_0015B810();
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
void * const D_004D9890[44] = { (void*)0x0, (void*)0x0, (void*)cAI_dtor, (void*)Receiver_HandleEventBase, (void*)Component_GetOwnerId, (void*)func_0012ECF0, (void*)func_001383D0, (void*)func_0012ED00, (void*)func_0012ED10, (void*)func_0012ED20, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cAI_v0B, (void*)cAI_v0C, (void*)func_0016F9E0, (void*)cAI_v0E, (void*)func_003EA430, (void*)cAI_v10, (void*)cAI_v11, (void*)func_0015B820, (void*)NpcAi_IsPlayer, (void*)func_00140E10, (void*)func_001535D0, (void*)Controller_ToHit, (void*)0x0, (void*)NpcAi_GetTeam, (void*)Controller_IsEnemyTeam, (void*)Controller_IsEnemy, (void*)Controller_GetShooterMotion, (void*)PlayerComp_OnHitNop, (void*)func_0016FA00, (void*)func_0015B830, (void*)PlayerComp_GetDeathCode, (void*)func_0014FC00, (void*)Component_AttachOwner, (void*)func_0016FA20, (void*)func_0015B840, (void*)func_0015B810, (void*)func_0015B850, (void*)NpcAi_SetTeam, (void*)0x0, (void*)0x0, (void*)0x0 };
