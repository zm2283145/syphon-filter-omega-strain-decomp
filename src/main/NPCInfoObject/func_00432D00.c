#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
#include "net_local_id.h"
#include "npc_info_rec.h"
}
typedef struct { int key; char pad[0xC]; int f10; } Ent_2D00;
typedef struct { char pad[0xC]; Ent_2D00* e; unsigned char flag; } Node_2D00;
struct It_2D00 { Node_2D00* node; It_2D00() {} };
extern "C" {
extern char D_00582B50[];
extern char D_004BFCA0[];
void Mem_Free(int pool, void* p, char* file, int line);
void std_tree_pair_tNPCInfoPtr_value_compare_begin(It_2D00* r, void* map);
It_2D00 std_map_tNPCInfoPtr_bool_end(void* map);
void cAssocArray_tNPCInfoPtr_bool_Iterator_ctor(It_2D00* r, const It_2D00& s);
void Tree_Successor(It_2D00* it);
void std_tree_pair_tNPCInfoPtr_value_compare_erase(void* map, Node_2D00** n);
}
static inline unsigned char Ne_2D00(It_2D00* a, It_2D00* b) { return !(a->node == b->node); }
extern "C" void cNPCInfoObject_DoPendingActiveTerrain(void* self, NpcInfoRec* arr, int key)
{
    It_2D00 it;
    It_2D00 end;
    It_2D00 b;
    Node_2D00* cur; NpcInfoRec* found; unsigned char flag; Ent_2D00* e;
    std_tree_pair_tNPCInfoPtr_value_compare_begin(&b, D_00582B50);
    it = b;
    while (cAssocArray_tNPCInfoPtr_bool_Iterator_ctor(&end, std_map_tNPCInfoPtr_bool_end(D_00582B50)), Ne_2D00(&it, &end)) {
        cur = it.node;
        e = cur->e;
        flag = cur->flag;
        found = 0;
        Tree_Successor(&it);
        if (key == e->f10) {
            int i;
            for (i = 0; i != 29; i++) {
                if (e->key == arr[i].key) { found = &arr[i]; break; }
            }
            if (found) found->aA[NetLocalId()] = flag;
            {
                AllocGuard g;
                Mem_Free(0, e, D_004BFCA0, 0x6B6);
            }
            {
                Node_2D00* c = cur;
                std_tree_pair_tNPCInfoPtr_value_compare_erase(D_00582B50, &c);
            }
        }
    }
}