#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct P_1B3A60 { char pad[0xC]; int h; };
class T_1B3A60 { public: VPAD16(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual void Set(int v); };
struct N_1B3A60 { char pad[0x30]; T_1B3A60* t; };
struct O_1B3A60 { char pad[0x58]; N_1B3A60* npc; };
extern "C" {
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
P_1B3A60* PlayerSlots_Get(int i);
int Player_GetIndex(int h);
void NpcAi_ActivateForPlayer(N_1B3A60* npc, P_1B3A60* p);
}
static inline int Net_1B3A60(void) { return D_005721C8 ? D_005721C0 : 1; }
static inline void Act_1B3A60(N_1B3A60* npc, P_1B3A60* f) { if (f && Net_1B3A60()) NpcAi_ActivateForPlayer(npc, f); }
extern "C" void func_001B3A60(O_1B3A60* self, int id)
{
    P_1B3A60* found = 0;
    if (id >= 0 && Net_1B3A60()) {
        int i;
        for (i = 0; i < 4; i++) {
            P_1B3A60* p = PlayerSlots_Get(i);
            if (p && Player_GetIndex(p->h) == id) { found = p; break; }
        }
    }
    self->npc->t->Set(-1);
    Act_1B3A60(self->npc, found);
}