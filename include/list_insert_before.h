#ifndef LIST_INSERT_BEFORE_H
#define LIST_INSERT_BEFORE_H

/*
 * Doubly-linked list insert of one int value before *pos (identical
 * template clones, one per translation unit): allocate a 12-byte node
 * under the allocator guard, hold it in a node holder while the value is
 * copied, link it in, bump the count. C++ only (#pragma cplusplus on).
 */
#include "alloc_guard.h"

extern "C" {
extern char D_0049AE70[];
extern char D_0049AE80[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* allocation, char* file, int line);
}

struct ListIntNode {
    ListIntNode* prev;
    ListIntNode* next;
    int value;
};

struct ListInt {
    int count;
    int alloc;
};

struct ListInsertFlag {
    char c;
    ListInsertFlag() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ListInsertFlag() {}
};

struct ListNodeHolder;
extern "C" void func_00139060(ListNodeHolder* holder);

struct ListNodeHolder {
    int* alloc;
    ListIntNode* node;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ListNodeHolder()
    {
        if (node) {
            func_00139060(this);
            ListIntNode* p = node;
            if (p) {
                AllocGuard guard;
                Mem_Free(0, p, D_0049AE80, 0x64);
            }
        }
    }
};

#define DEFINE_LIST_INSERT_BEFORE(name)                                       \
    extern "C" int name(ListIntNode** result, ListInt* list,                  \
                        ListIntNode** pos, const int* value)                  \
    {                                                                         \
        ListIntNode* n;                                                       \
        int* alloc = &list->alloc;                                            \
        ListInsertFlag flag;                                                  \
        {                                                                     \
            AllocGuard guard;                                                 \
            n = (ListIntNode*)Mem_Alloc(0, 0xC, D_0049AE70, 0x5C);            \
        }                                                                     \
        ListNodeHolder h;                                                     \
        h.alloc = alloc;                                                      \
        h.node = n;                                                           \
        int* v = &h.node->value;                                              \
        if (v)                                                                \
            *v = *value;                                                      \
        ListIntNode* p;                                                       \
        ListIntNode* m = h.node;                                              \
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

#endif /* LIST_INSERT_BEFORE_H */