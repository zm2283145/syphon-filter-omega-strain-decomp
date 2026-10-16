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

void* func_00139060(char* self) {
    return self + 4;
}

List* ScalarCollection_Init(List* l) {
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
void Mem_Free(int pool, void* allocation, char* file, int line);
void func_0036D5D0(void* p, int flags);
}
struct LN_9090 { LN_9090* prev; LN_9090* next; char val[4]; };
struct L_9090 { int count; };
extern "C" void func_00139090(LN_9090** result, L_9090* list, LN_9090** first, LN_9090** last)
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
        func_0036D5D0((*first)->val, -1);
        LN_9090* n = *first;
        *first = (*first)->next;
        if (n) {
            AllocGuard guard;
            Mem_Free(0, n, "allocator.hh", 0x64);
        }
        list->count--;
    }
    *result = *last;
}
#pragma pop /* merge_units */
/* merge_units: end func_00139090 */

/* merge_units: begin func_001391E0 */
#pragma push /* merge_units */
List* func_001391E0(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
#pragma pop /* merge_units */
/* merge_units: end func_001391E0 */
