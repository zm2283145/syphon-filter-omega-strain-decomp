#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void Actor_VirtualNop1753D0();
extern "C" void Actor_VirtualNop1753E0();
extern "C" void Receiver_HandleEventBase();
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
extern "C" void func_00154650();
extern "C" void func_0015B820();
extern "C" void func_0015B830();
extern "C" void func_0015B840();
extern "C" void func_0015B850();
extern "C" void func_0016F9E0();
extern "C" void PlayerComp_OnHitNop();
extern "C" void func_0016FA00();
extern "C" void PlayerComp_GetDeathCode();
extern "C" void func_0016FA20();
extern "C" void func_001753F0();
extern "C" void func_0022F430();
extern "C" void func_003CB1E0();
extern "C" void func_003CB1F0();
extern "C" void func_003CC500();
extern "C" void func_003CCF20();
extern "C" void func_003EA420();
extern "C" void func_003EA430();
extern "C" void Component_GetOwnerId();
extern void * const D_004E06C0[];
void Receiver_Destruct(void* p, short f);
void operator_delete(void* p);
}
struct L3EA5B0 { char pad[0x58]; int x58; };
struct O3EA5B0 { void* vt; char pad[0x2C]; L3EA5B0* link; };
extern "C" O3EA5B0* func_003EA5B0(O3EA5B0* self, short del)
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
        Receiver_Destruct(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}
void * const D_004E06C0[40] = { (void*)0x0, (void*)0x0, (void*)func_003EA5B0, (void*)Receiver_HandleEventBase, (void*)Component_GetOwnerId, (void*)func_0012ECF0, (void*)func_001383D0, (void*)func_0012ED00, (void*)func_0012ED10, (void*)func_0012ED20, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)func_003CB1E0, (void*)func_003CB1F0, (void*)func_0016F9E0, (void*)0x0, (void*)func_003EA430, (void*)Actor_VirtualNop1753D0, (void*)Actor_VirtualNop1753E0, (void*)func_0015B820, (void*)NpcAi_IsPlayer, (void*)func_00140E10, (void*)func_001535D0, (void*)0x0, (void*)0x0, (void*)func_0022F430, (void*)func_003CC500, (void*)func_003EA420, (void*)func_00154650, (void*)PlayerComp_OnHitNop, (void*)func_0016FA00, (void*)func_0015B830, (void*)PlayerComp_GetDeathCode, (void*)func_0014FC00, (void*)func_003CCF20, (void*)func_0016FA20, (void*)func_0015B840, (void*)func_001753F0, (void*)func_0015B850 };
