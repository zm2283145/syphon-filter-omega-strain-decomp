#include "types.h"
#include "net_local_id.h"
#include "npc_info_rec.h"
extern unsigned char D_005721D0;
void func_00434E20(int self, NpcInfoMsg* m);
void func_00433CE0(int self, int key)
{
    int h;
    NpcInfoMsg m;
    NpcInfoRec* r;
    func_004355D0(self);
    r = func_004361C0(key, &h);
    if (r) {
        NPC_INFO_COPY(m, r)
        if (D_005721D0) {
            m.f10 = h;
            m.a6[NetLocalId()] = 0;
            r->a6[NetLocalId()] = 0;
            func_00434E20(self, &m);
            func_00434920(self, h);
        } else {
            r->a6[NetLocalId()] = 0;
        }
    }
}