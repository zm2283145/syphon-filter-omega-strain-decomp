#include "types.h"
#include "npc_auth.h"
#include "npc_info_rec.h"
void func_00434D10(int self, NpcInfoMsg* m);

void func_004344C0(int self, int key, int v)
{
    int h;
    NpcInfoMsg m;
    NpcInfoRec* r;
    if (D_005721C8) {
        func_004355D0(self);
        if (NpcAuth_IsLocal()) {
            r = func_004361C0(key, &h);
            v = v >= 0 ? v : 0xFF;
            if (r && r->state != v) {
                NPC_INFO_COPY(m, r)
                m.state = v;
                m.b4 = r->b4;
                m.f10 = h;
                r->state = v;
                func_00434D10(self, &m);
                func_00434920(self, h);
            }
        }
    }
}

