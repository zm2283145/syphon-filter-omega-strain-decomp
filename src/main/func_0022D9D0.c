#pragma cplusplus on

#include "types.h"
#ifndef LIB_0022D9D0
#define LIB_0022D9D0

/*
 * Doubly-linked list insert of one int value before *pos (identical
 * template clones, one per translation unit): allocate a 12-byte node
 * under the allocator guard, hold it in a node holder while the value is
 * copied, link it in, bump the count. C++ only (#pragma cplusplus on).
 */
#include "alloc_guard.h"

extern "C" {
extern char D_004A6688[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* allocation, char* file, int line);
}

struct I8_0022D9D0Val { int w0; int w1; int w2; int w3; };
struct ListI8_0022D9D0Node {
    ListI8_0022D9D0Node* prev;
    ListI8_0022D9D0Node* next;
    I8_0022D9D0Val value;
};

struct ListI8_0022D9D0 {
    int count;
    int alloc;
};

struct ListI8_0022D9D0Flag {
    char c;
    ListI8_0022D9D0Flag() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ListI8_0022D9D0Flag() {}
};

struct ListI8_0022D9D0Holder;
extern "C" void details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_5(ListI8_0022D9D0Holder* holder);

struct ListI8_0022D9D0Holder {
    int* alloc;
    ListI8_0022D9D0Node* node;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ListI8_0022D9D0Holder()
    {
        if (node) {
            details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_5(this);
            ListI8_0022D9D0Node* p = node;
            if (p) {
                AllocGuard guard;
                Mem_Free(0, p, D_004A6688, 0x64);
            }
        }
    }
};

#define DEFINE_LIST_INSERT_BEFORE8(name)                                       \
    extern "C" int name(ListI8_0022D9D0Node** result, ListI8_0022D9D0* list,                  \
                        ListI8_0022D9D0Node** pos, const I8_0022D9D0Val* value)                  \
    {                                                                         \
        ListI8_0022D9D0Node* n;                                                       \
        int* alloc = &list->alloc;                                            \
        ListI8_0022D9D0Flag flag;                                                  \
        {                                                                     \
            AllocGuard guard;                                                 \
            n = (ListI8_0022D9D0Node*)Mem_Alloc(0, 24, "allocator.hh", 0x5C);            \
        }                                                                     \
        ListI8_0022D9D0Holder h;                                                     \
        h.alloc = alloc;                                                      \
        h.node = n;                                                           \
        I8_0022D9D0Val* v = &h.node->value;                                              \
        if (v)                                                                \
            *v = *value;                                                      \
        ListI8_0022D9D0Node* p;                                                       \
        ListI8_0022D9D0Node* m = h.node;                                              \
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

#endif /* LIB_0022D9D0 */
DEFINE_LIST_INSERT_BEFORE8(std_list_deleter_LosReqElem_insert)
