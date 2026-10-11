#include "types.h"
#include "net_local_id.h"
#include "npc_info_rec.h"
void func_00434BE0(int self, NpcInfoMsg* m, unsigned char v);
void func_00433F20(int self, int key, signed char v)
{
    int h;
    NpcInfoMsg m;
    NpcInfoRec* r;
    if (D_005721C8) {
        func_004355D0(self);
        r = func_004361C0(key, &h);
        if (r) {
            NPC_INFO_COPY(m, r)
            m.aA[NetLocalId()] = v;
            m.f10 = h;
            r->aA[NetLocalId()] = v;
            func_00434BE0(self, &m, v);
            func_00434920(self, h);
        }
    }
}