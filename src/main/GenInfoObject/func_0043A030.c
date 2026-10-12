#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
#include "net_local_id.h"
}
#include "net_owner_map.h"
extern "C" {
static const unsigned int dat_00497588[2] = { 0 };
}
extern "C" void func_0043A030(void* self, int* key)
{
    NetOwnEnt* e = NetOwn_Find(*key);
    if (e && NET_OWN_HAS(e->hi, 1 << NetLocalId())) {
        NetOwnIt it; NetOwnIt end; NetOwnIt end2; NetOwnIt t;
        NetOwnHdl* h;
        func_00439380(&t, D_00583900);
        it = t;
        while (func_00439360(&end, func_00439370(D_00583900)),
               NetOwn_Ne(&it, &end)) {
            NetOwnVal* v = &it.node->v;
            if (v->first->key == *key) { v->second = (0); break; }
            Tree_Successor(&it);
        }
        func_00439360(&end2, func_00439370(D_00583900));
        if (it.node == end2.node) {
            NetOwnEnt* n; char res[8]; NetOwnVal pv;
            NET_OWN_CLEAR(e->hi, 1 << NetLocalId());
            {
                AllocGuard g;
                n = (NetOwnEnt*)Mem_Alloc(0, 8, D_004BFD60, (0x196));
            }
            if (n) { n->key = *key; n->lo = 0xF; n->hi = 0; }
            pv.first = n;
            pv.second = (*(unsigned char*)dat_00497588);
            func_0043B340(res, D_00583900, &pv);
            func_002EB650(&h, D_00497578);
            if (h->owner == NetLocalId())
                func_00439390(NetLocalId(), D_00497578, -2);
        }
    }
}
