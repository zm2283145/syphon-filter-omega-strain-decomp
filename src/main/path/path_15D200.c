/*
 * main/path: range (2 files, 0015D200-0015D280)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "obj_list_dtor.h"
#pragma pop
#include "types.h"

/* merge_units: begin func_0015D200 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_cPathSystemRequestPtr_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0015D200 */

/* merge_units: begin func_0015D280 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { int idx; int type; } F8Elem_15D;
struct F8It_15D {
    F8Elem_15D* p;
    bool operator==(const F8It_15D& o) const { return p == o.p; }
    bool operator!=(const F8It_15D& o) const { return !(*this == o); }
    F8It_15D& operator++() { p++; return *this; }
    F8Elem_15D* operator->() const { return p; }
};
typedef struct { char pad[0x68]; char list[4]; } F8Obj_15D;
typedef struct { char pad[8]; int* nodes; } F8Table_15D;
extern "C" {
F8Obj_15D* NpcPath_GetNode(int self);
F8Elem_15D* std_vector_imp_tNodeLink_begin_void_2(void* c);
F8Elem_15D* std_vector_imp_tNodeLink_end_void_2(void* c);
F8It_15D std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(void* c, F8Elem_15D** raw);
extern F8Table_15D* D_004FFBE0;
}
static inline F8It_15D F8Begin(void* c) { F8Elem_15D* b = std_vector_imp_tNodeLink_begin_void_2(c); return std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(c, &b); }
static inline F8It_15D F8End(void* c) { F8Elem_15D* e = std_vector_imp_tNodeLink_end_void_2(c); return std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(c, &e); }
static inline F8It_15D F8CBegin(void* c) { F8It_15D r; r.p = F8Begin(c).p; return r; }
static inline bool F8More(F8It_15D& it, void* c) { return it != F8End(c); }
extern "C" int NpcPath_FirstLinkOfType(int self, int type)
{
    int r;
    void* c;
    F8Table_15D* tbl = D_004FFBE0;
    r = 0;
    c = NpcPath_GetNode(self)->list;
    F8It_15D it = F8CBegin(c);
    while (F8More(it, c)) {
        F8Elem_15D* e = it.p;
        if (type == e->type) {
            r = tbl->nodes[e->idx];
            break;
        }
        it.p = e + 1;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015D280(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015D280 */
