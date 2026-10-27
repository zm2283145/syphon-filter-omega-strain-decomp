/*
 * Libs/SFOLib/Source/GobjMan: 4 files, 0040B6C0-0040B6D0
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
extern void std_vector_cSystemPtr_push_back(void* list, Obj40B790** o);
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
