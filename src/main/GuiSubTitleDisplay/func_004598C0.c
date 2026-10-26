#pragma cplusplus on

#include "types.h"
#ifndef LIB_004598C0
#define LIB_004598C0

/*
 * Doubly-linked list insert of one int value before *pos (identical
 * template clones, one per translation unit): allocate a 12-byte node
 * under the allocator guard, hold it in a node holder while the value is
 * copied, link it in, bump the count. C++ only (#pragma cplusplus on).
 */
#include "alloc_guard.h"

extern "C" {
extern char D_004C1F58[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* allocation, char* file, int line);
}

struct I8_004598C0Val { float a; float b __attribute__((aligned(16))); float c; float d; float e; int f; int g; int h; int i; };
struct ListI8_004598C0Node {
    ListI8_004598C0Node* prev;
    ListI8_004598C0Node* next;
    I8_004598C0Val value;
};

struct ListI8_004598C0 {
    int count;
    int alloc;
};

struct ListI8_004598C0Flag {
    char c;
    ListI8_004598C0Flag() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ListI8_004598C0Flag() {}
};

struct ListI8_004598C0Holder;
extern "C" void details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_11(ListI8_004598C0Holder* holder);

struct ListI8_004598C0Holder {
    int* alloc;
    ListI8_004598C0Node* node;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ListI8_004598C0Holder()
    {
        if (node) {
            details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_11(this);
            ListI8_004598C0Node* p = node;
            if (p) {
                AllocGuard guard;
                Mem_Free(0, p, D_004C1F58, 0x64);
            }
        }
    }
};

#define DEFINE_LIST_INSERT_BEFORE8(name)                                       \
    extern "C" int name(ListI8_004598C0Node** result, ListI8_004598C0* list,                  \
                        ListI8_004598C0Node** pos, const I8_004598C0Val* value)                  \
    {                                                                         \
        ListI8_004598C0Node* n;                                                       \
        int* alloc = &list->alloc;                                            \
        ListI8_004598C0Flag flag;                                                  \
        {                                                                     \
            AllocGuard guard;                                                 \
            n = (ListI8_004598C0Node*)Mem_Alloc(0, 64, "allocator.hh", 0x5C);            \
        }                                                                     \
        ListI8_004598C0Holder h;                                                     \
        h.alloc = alloc;                                                      \
        h.node = n;                                                           \
        I8_004598C0Val* v = &h.node->value;                                              \
        if (v)                                                                \
            *v = *value;                                                      \
        ListI8_004598C0Node* p;                                                       \
        ListI8_004598C0Node* m = h.node;                                              \
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

#endif /* LIB_004598C0 */
DEFINE_LIST_INSERT_BEFORE8(std_list_deleter_TextAtom_insert)
