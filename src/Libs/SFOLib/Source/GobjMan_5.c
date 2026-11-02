/*
 * Libs/SFOLib/Source/GobjMan: 7 files, 0040B510-0040B6C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040B510 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "GobjMan_types.h"
#pragma bool off
/* cBaseObjList_Purge: drop every object whose id is queued in the scope's id list (and unmap it in a root scope), then clear the list */
/* id-list cursor; a union so the whole-cursor copy is a block move like retail's */
union ItU_40B510 { int* p; };
struct It_40B510 { int* p; It_40B510() {} };
extern "C" {
extern GobjMap D_00571C10;
extern GobjMapNode D_00571C14;
#if 0 /* merge_units */
int* std_vector_imp_cObjectId_begin(GobjVec* v);
#endif /* merge_units */
int* std_vector_imp_cObjectId_begin(PtrVec* v); /* merge_units */
#define std_vector_imp_cObjectId_begin(a0) (std_vector_imp_cObjectId_begin((PtrVec *)(a0))) /* merge_units */

int* std_vector_imp_cObjectId_end(GobjVec* v);
struct It_40B510;
void std_vector_cObjectId_pointer2iterator(It_40B510* out, GobjVec* v, int* const& p);
void std_tree_pair_cObjectId_value_compare_find(GobjMapNode** result, GobjMap* map, const GobjId* id);
#if 0 /* merge_units */
void std_vector_pod_int_resize(GobjVec* v, int n, int* fill);
#endif /* merge_units */
void std_vector_pod_int_resize(void*, int, int*); /* merge_units */
#define std_vector_pod_int_resize(a0, a1, a2) (std_vector_pod_int_resize((void *)(a0), (a1), (a2))) /* merge_units */

void std_tree_pair_cObjectId_value_compare_erase(GobjMap* map, GobjMapNode** node);
void std_vector_deleter_cObjectId_clear(GobjVec* v);
void cBaseObjList_Purge(GobjScope* self);
}
static inline int Ne_40B510(int* a, int* b) { return !(a == b); }
static inline void Remove_40B510(GobjVec* v, int value, int* fill)
{
    int i;
    int last = v->count - 1;
    for (i = 0; last >= i; i++) {
        int* e = &v->data[i];
        if (*e == value) {
            *e = v->data[last];
            last--;
        }
    }
    *fill = 0;
    std_vector_pod_int_resize(v, last + 1, fill);
}
#pragma push
#pragma opt_strength_reduction off
void cBaseObjList_Purge(GobjScope* self)
{
    ItU_40B510 it;
    GobjId id;
    ItU_40B510 cur;
    GobjMapNode* node;
    int fill;
    It_40B510 b;
    GobjMapNode* n;
    It_40B510 e;
    std_vector_cObjectId_pointer2iterator(&b, &self->ids, std_vector_imp_cObjectId_begin(&self->ids));
    cur.p = b.p;
    it = cur;
    while ((std_vector_cObjectId_pointer2iterator(&e, &self->ids, std_vector_imp_cObjectId_end(&self->ids)), Ne_40B510(it.p, e.p))) {
        GobjMapNode* nd;
        id.word = *it.p;
        std_tree_pair_cObjectId_value_compare_find(&node, &D_00571C10, &id);
        nd = node;
        if (Ne_40B510((int*)nd, (int*)&D_00571C14)) {
            Remove_40B510(&self->objects, (int)nd->object, &fill);
            if (!self->parent) {
                n = nd;
                std_tree_pair_cObjectId_value_compare_erase(&D_00571C10, &n);
            }
        }
        it.p++;
    }
    std_vector_deleter_cObjectId_clear(&self->ids);
}
#pragma pop
#undef std_vector_imp_cObjectId_begin /* merge_units */
#undef std_vector_pod_int_resize /* merge_units */
static inline void merge_flush_func_0040B510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040B510 */

/* merge_units: begin func_0040B6C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

int* std_vector_imp_cObjectId_begin(PtrVec* v) {
    return v->data;
}
static inline void merge_flush_func_0040B6C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040B6C0 */

/* merge_units: begin func_0040B6D0 */
#pragma push /* merge_units */
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
#if 0 /* merge_units */
extern void std_vector_pod_int_resize(Vec40B830* v, int n, int* fill);
#endif /* merge_units */
#define std_vector_pod_int_resize(a0, a1, a2) (std_vector_pod_int_resize((void *)(a0), (a1), (a2))) /* merge_units */

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
#undef std_vector_pod_int_resize /* merge_units */
static inline void merge_flush_func_0040B830(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040B830 */
