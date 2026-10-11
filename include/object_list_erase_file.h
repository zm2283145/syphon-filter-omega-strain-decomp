#ifndef OBJECT_LIST_ERASE_FILE_H
#define OBJECT_LIST_ERASE_FILE_H

/*
 * Same as object_list_erase_range.h / object_list_erase_one.h, with the
 * allocator file symbol as a parameter (clones from other source files):
 *   DEFINE_OBJECT_LIST_ERASE_RANGE_FILE(name, fileSym)
 *   DEFINE_OBJECT_LIST_ERASE_ONE_FILE(name, fileSym)
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" void Mem_Free(int pool, void* allocation, char* file, int line);

struct EraseFileNode {
    EraseFileNode* prev;
    EraseFileNode* next;
};

struct EraseFileList {
    int count;
};

#define DEFINE_OBJECT_LIST_ERASE_RANGE_FILE(name, fileSym)                    \
    extern "C" char fileSym[];                                                \
    extern "C" void name(EraseFileNode** result, EraseFileList* list,         \
                         EraseFileNode** first, EraseFileNode** last)         \
    {                                                                         \
        EraseFileNode* f = *first;                                            \
        EraseFileNode* l = *last;                                             \
        if (f == l) {                                                         \
            *result = l;                                                      \
            return;                                                           \
        }                                                                     \
        EraseFileNode* lp = l->prev;                                          \
        f->prev->next = lp->next;                                             \
        lp->next->prev = f->prev;                                             \
        while (*first != *last) {                                             \
            EraseFileNode* n = *first;                                        \
            *first = (*first)->next;                                          \
            if (n) {                                                          \
                AllocGuard guard;                                             \
                Mem_Free(0, n, fileSym, 0x64);                                \
            }                                                                 \
            list->count--;                                                    \
        }                                                                     \
        *result = *last;                                                      \
    }

#define DEFINE_OBJECT_LIST_ERASE_ONE_FILE(name, fileSym)                      \
    extern "C" char fileSym[];                                                \
    extern "C" void name(EraseFileNode** result, EraseFileList* list,         \
                         EraseFileNode** pos)                                 \
    {                                                                         \
        EraseFileNode* n = *pos;                                              \
        *pos = n->next;                                                       \
        n->prev->next = n->next;                                              \
        n->next->prev = n->prev;                                              \
        if (n) {                                                              \
            AllocGuard guard;                                                 \
            Mem_Free(0, n, fileSym, 0x64);                                    \
        }                                                                     \
        list->count--;                                                        \
        *result = *pos;                                                       \
    }

#endif /* OBJECT_LIST_ERASE_FILE_H */