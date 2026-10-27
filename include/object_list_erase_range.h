#ifndef OBJECT_LIST_ERASE_RANGE_H
#define OBJECT_LIST_ERASE_RANGE_H

/*
 * Linked-list erase(first, last) shared by identical template clones (one
 * per translation unit): unlink [first, last), then free each node
 * (file D_0049AE80, line 100) under the allocator guard and decrement the
 * count; returns last through *result.
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" {
extern char D_0049AE80[];
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
}

struct EraseListNode {
    EraseListNode* prev;
    EraseListNode* next;
};

struct EraseList {
    int count;
};

#define DEFINE_OBJECT_LIST_ERASE_RANGE(name)                                  \
    extern "C" void name(EraseListNode** result, EraseList* list,                 \
                         EraseListNode** first, EraseListNode** last)             \
    {                                                                         \
        EraseListNode* f = *first;                                              \
        EraseListNode* l = *last;                                               \
        if (f == l) {                                                         \
            *result = l;                                                      \
            return;                                                           \
        }                                                                     \
        EraseListNode* lp = l->prev;                                            \
        f->prev->next = lp->next;                                             \
        lp->next->prev = f->prev;                                             \
        while (*first != *last) {                                             \
            EraseListNode* n = *first;                                          \
            *first = (*first)->next;                                          \
            if (n) {                                                          \
                AllocGuard guard;                                             \
                cMemMan_Deallocate(0, n, D_0049AE80, 0x64);                             \
            }                                                                 \
            list->count--;                                                    \
        }                                                                     \
        *result = *last;                                                      \
    }

#endif /* OBJECT_LIST_ERASE_RANGE_H */