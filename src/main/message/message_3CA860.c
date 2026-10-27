/*
 * main/message: 5 files, 003CA860-003CAA50
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
extern SvcIt_c7* std_list_cSystemPtr_generic_iterator_ctor(SvcIt_c7* dst, SvcIt_c7* src);
extern void std_list_cSystemPtr_begin(SvcIt_c7* out, void* list);
extern SvcIt_c7* cLListIterator_cSystemPtr_ctor(SvcIt_c7* dst, SvcIt_c7* src);
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
#pragma pop /* merge_units */
/* merge_units: end func_003CAA50 */
