#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct P_1B3960 { char pad[0xC]; int h; };
class O_1B3960 { public: VPAD16(a) VPAD4(b) VPAD2(c) virtual void Kill(int f); char pad4[0x54]; void* npc; };
extern "C" {
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
P_1B3960* func_003FB8D0(int i);
int func_003FB340(int h);
void cNPC_Deactivate(void* npc, P_1B3960* p);
}
static inline int Net_1B3960(void) { return D_005721C8 ? D_005721C0 : 1; }
static inline void Deact_1B3960(void* npc, P_1B3960* f) { if (f && Net_1B3960()) cNPC_Deactivate(npc, f); }
extern "C" void func_001B3960(O_1B3960* self, int id)
{
    P_1B3960* found = 0;
    if (id >= 0) {
        if (Net_1B3960()) {
            int i;
            for (i = 0; i < 4; i++) {
                P_1B3960* p = func_003FB8D0(i);
                if (p && func_003FB340(p->h) == id) { found = p; break; }
            }
        }
        Deact_1B3960(self->npc, found);
    } else {
        self->Kill(1);
    }
}

