#pragma cplusplus on

#include "types.h"
#ifndef LIB_0037FCA0
#define LIB_0037FCA0

/*
 * Doubly-linked list insert of one int value before *pos (identical
 * template clones, one per translation unit): allocate a 12-byte node
 * under the allocator guard, hold it in a node holder while the value is
 * copied, link it in, bump the count. C++ only (#pragma cplusplus on).
 */
#include "alloc_guard.h"

extern "C" {
extern char D_004BC298[];
extern char D_004BC2A8[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* allocation, char* file, int line);
}

struct I8_0037FCA0Val { int w0; int w1; int w2; };
struct ListI8_0037FCA0Node {
    ListI8_0037FCA0Node* prev;
    ListI8_0037FCA0Node* next;
    I8_0037FCA0Val value;
};

struct ListI8_0037FCA0 {
    int count;
    int alloc;
};

struct ListI8_0037FCA0Flag {
    char c;
    ListI8_0037FCA0Flag() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ListI8_0037FCA0Flag() {}
};

struct ListI8_0037FCA0Holder;
extern "C" void func_0037FE70(ListI8_0037FCA0Holder* holder);

struct ListI8_0037FCA0Holder {
    int* alloc;
    ListI8_0037FCA0Node* node;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ListI8_0037FCA0Holder()
    {
        if (node) {
            func_0037FE70(this);
            ListI8_0037FCA0Node* p = node;
            if (p) {
                AllocGuard guard;
                Mem_Free(0, p, D_004BC2A8, 0x64);
            }
        }
    }
};

#define DEFINE_LIST_INSERT_BEFORE8(name)                                       \
    extern "C" int name(ListI8_0037FCA0Node** result, ListI8_0037FCA0* list,                  \
                        ListI8_0037FCA0Node** pos, const I8_0037FCA0Val* value)                  \
    {                                                                         \
        ListI8_0037FCA0Node* n;                                                       \
        int* alloc = &list->alloc;                                            \
        ListI8_0037FCA0Flag flag;                                                  \
        {                                                                     \
            AllocGuard guard;                                                 \
            n = (ListI8_0037FCA0Node*)Mem_Alloc(0, 20, D_004BC298, 0x5C);            \
        }                                                                     \
        ListI8_0037FCA0Holder h;                                                     \
        h.alloc = alloc;                                                      \
        h.node = n;                                                           \
        I8_0037FCA0Val* v = &h.node->value;                                              \
        if (v)                                                                \
            *v = *value;                                                      \
        ListI8_0037FCA0Node* p;                                                       \
        ListI8_0037FCA0Node* m = h.node;                                              \
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

#endif /* LIB_0037FCA0 */
DEFINE_LIST_INSERT_BEFORE8(func_0037FCA0)
