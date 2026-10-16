#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
#include "net_local_id.h"
}
#include "net_owner_map.h"
typedef struct LNode_98E0 { struct LNode_98E0* prev; struct LNode_98E0* next; NetOwnEnt* data; } LNode_98E0;
struct LIt_98E0 { LNode_98E0* node; LIt_98E0() {} };
extern "C" {
extern char D_005838B8[];
extern unsigned char D_005721D0;
LIt_98E0 List_Begin(void* list);
void func_00438E10(LIt_98E0* r, const LIt_98E0& s);
LIt_98E0 func_00438E00(void* list);
void func_00438DF0(LIt_98E0* r, const LIt_98E0& s);
void func_00439C40(void* list, NetOwnEnt** p);
}
static inline NetOwnEnt* NetOwn_Find2(NetOwnEnt* tbl, int key)
{
    int i;
    if (tbl) {
        for (i = 0; i != 55; i++) {
            if (key == tbl[i].key) return &tbl[i];
        }
    }
    return 0;
}
static inline int Nib_98E0(int o) { return o >= 0 ? o : 0xF; }
extern "C" void func_004398E0(void* self, int* key, int owner)
{
    int k = *key;
    NetOwnEnt* tbl = D_00583888;
    if (!NetOwn_Find2(tbl, k)) {
        int o; if (owner >= 0) o = owner; else o = 0xF;
        if (D_005721D0) {
            LIt_98E0 end;
            LIt_98E0 end2;
            NetOwnEnt* p;
            LIt_98E0 it;
LNode_98E0* n;
            func_00438E10(&it, List_Begin(D_005838B8));
            n = it.node;
            while (func_00438DF0(&end, func_00438E00(D_005838B8)), n != end.node) {
                if (n->data->key == *key) break;
                n = n->next;
            }
            func_00438DF0(&end2, func_00438E00(D_005838B8));
            if (n == end2.node) {
                NetOwnEnt* nw;
                {
                    AllocGuard g;
                    nw = (NetOwnEnt*)Mem_Alloc(0, 8, D_004BFD60, 0x1EC);
                }
                if (nw) { nw->key = *key; nw->lo = o; nw->hi = 0; }
                NetOwnHdl* h;
                p = nw;
                func_00439C40(D_005838B8, &p);
                func_002EB650(&h, D_00497578);
                if (h->owner == NetLocalId())
                    func_00439390(NetLocalId(), D_00497578, -2);
            }
        } else {
            int i;
            for (i = 0; i < 55; i++) {
                if (tbl[i].key == -1) break;
            }
            if (i < 55) {
                tbl[i].key = k;
                tbl[i].lo = o;
            }
        }
    }
}