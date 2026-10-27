#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
#include "net_local_id.h"
}
#include "net_owner_map.h"
extern "C" {
extern unsigned char D_005838A0[];
extern unsigned char D_00583890;
void cGenInfoObject_DoPendingAdds(NetOwnEnt* tbl);
void cGenInfoObject_DoPendingActDeacts(NetOwnEnt* tbl);
void cGenInfoObject_DoPendingOwner(NetOwnEnt* tbl);
}
typedef struct { char pad[4]; int owner; char pad8[0x1C - 8]; NetOwnEnt* tbl; } Hdl_9390;
extern "C" void func_00439390(int id, int sess, int kind)
{
    Hdl_9390* h;
    if (NetGetObject((NetOwnHdl**)&h, sess) == 0) {
        NetOwnEnt* tbl = h->tbl;
        if (kind == -2 && h->owner == NetLocalId()) {
            int i;
            int j;
            unsigned char* f;
            cGenInfoObject_DoPendingAdds(tbl);
            cGenInfoObject_DoPendingActDeacts(tbl);
            cGenInfoObject_DoPendingOwner(tbl);
            for (i = 0, f = D_005838A0; i < 4; i++, f++) {
                if (*f) {
                    int ok = g_IsMultiplayer ? D_005721C0 : 1;
                    if (ok) {
                        NetOwnEnt* e;
                        int bit;
                        bit = 1 << i;
                        for (j = 0, e = tbl; j < 55; j++, e++) {
                            if (e->key != -1) {
                                if (i == e->lo) {
                                    e->lo = 0;
                                    e->hi &= ~bit;
                                } else if (e->hi & bit) {
                                    e->hi &= ~bit;
                                }
                            }
                        }
                    }
                    *f = 0;
                }
            }
            D_00583890 = 1;
        }
    }
}
