#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
#include "net_local_id.h"
}
#include "net_owner_map.h"
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void std_tree_pair_tGenInfoPtr_value_compare_erase(void* map, NetOwnNode** n);
void std_tree_pair_tGenInfoPtr_value_compare_clear(void* map);
}
extern "C" void cGenInfoObject_DoPendingActDeacts(NetOwnEnt* tbl)
{
    NetOwnIt it;
    NetOwnIt end;
    NetOwnIt b;
    NetOwnNode* cur; NetOwnEnt* found; unsigned char flag; NetOwnEnt* k;
    std_tree_pair_tGenInfoPtr_value_compare_begin(&b, D_00583900);
    found = 0;
    it = b;
    while (cAssocArray_tGenInfoPtr_bool_Iterator_ctor(&end, std_map_tGenInfoPtr_bool_end(D_00583900)), NetOwn_Ne(&it, &end)) {
        int i;
        cur = it.node;
        k = cur->v.first;
        flag = cur->v.second;
        std_red_black_tree_1_increment(&it);
        for (i = 0; i != 55; i++) {
            if (k->key == tbl[i].key) { found = &tbl[i]; break; }
        }
        if (found) {
            if (flag) found->hi |= 1 << NetLocalId();
            else if (found->hi & (1 << NetLocalId())) found->hi &= ~(1 << NetLocalId());
        }
        {
            AllocGuard g;
            cMemMan_Deallocate(0, k, D_004BFD60, 0x2B6);
        }
        {
            NetOwnNode* c = cur;
            std_tree_pair_tGenInfoPtr_value_compare_erase(D_00583900, &c);
        }
    }
    std_tree_pair_tGenInfoPtr_value_compare_clear(D_00583900);
}