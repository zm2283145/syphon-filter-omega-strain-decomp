/*
 * Libs/SFOLib/Source/GobjMan: 1 file, 0040B510
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
int* std_vector_imp_cObjectId_begin(GobjVec* v);
int* std_vector_imp_cObjectId_end(GobjVec* v);
struct It_40B510;
void std_vector_cObjectId_pointer2iterator(It_40B510* out, GobjVec* v, int* const& p);
void std_tree_pair_cObjectId_value_compare_find(GobjMapNode** result, GobjMap* map, const GobjId* id);
void std_vector_pod_int_resize(GobjVec* v, int n, int* fill);
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
static inline void merge_flush_func_0040B510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040B510 */
