/*
 * Libs/SFOLib/Source/system: 9 files, 003CA860-003CAB20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CA860 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Allocator release(ptr, pool, destroy, file, line): destroy the element's member at +4, then cMemMan_Deallocate under the guard. */
extern "C" {
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void* std_pair_int_cLList_tQueuedMessage_dtor(void* self, short flags);
void opDelete_nodeP_int_bool_charP_etc_3(void* allocation, int pool, int destroy, char* file, int line);
}
void opDelete_nodeP_int_bool_charP_etc_3(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation)
            std_pair_int_cLList_tQueuedMessage_dtor((char*)allocation + 12, -1);
    }
    cMemMan_Deallocate(pool, allocation, file, line);
}
static inline void merge_flush_func_003CA860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CA860 */

/* merge_units: begin func_003CA940 */
#pragma push /* merge_units */
extern void std_list_tQueuedMessage_dtor(void* self, short del);
extern void operator_delete(void* p);
void* std_pair_int_cLList_tQueuedMessage_dtor(void* self, short del)
{
    if (self) {
        void* m = (char*)self + 4;
        if (m)
            std_list_tQueuedMessage_dtor(m, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_003CA940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CA940 */

/* merge_units: begin func_003CA9A0 */
#pragma push /* merge_units */
extern char D_004BD178[];
extern void cTimerDisable_ctor(int* g);
extern void cTimerDisable_dtor(int* g, int del);
#if 0 /* merge_units */
extern void cMemMan_Deallocate(int heap, void* p, const char* file, int line);
#endif /* merge_units */
#define cMemMan_Deallocate(a0, a1, a2, a3) (cMemMan_Deallocate((a0), (a1), (char *)(a2), (a3))) /* merge_units */


void cAllocator_node_deallocate_nodeP_uint_4(void* self, void* p)
{
    if (p) {
        int g[1];
        cTimerDisable_ctor(g);
        cMemMan_Deallocate(0, p, D_004BD178, 100);
        cTimerDisable_dtor(g, -1);
    }
}
#undef cMemMan_Deallocate /* merge_units */
static inline void merge_flush_func_003CA9A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CA9A0 */

/* merge_units: begin func_003CAA00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern int cLList_tQueuedMessage_dtor(void* obj, int flags);

void* std_tree_pair_int_value_compare_cAllocator_pair_node_alloc_void(char* self) {
    return self + 4;
}

/* Destroys the object embedded 4 bytes into obj (flags -1) when obj is non-null. */
void cAllocator_pair_int_destroy_pairP(void* self, char* obj) {
    if (obj != 0) {
        cLList_tQueuedMessage_dtor(obj + 4, -1);
    }
}

void* std_tree_pair_int_value_compare_cAllocator_pair_alloc_void(void* self) {
    return self;
}
static inline void merge_flush_func_003CAA00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CAA00 */

/* merge_units: begin func_003CAA50 */
#pragma push /* merge_units */
#pragma opt_common_subs off
typedef struct { char pad[8]; int* key; } Svc_c7;
typedef struct SvcNode_c7 { struct SvcNode_c7* prev; struct SvcNode_c7* next; Svc_c7* svc; } SvcNode_c7;
typedef struct { SvcNode_c7* p; } SvcIt_c7;
typedef struct { char pad[0x20]; int list; } SvcMgr_c7;
extern void std_list_deleter_voidPtr_end_void(SvcIt_c7* out, void* list);
#if 0 /* merge_units */
extern SvcIt_c7* std_list_cSystemPtr_generic_iterator_ctor(SvcIt_c7* dst, SvcIt_c7* src);
#endif /* merge_units */
Word * std_list_cSystemPtr_generic_iterator_ctor(); /* merge_units */

#if 0 /* merge_units */
extern void std_list_cSystemPtr_begin(SvcIt_c7* out, void* list);
#endif /* merge_units */
void std_list_cSystemPtr_begin(); /* merge_units */

#if 0 /* merge_units */
extern SvcIt_c7* cLListIterator_cSystemPtr_ctor(SvcIt_c7* dst, SvcIt_c7* src);
#endif /* merge_units */
Word * cLListIterator_cSystemPtr_ctor(); /* merge_units */

Svc_c7* cSystemContainer_GetSystem(SvcMgr_c7* self, int* id) {
    SvcIt_c7 it;
    SvcIt_c7 beg;
    SvcIt_c7 end;
    SvcIt_c7 e0;
    SvcIt_c7 b0;
    SvcNode_c7* last;
    std_list_deleter_voidPtr_end_void(&e0, &self->list);
    std_list_cSystemPtr_generic_iterator_ctor(&end, &e0);
    last = end.p;
    std_list_cSystemPtr_begin(&b0, &self->list);
    cLListIterator_cSystemPtr_ctor(&beg, &b0);
    for (it = beg; it.p != last; it.p = it.p->next) {
        Svc_c7* s = it.p->svc; if (*s->key == *id) return s;
    }
    return 0;
}
static inline void merge_flush_func_003CAA50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CAA50 */

/* merge_units: begin func_003CAB20 */
#pragma push /* merge_units */
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
#if 0 /* merge_units */
void std_list_deleter_voidPtr_end_void(SvcIt_ab50* out, void* list);
#endif /* merge_units */
#define std_list_deleter_voidPtr_end_void(a0, a1) (std_list_deleter_voidPtr_end_void((SvcIt_c7 *)(a0), (a1))) /* merge_units */

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
#undef std_list_deleter_voidPtr_end_void /* merge_units */
#undef std_list_cSystemPtr_generic_iterator_ctor /* merge_units */
#undef std_list_cSystemPtr_begin /* merge_units */
#undef cLListIterator_cSystemPtr_ctor /* merge_units */
static inline void merge_flush_func_003CAB50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CAB50 */

/* merge_units: begin func_003CAC40 */
#pragma push /* merge_units */
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

/* merge_units: begin system_3CACA0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct VObj_ca0 { virtual void v0(); virtual bool v1(int m); };
typedef struct LNode_ca0 { struct LNode_ca0* prev; struct LNode_ca0* next; VObj_ca0* obj; } LNode_ca0;
typedef union { LNode_ca0* p; } LIt_ca0;
typedef struct { char pad[0x20]; int list; } Obj_ca0;
#if 0 /* merge_units */
extern "C" void std_list_deleter_voidPtr_end_void(LIt_ca0* out, void* list);
#endif /* merge_units */
#define std_list_deleter_voidPtr_end_void(a0, a1) (std_list_deleter_voidPtr_end_void((SvcIt_c7 *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern "C" LIt_ca0* std_list_cSystemPtr_generic_iterator_ctor(LIt_ca0* dst, LIt_ca0* src);
#endif /* merge_units */
#define std_list_cSystemPtr_generic_iterator_ctor(a0, a1) ((LIt_ca0 *)std_list_cSystemPtr_generic_iterator_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */


#if 0 /* merge_units */
extern "C" void std_list_cSystemPtr_begin(LIt_ca0* out, void* list);
#endif /* merge_units */
#define std_list_cSystemPtr_begin(a0, a1) (std_list_cSystemPtr_begin((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */


#if 0 /* merge_units */
extern "C" LIt_ca0* cLListIterator_cSystemPtr_ctor(LIt_ca0* dst, LIt_ca0* src);
#endif /* merge_units */
#define cLListIterator_cSystemPtr_ctor(a0, a1) ((LIt_ca0 *)cLListIterator_cSystemPtr_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */


extern "C" bool cSystemContainer_HandleMessage(Obj_ca0* self, int msg) {
    bool r = false;
    LIt_ca0 it;
    LIt_ca0 beg;
    LIt_ca0 end;
    LIt_ca0 e0;
    LIt_ca0 b0;
    LNode_ca0* last;
    std_list_deleter_voidPtr_end_void(&e0, &self->list);
    std_list_cSystemPtr_generic_iterator_ctor(&end, &e0);
    last = end.p;
    std_list_cSystemPtr_begin(&b0, &self->list);
    cLListIterator_cSystemPtr_ctor(&beg, &b0);
    for (it = beg; it.p != last; it.p = it.p->next) {
        VObj_ca0* o = it.p->obj;
        r |= o->v1(msg);
    }
    return r;
}
#undef std_list_deleter_voidPtr_end_void /* merge_units */
#undef std_list_cSystemPtr_generic_iterator_ctor /* merge_units */
#undef std_list_cSystemPtr_begin /* merge_units */
#undef cLListIterator_cSystemPtr_ctor /* merge_units */
static inline void merge_flush_system_3CACA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end system_3CACA0 */
