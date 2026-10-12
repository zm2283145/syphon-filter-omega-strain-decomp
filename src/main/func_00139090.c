#pragma cplusplus on
#include "types.h"
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