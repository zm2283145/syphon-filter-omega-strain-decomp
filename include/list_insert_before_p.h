#ifndef LIST_INSERT_BEFORE_P_H
#define LIST_INSERT_BEFORE_P_H

/*
 * list_insert_before.h with the allocator file symbols and the node-holder
 * release callee as parameters (the holder type is generated per clone).
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" {
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
}

struct ListIntNodeP {
    ListIntNodeP* prev;
    ListIntNodeP* next;
    int value;
};

struct ListIntP {
    int count;
    int alloc;
};

struct ListInsertFlagP {
    char c;
    ListInsertFlagP() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ListInsertFlagP() {}
};

#define DEFINE_LIST_INSERT_BEFORE_P(name, allocFile, freeFile, holderFn)      \
    extern "C" {                                                              \
    extern char allocFile[];                                                  \
    extern char freeFile[];                                                   \
    }                                                                         \
    struct name##_Holder;                                                     \
    extern "C" void holderFn(name##_Holder* holder);                          \
    struct name##_Holder {                                                    \
        int* alloc;                                                           \
        ListIntNodeP* node;                                                   \
        __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~name##_Holder()        \
        {                                                                     \
            if (node) {                                                       \
                holderFn(this);                                               \
                ListIntNodeP* p = node;                                       \
                if (p) {                                                      \
                    AllocGuard guard;                                         \
                    cMemMan_Deallocate(0, p, freeFile, 0x64);                           \
                }                                                             \
            }                                                                 \
        }                                                                     \
    };                                                                        \
    extern "C" int name(ListIntNodeP** result, ListIntP* list,                \
                        ListIntNodeP** pos, const int* value)                 \
    {                                                                         \
        ListIntNodeP* n;                                                      \
        int* alloc = &list->alloc;                                            \
        ListInsertFlagP flag;                                                 \
        {                                                                     \
            AllocGuard guard;                                                 \
            n = (ListIntNodeP*)cMemMan_Allocate(0, 0xC, allocFile, 0x5C);            \
        }                                                                     \
        name##_Holder h;                                                      \
        h.alloc = alloc;                                                      \
        h.node = n;                                                           \
        int* v = &h.node->value;                                              \
        if (v)                                                                \
            *v = *value;                                                      \
        ListIntNodeP* p;                                                      \
        ListIntNodeP* m = h.node;                                             \
        h.node = 0;                                                           \
        p = *pos;                                                             \
        p->prev->next = m;                                                    \
        m->prev = p->prev;                                                    \
        p->prev = m;                                                          \
        m->next = p;                                                          \
        list->count++;                                                        \
        *result = m;                                                          \
        return 0;                                                             \
    }

#endif /* LIST_INSERT_BEFORE_P_H */