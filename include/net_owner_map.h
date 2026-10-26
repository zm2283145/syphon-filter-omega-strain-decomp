#ifndef NET_OWNER_MAP_H
#define NET_OWNER_MAP_H
/* 0x0043Axxx owner-map updates: find the key in the 55-entry table D_00583888,
   test the local player's bit in its mask nibble, mark a matching node of the
   map D_00583900 (or insert a fresh entry), then notify the session owner.
   C++ only; include alloc_guard.h and net_local_id.h first. */
typedef struct { int key; unsigned char lo : 4; unsigned char hi : 4; } NetOwnEnt;
typedef struct { NetOwnEnt* first; unsigned char second; } NetOwnVal;
typedef struct { char pad[0xC]; NetOwnVal v; } NetOwnNode;
struct NetOwnIt { NetOwnNode* node; NetOwnIt() {} };
typedef struct { char pad[4]; int owner; } NetOwnHdl;
extern "C" {
extern NetOwnEnt* D_00583888;
extern char D_00583900[];
extern int D_00497578;
extern char D_004BFD60[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void std_tree_pair_tGenInfoPtr_value_compare_begin(NetOwnIt* r, void* map);
NetOwnIt std_map_tGenInfoPtr_bool_end(void* map);
void cAssocArray_tGenInfoPtr_bool_Iterator_ctor(NetOwnIt* r, const NetOwnIt& s);
void Tree_Successor(NetOwnIt* it);
void std_tree_pair_tGenInfoPtr_value_compare_insert_one(void* r, void* map, NetOwnVal* v);
int NetGetObject(NetOwnHdl** out, int id);
void func_00439390(int id, int sess, int kind);
}
static inline unsigned char NetOwn_Ne(NetOwnIt* a, NetOwnIt* b) { return !(a->node == b->node); }
static inline NetOwnEnt* NetOwn_Find(int key)
{
    int i;
    if (D_00583888) {
        for (i = 0; i != 55; i++) {
            if (key == D_00583888[i].key) return &D_00583888[i];
        }
    }
    return 0;
}
/* TEST(hi, bit): entry condition; MARK: value stored in a matching node;
   UPD: statement updating e->hi with bit; SECOND: byte global for the new pair */
#define DEFINE_NET_OWNER_MAP(name, TEST, MARK, UPD, line, SECOND)               \
    extern "C" { extern unsigned char SECOND; }                                 \
    extern "C" void name(void* self, int* key)                                  \
    {                                                                           \
        NetOwnEnt* e = NetOwn_Find(*key);                                       \
        if (e && TEST(e->hi, 1 << NetLocalId())) {                              \
            NetOwnIt it; NetOwnIt end; NetOwnIt end2; NetOwnIt t;               \
            NetOwnHdl* h;                                                       \
            std_tree_pair_tGenInfoPtr_value_compare_begin(&t, D_00583900);                                      \
            it = t;                                                             \
            while (cAssocArray_tGenInfoPtr_bool_Iterator_ctor(&end, std_map_tGenInfoPtr_bool_end(D_00583900)),              \
                   NetOwn_Ne(&it, &end)) {                                      \
                NetOwnVal* v = &it.node->v;                                     \
                if (v->first->key == *key) { v->second = (MARK); break; }       \
                Tree_Successor(&it);                                            \
            }                                                                   \
            cAssocArray_tGenInfoPtr_bool_Iterator_ctor(&end2, std_map_tGenInfoPtr_bool_end(D_00583900));                    \
            if (it.node == end2.node) {                                         \
                NetOwnEnt* n; char res[8]; NetOwnVal pv;                        \
                UPD(e->hi, 1 << NetLocalId());                                  \
                {                                                               \
                    AllocGuard g;                                               \
                    n = (NetOwnEnt*)Mem_Alloc(0, 8, D_004BFD60, (line));        \
                }                                                               \
                if (n) { n->key = *key; n->lo = 0xF; n->hi = 0; }               \
                pv.first = n;                                                   \
                pv.second = SECOND;                                             \
                std_tree_pair_tGenInfoPtr_value_compare_insert_one(res, D_00583900, &pv);                            \
                NetGetObject(&h, D_00497578);                                  \
                if (h->owner == NetLocalId())                                   \
                    func_00439390(NetLocalId(), D_00497578, -2);                \
            }                                                                   \
        }                                                                       \
    }
#define NET_OWN_HAS(m, b) ((m) & (b))
#define NET_OWN_LACKS(m, b) (!((m) & (b)))
#define NET_OWN_CLEAR(m, b) ((m) &= ~(b))
#define NET_OWN_SET(m, b) ((m) |= (b))
#endif