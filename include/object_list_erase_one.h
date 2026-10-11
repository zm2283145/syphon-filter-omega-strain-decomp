#ifndef OBJECT_LIST_ERASE_ONE_H
#define OBJECT_LIST_ERASE_ONE_H

/*
 * erase(pos) for the object list of object_list_erase_range.h (identical
 * template clones): advance *pos, unlink and free the node under the
 * allocator guard, decrement the count, return the advanced iterator
 * through *result. C++ only (#pragma cplusplus on before including).
 */
#include "object_list_erase_range.h"

#define DEFINE_OBJECT_LIST_ERASE_ONE(name)                                    \
    extern "C" void name(EraseListNode** result, EraseList* list,             \
                         EraseListNode** pos)                                 \
    {                                                                         \
        EraseListNode* n = *pos;                                              \
        *pos = n->next;                                                       \
        n->prev->next = n->next;                                              \
        n->next->prev = n->prev;                                              \
        if (n) {                                                              \
            AllocGuard guard;                                                 \
            Mem_Free(0, n, D_0049AE80, 0x64);                                 \
        }                                                                     \
        list->count--;                                                        \
        *result = *pos;                                                       \
    }

#endif /* OBJECT_LIST_ERASE_ONE_H */