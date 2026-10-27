/*
 * Libs/SFOLib/Source/system: 3 files, 003CAB20-003CAC40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CAB20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* cLListIterator_cSystemPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cSystemPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* std_list_cSystemPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_003CAB20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CAB20 */

/* merge_units: begin func_003CAB50 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_common_subs off
typedef struct { char pad[8]; int* key; } Svc_ab50;
typedef struct SvcNode_ab50 { struct SvcNode_ab50* prev; struct SvcNode_ab50* next; Svc_ab50* svc; } SvcNode_ab50;
typedef struct { SvcNode_ab50* p; } SvcIt_ab50;
typedef struct { char pad[0x20]; int list; } SvcMgr_ab50;
struct Empty_ab50 { char c; };
struct Pred_ab50 {
    Empty_ab50 e;
    Svc_ab50** svc;
    Pred_ab50(const Empty_ab50& c, Svc_ab50** s) : e(c), svc(s) {}
};
extern "C" {
void std_list_deleter_voidPtr_end_void(SvcIt_ab50* out, void* list);
#if 0 /* merge_units */
SvcIt_ab50* std_list_cSystemPtr_generic_iterator_ctor(SvcIt_ab50* dst, SvcIt_ab50* src);
#endif /* merge_units */
#define std_list_cSystemPtr_generic_iterator_ctor(a0, a1) ((SvcIt_ab50 *)std_list_cSystemPtr_generic_iterator_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

#if 0 /* merge_units */
void std_list_cSystemPtr_begin(SvcIt_ab50* out, void* list);
#endif /* merge_units */
#define std_list_cSystemPtr_begin(a0, a1) (std_list_cSystemPtr_begin((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

#if 0 /* merge_units */
SvcIt_ab50* cLListIterator_cSystemPtr_ctor(SvcIt_ab50* dst, SvcIt_ab50* src);
#endif /* merge_units */
#define cLListIterator_cSystemPtr_ctor(a0, a1) ((SvcIt_ab50 *)cLListIterator_cSystemPtr_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

void std_list_imp_voidPtr_remove_if(void* v, Pred_ab50 p);
}
struct KeyPred_ab50 { int* k; KeyPred_ab50(int* kk) : k(kk) {} bool operator()(Svc_ab50* s) const { return *s->key == *k; } };
inline Svc_ab50* Erase_ab50(SvcMgr_ab50* self, Svc_ab50*& svc, SvcIt_ab50 it, SvcNode_ab50* last, Empty_ab50& e) {
    for (; it.p != last; it.p = it.p->next) {
        if (KeyPred_ab50(svc->key)(it.p->svc)) {
            std_list_imp_voidPtr_remove_if(&self->list, Pred_ab50(e, &svc));
            return svc;
        }
    }
    return 0;
}
struct ItW_ab50 { SvcIt_ab50 i; };
extern "C" Svc_ab50* cSystemContainer_RemoveSystem(SvcMgr_ab50* self, Svc_ab50* svc) {
    ItW_ab50 uit;
    SvcIt_ab50 beg;
    SvcIt_ab50 end;
    Empty_ab50 e;
    SvcIt_ab50 e0;
    SvcIt_ab50 b0;
    SvcNode_ab50* last;
    std_list_deleter_voidPtr_end_void(&e0, &self->list);
    std_list_cSystemPtr_generic_iterator_ctor(&end, &e0);
    last = end.p;
    std_list_cSystemPtr_begin(&b0, &self->list);
    cLListIterator_cSystemPtr_ctor(&beg, &b0);
    for (uit = *(ItW_ab50*)&beg; uit.i.p != last; uit.i.p = uit.i.p->next) {
        if (KeyPred_ab50(svc->key)(uit.i.p->svc)) {
            std_list_imp_voidPtr_remove_if(&self->list, Pred_ab50(e, &svc));
            return svc;
        }
    }
    return 0;
}
#undef std_list_cSystemPtr_generic_iterator_ctor /* merge_units */
#undef std_list_cSystemPtr_begin /* merge_units */
#undef cLListIterator_cSystemPtr_ctor /* merge_units */
static inline void merge_flush_func_003CAB50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CAB50 */

/* merge_units: begin func_003CAC40 */
#pragma push /* merge_units */
#include "loose04_types.h"

extern L4Iter* std_list_deleter_voidPtr_insert(L4Iter* out, void* list, L4Iter* pos, int* value);
L4Iter* std_list_cSystemPtr_push_back(void* list, int* value);

/* Appends value to the list at +0x20; always returns 1. */
int cSystemContainer_AddSystem(Unk3CAC40* self, int value) {
    int loc[1];

    loc[0] = value;
    std_list_cSystemPtr_push_back(self->unk20, loc);
    return 1;
}

/* push_back on a list whose sentinel node is at +4. */
L4Iter* std_list_cSystemPtr_push_back(void* list, int* value) {
    L4Iter it[2];

    it[0].node = (L4Node*)((char*)list + 4);
    return std_list_deleter_voidPtr_insert(&it[1], list, &it[0], value);
}
static inline void merge_flush_func_003CAC40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CAC40 */
