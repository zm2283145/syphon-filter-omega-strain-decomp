#include "types.h"
#include "net_local_id.h"
#include "npc_info_rec.h"
void func_00435070(int self, NpcInfoMsg* m);
void func_004341F0(int self, int key)
{
    int h;
    NpcInfoMsg m;
    NpcInfoRec* r;
    if (D_005721C8) {
        func_004355D0(self);
        r = func_004361C0(key, &h);
        if (r) {
            NPC_INFO_COPY(m, r)
            m.a6[NetLocalId()] = 1;
            r->a6[NetLocalId()] = 1;
            m.f10 = h;
            func_00435070(self, &m);
            func_00434920(self, h);
        }
    }
}
