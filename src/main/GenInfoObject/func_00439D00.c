#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
#include "net_local_id.h"
}
#include "net_owner_map.h"
typedef struct LNode_9D00 { struct LNode_9D00* prev; struct LNode_9D00* next; NetOwnEnt* data; } LNode_9D00;
struct LIt_9D00 { LNode_9D00* node; LIt_9D00() {} };
extern "C" {
extern char D_005838D8[];
LIt_9D00 func_0013B180(void* list);
void func_00438E10(LIt_9D00* r, const LIt_9D00& s);
LIt_9D00 func_00438E00(void* list);
void func_00438DF0(LIt_9D00* r, const LIt_9D00& s);
void func_00439C40(void* list, NetOwnEnt** p);
}
typedef struct { unsigned char lo : 4; unsigned char hi : 4; } Bits_9D00;
typedef struct { int key; Bits_9D00 b; } Ent2_9D00;
extern "C" void func_00439D00(void* self, int* key, int owner)
{
    NetOwnEnt* e = NetOwn_Find(*key);
    if (e && e->lo != (owner >= 0 ? owner : 0xF)) {
        LIt_9D00 end;
        LIt_9D00 end2;
        NetOwnEnt* p;
        LIt_9D00 it;
        int o; if (owner >= 0) o = owner; else o = 0xF;
        LNode_9D00* n;
        func_00438E10(&it, func_0013B180(D_005838D8));
        n = it.node;
        while (func_00438DF0(&end, func_00438E00(D_005838D8)), n != end.node) {
            NetOwnEnt* d = n->data;
            if (d->key == *key) {
                Bits_9D00* b = &((Ent2_9D00*)d)->b; if (o != b->lo) b->lo = owner;
                break;
            }
            n = n->next;
        }
        func_00438DF0(&end2, func_00438E00(D_005838D8));
        if (n == end2.node) {
            NetOwnEnt* ne;
            {
                AllocGuard g;
                ne = (NetOwnEnt*)Mem_Alloc(0, 8, D_004BFD60, 0x1BB);
            }
            if (ne) { ne->key = *key; ne->lo = o; ne->hi = 0; }
            NetOwnHdl* h;
            p = ne;
            func_00439C40(D_005838D8, &p);
            func_002EB650(&h, D_00497578);
            if (h->owner == NetLocalId())
                func_00439390(NetLocalId(), D_00497578, -2);
        }
    }
}