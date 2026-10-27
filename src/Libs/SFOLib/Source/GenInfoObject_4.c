/*
 * Libs/SFOLib/Source/GenInfoObject: 2 files, 00438E20-00439030
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00438E20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Raw_8E20 { int p; };
struct Ent_8E20 { int key; unsigned char lo : 4; unsigned char hi : 4; char pad[3]; };
extern "C" {
void cMemMan_Deallocate(int, void*, char*, int);
void std_list_deleter_voidPtr_erase_listdeleter(int*, char*, int*);
Raw_8E20 std_list_deleter_voidPtr_begin_void(void*);
Raw_8E20 std_list_tGenInfoPtr_end(void*);
void std_list_tGenInfoPtr_generic_iterator_ctor(char**, const Raw_8E20&);
void cLListIterator_tGenInfoPtr_ctor(char**, const Raw_8E20&);
void std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(int*, char**);
void cGenInfoObject_ctor(int*);
extern char D_005838B8;
extern char D_004BFD60[];
}
#define Begin_8E20(o) std_list_tGenInfoPtr_generic_iterator_ctor(o, std_list_deleter_voidPtr_begin_void(&D_005838B8))
#define End_8E20(o) cLListIterator_tGenInfoPtr_ctor(o, std_list_tGenInfoPtr_end(&D_005838B8))
extern "C" void cGenInfoObject_DoPendingAdds(Ent_8E20* tbl) {
    int ctx;
    char* end;
    {
        char* e; Ent_8E20* t; char* n; char* cur; char* it;
        Begin_8E20(&it);
        n = it;
        while ((End_8E20(&end), n != end)) {
            int i;
            e = F_(n, 0x8, char*);
            cur = n;
            n = F_(n, 0x4, char*);
            {
                /* t is not reset per entry: retail keeps the previous entry's match when the key is absent */
                { i = 0; do { if (tbl[i].key == F_(e, 0x0, int)) { t = &tbl[i]; break; } } while (++i != 55); }
                if (!t) {
                    cGenInfoObject_ctor(&ctx);
                    {
                        int key = ((Ent_8E20*)e)->key;
                        unsigned char lo = ((Ent_8E20*)e)->lo;
                        int j;
                        for (j = 0; j < 55; j++) if (tbl[j].key == -1) break;
                        if (j < 55) { Ent_8E20* u = &tbl[j]; u->key = key; u->lo = lo; }
                    }
                }
            }
            {
                AllocGuard g;
                cMemMan_Deallocate(0, e, D_004BFD60, 0x2FD);
            }
            {
                char* c;
                int res;
                int pos;
                c = cur;
                std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&pos, &c);
                std_list_deleter_voidPtr_erase_listdeleter(&res, &D_005838B8, &pos);
            }
        }
    }
}
static inline void merge_flush_func_00438E20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00438E20 */

/* merge_units: begin func_00439030 */
#pragma push /* merge_units */
#pragma cplusplus on
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
static inline void merge_flush_func_00439030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00439030 */
