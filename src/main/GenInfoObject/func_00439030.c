#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
#include "net_local_id.h"
}
#include "net_owner_map.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
void func_0043B200(void* map, NetOwnNode** n);
void Map_Clear(void* map);
}
extern "C" void func_00439030(NetOwnEnt* tbl)
{
    NetOwnIt it;
    NetOwnIt end;
    NetOwnIt b;
    NetOwnNode* cur; NetOwnEnt* found; unsigned char flag; NetOwnEnt* k;
    func_00439380(&b, D_00583900);
    found = 0;
    it = b;
    while (func_00439360(&end, func_00439370(D_00583900)), NetOwn_Ne(&it, &end)) {
        int i;
        cur = it.node;
        k = cur->v.first;
        flag = cur->v.second;
        Tree_Successor(&it);
        for (i = 0; i != 55; i++) {
            if (k->key == tbl[i].key) { found = &tbl[i]; break; }
        }
        if (found) {
            if (flag) found->hi |= 1 << NetLocalId();
            else if (found->hi & (1 << NetLocalId())) found->hi &= ~(1 << NetLocalId());
        }
        {
            AllocGuard g;
            Mem_Free(0, k, D_004BFD60, 0x2B6);
        }
        {
            NetOwnNode* c = cur;
            func_0043B200(D_00583900, &c);
        }
    }
    Map_Clear(D_00583900);
}