/*
 * main/GenInfoObject: range (2 files, 00439D00-0043A030)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "net_local_id.h"
#pragma push
#pragma cplusplus on
#include "net_owner_map.h"
#pragma pop

/* merge_units: begin func_00439D00 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {}typedef struct LNode_9D00 { struct LNode_9D00* prev; struct LNode_9D00* next; NetOwnEnt* data; } LNode_9D00;
struct LIt_9D00 { LNode_9D00* node; LIt_9D00() {} };
extern "C" {
extern char D_005838D8[];
LIt_9D00 List_Begin(void* list);
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
        func_00438E10(&it, List_Begin(D_005838D8));
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00439D00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00439D00 */

/* merge_units: begin func_0043A030 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {}extern "C" {
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0043A030(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0043A030 */
