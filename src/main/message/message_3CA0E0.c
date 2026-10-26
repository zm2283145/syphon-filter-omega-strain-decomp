#pragma cplusplus on

#include "types.h"
#ifndef LIB_003CA0E0
#define LIB_003CA0E0

/*
 * Doubly-linked list insert of one int value before *pos (identical
 * template clones, one per translation unit): allocate a 12-byte node
 * under the allocator guard, hold it in a node holder while the value is
 * copied, link it in, bump the count. C++ only (#pragma cplusplus on).
 */
#include "alloc_guard.h"

extern "C" {
extern char D_004BD198[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* allocation, char* file, int line);
}

struct I8_003CA0E0Val { int w0; int w1; int w2; };
struct ListI8_003CA0E0Node {
    ListI8_003CA0E0Node* prev;
    ListI8_003CA0E0Node* next;
    I8_003CA0E0Val value;
};

struct ListI8_003CA0E0 {
    int count;
    int alloc;
};

struct ListI8_003CA0E0Flag {
    char c;
    ListI8_003CA0E0Flag() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ListI8_003CA0E0Flag() {}
};

struct ListI8_003CA0E0Holder;
extern "C" void details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_9(ListI8_003CA0E0Holder* holder);

struct ListI8_003CA0E0Holder {
    int* alloc;
    ListI8_003CA0E0Node* node;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ListI8_003CA0E0Holder()
    {
        if (node) {
            details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_9(this);
            ListI8_003CA0E0Node* p = node;
            if (p) {
                AllocGuard guard;
                Mem_Free(0, p, D_004BD198, 0x64);
            }
        }
    }
};

#define DEFINE_LIST_INSERT_BEFORE8(name)                                       \
    extern "C" int name(ListI8_003CA0E0Node** result, ListI8_003CA0E0* list,                  \
                        ListI8_003CA0E0Node** pos, const I8_003CA0E0Val* value)                  \
    {                                                                         \
        ListI8_003CA0E0Node* n;                                                       \
        int* alloc = &list->alloc;                                            \
        ListI8_003CA0E0Flag flag;                                                  \
        {                                                                     \
            AllocGuard guard;                                                 \
            n = (ListI8_003CA0E0Node*)Mem_Alloc(0, 20, "allocator.hh", 0x5C);            \
        }                                                                     \
        ListI8_003CA0E0Holder h;                                                     \
        h.alloc = alloc;                                                      \
        h.node = n;                                                           \
        I8_003CA0E0Val* v = &h.node->value;                                              \
        if (v)                                                                \
            *v = *value;                                                      \
        ListI8_003CA0E0Node* p;                                                       \
        ListI8_003CA0E0Node* m = h.node;                                              \
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

#endif /* LIB_003CA0E0 */
DEFINE_LIST_INSERT_BEFORE8(MsgQueue_Insert)
