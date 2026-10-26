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
void ObjMap_Find(GobjMapNode** result, GobjMap* map, const GobjId* id);
void PtrVector_Resize(GobjVec* v, int n, int* fill);
void std_tree_pair_cObjectId_value_compare_erase(GobjMap* map, GobjMapNode** node);
void Actor_VirtualLeaf175230(GobjVec* v);
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
    PtrVector_Resize(v, last + 1, fill);
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
        ObjMap_Find(&node, &D_00571C10, &id);
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
    Actor_VirtualLeaf175230(&self->ids);
}
#pragma pop
