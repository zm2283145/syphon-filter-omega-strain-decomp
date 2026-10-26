#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
#include "net_local_id.h"
}
#include "net_owner_map.h"
extern "C" {
static const unsigned int dat_00497580[2] = { 0x1, 0x0 };
}
extern "C" void cGenInfoObject_Activate(void* self, int* key)
{
    NetOwnEnt* e = NetOwn_Find(*key);
    if (e && NET_OWN_LACKS(e->hi, 1 << NetLocalId())) {
        NetOwnIt it; NetOwnIt end; NetOwnIt end2; NetOwnIt t;
        NetOwnHdl* h;
        std_tree_pair_tGenInfoPtr_value_compare_begin(&t, D_00583900);
        it = t;
        while (cAssocArray_tGenInfoPtr_bool_Iterator_ctor(&end, std_map_tGenInfoPtr_bool_end(D_00583900)),
               NetOwn_Ne(&it, &end)) {
            NetOwnVal* v = &it.node->v;
            if (v->first->key == *key) { v->second = (1); break; }
            Tree_Successor(&it);
        }
        cAssocArray_tGenInfoPtr_bool_Iterator_ctor(&end2, std_map_tGenInfoPtr_bool_end(D_00583900));
        if (it.node == end2.node) {
            NetOwnEnt* n; char res[8]; NetOwnVal pv;
            NET_OWN_SET(e->hi, 1 << NetLocalId());
            {
                AllocGuard g;
                n = (NetOwnEnt*)Mem_Alloc(0, 8, D_004BFD60, (0x173));
            }
            if (n) { n->key = *key; n->lo = 0xF; n->hi = 0; }
            pv.first = n;
            pv.second = (*(unsigned char*)dat_00497580);
            std_tree_pair_tGenInfoPtr_value_compare_insert_one(res, D_00583900, &pv);
            NetGetObject(&h, D_00497578);
            if (h->owner == NetLocalId())
                func_00439390(NetLocalId(), D_00497578, -2);
        }
    }
}
