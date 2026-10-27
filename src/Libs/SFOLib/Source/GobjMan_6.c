/*
 * Libs/SFOLib/Source/GobjMan: 6 files, 0040B6C0-0040B810
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040B6C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

int* std_vector_imp_cObjectId_begin(PtrVec* v) {
    return v->data;
}
static inline void merge_flush_func_0040B6C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040B6C0 */

/* merge_units: begin func_0040B6D0 */
#pragma push /* merge_units */
#include "GobjMan_types.h"

extern GobjMap D_00571C10;
extern GobjMapNode D_00571C14;
extern void std_tree_pair_cObjectId_value_compare_find(GobjMapNode** result, GobjMap* map, const GobjId* id);

/* Find the object associated with an ID in the global registry map. */
GobjEntry* cBaseObjList_LookupObj(GobjScope* unused, const GobjId* id)
{
    GobjMapNode* node;
    std_tree_pair_cObjectId_value_compare_find(&node, &D_00571C10, id);
    if (node == &D_00571C14)
        return 0;
    return node->object;
}
static inline void merge_flush_func_0040B6D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040B6D0 */

/* merge_units: begin func_0040B720 */
#pragma push /* merge_units */
typedef struct RegNode { struct RegNode* parent; char pad[0x10]; int list; int index; int* items; } RegNode;
extern void std_vector_imp_cObjectId_insert(int* list, int* where, int n, void* item);

/* Inserts the item into this node's list and every ancestor's. */
void cBaseObjList_Remove(RegNode* self, char* item)
{
    if (item) {
        std_vector_imp_cObjectId_insert(&self->list, self->items + self->index, 1, item + 0xC);
        if (self->parent) {
            cBaseObjList_Remove(self->parent, item);
        }
    }
}
static inline void merge_flush_func_0040B720(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040B720 */

/* merge_units: begin func_0040B790 */
#pragma push /* merge_units */
typedef struct Obj40B790 { char pad[0xC]; int key; } Obj40B790;
typedef struct Node40B790 { struct Node40B790* parent; char list[4]; } Node40B790;
typedef struct { int key; Obj40B790* val; } Pair40B790;
typedef struct { void* it; unsigned char ok; } Res40B790;
#if 0 /* merge_units */
extern void std_vector_cSystemPtr_push_back(void* list, Obj40B790** o);
#endif /* merge_units */
int std_vector_cSystemPtr_push_back(); /* merge_units */

extern void std_tree_pair_cObjectId_value_compare_insert_one(Res40B790* out, void* map, Pair40B790* p);
#if 0 /* merge_units */
extern char D_00571C10[];
#endif /* merge_units */
#define D_00571C10 ((char*)&D_00571C10) /* merge_units */



#pragma push
#pragma opt_propagation off
unsigned char cBaseObjList_Add(Node40B790* n, Obj40B790* o) {
    Res40B790 r;
Pair40B790 p;
    std_vector_cSystemPtr_push_back(n->list, &o);
    if (n->parent) return cBaseObjList_Add(n->parent, o);
    p.key = o->key;
    p.val = o;
    std_tree_pair_cObjectId_value_compare_insert_one(&r, D_00571C10, &p);
    return r.ok;
}
#pragma pop
#undef D_00571C10 /* merge_units */
static inline void merge_flush_func_0040B790(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040B790 */

/* merge_units: begin func_0040B810 */
#pragma push /* merge_units */
extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int count, int value);

/* Appends one object to the registry vector. */
int std_vector_cSystemPtr_push_back(PtrVec* v, int obj) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, obj);
}
static inline void merge_flush_func_0040B810(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040B810 */

/* merge_units: begin func_0040B830 */
#pragma push /* merge_units */
typedef struct { int pad; int count; void** data; } Vec40B830;
typedef struct { void* vt; char m4[0x10]; char m14[0xC]; } Obj40B830;
extern Vec40B830* GetPurgeList(void);
extern void std_vector_pod_int_resize(Vec40B830* v, int n, int* fill);
extern void std_vector_deleter_cObjectId_dtor(void* p, int f);
extern void std_vector_cSystemPtr_dtor(void* p, int f);
extern void operator_delete(void* p);
static inline void D1_40B830(void* p) { if (p) std_vector_deleter_cObjectId_dtor(p, 0); }
static inline void D2_40B830(void* p) { if (p) D1_40B830(p); }
static inline void D3_40B830(void* p) { if (p) D2_40B830(p); }
#pragma push
#pragma inline_depth(10)
#pragma opt_strength_reduction off
Obj40B830* cBaseObjList_dtor(Obj40B830* self, short del)
{
    if (self) {
        Vec40B830* v = GetPurgeList();
        int i;
        int last = v->count - 1;
        int zero;
        for (i = 0; !(last < i); i++) {
            if (v->data[i] == self) {
                v->data[i] = v->data[last];
                last--;
            }
        }
        zero = 0;
        std_vector_pod_int_resize(v, last + 1, &zero);
        D3_40B830(self->m14);
        if (self->m4) std_vector_cSystemPtr_dtor(self->m4, -1);
        if (del > 0) operator_delete(self);
    }
    return self;
}
#pragma pop
static inline void merge_flush_func_0040B830(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040B830 */
