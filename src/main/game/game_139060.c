/*
 * main/game: 3 files, 00139060-001391E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00139060 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void(char* self) {
    return self + 4;
}

List* std_list_deleter_voidPtr_ctor_void(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
#pragma pop /* merge_units */
/* merge_units: end func_00139060 */

/* merge_units: begin func_00139090 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void cHogFile_dtor(void* p, int flags);
}
struct LN_9090 { LN_9090* prev; LN_9090* next; char val[4]; };
struct L_9090 { int count; };
extern "C" void std_list_deleter_cHogFile_erase_listdeleter_listdeleter(LN_9090** result, L_9090* list, LN_9090** first, LN_9090** last)
{
    LN_9090* f = *first;
    LN_9090* l = *last;
    if (f == l) {
        *result = l;
        return;
    }
    LN_9090* lp = l->prev;
    f->prev->next = lp->next;
    lp->next->prev = f->prev;
    while (*first != *last) {
        cHogFile_dtor((*first)->val, -1);
        LN_9090* n = *first;
        *first = (*first)->next;
        if (n) {
            AllocGuard guard;
            cMemMan_Deallocate(0, n, "allocator.hh", 0x64);
        }
        list->count--;
    }
    *result = *last;
}
#pragma pop /* merge_units */
/* merge_units: end func_00139090 */

/* merge_units: begin func_001391E0 */
#pragma push /* merge_units */
List* std_list_deleter_cHogFile_ctor(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
#pragma pop /* merge_units */
/* merge_units: end func_001391E0 */
