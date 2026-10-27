#pragma cplusplus on

#include "types.h"
#ifndef LIB_00222980
#define LIB_00222980

/*
 * Doubly-linked list insert of one int value before *pos (identical
 * template clones, one per translation unit): allocate a 12-byte node
 * under the allocator guard, hold it in a node holder while the value is
 * copied, link it in, bump the count. C++ only (#pragma cplusplus on).
 */
#include "alloc_guard.h"

extern "C" {
extern char D_0049CD60[];
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
}

struct I8_00222980Val { int w0; int w1; };
struct ListI8_00222980Node {
    ListI8_00222980Node* prev;
    ListI8_00222980Node* next;
    I8_00222980Val value;
};

struct ListI8_00222980 {
    int count;
    int alloc;
};

struct ListI8_00222980Flag {
    char c;
    ListI8_00222980Flag() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ListI8_00222980Flag() {}
};

struct ListI8_00222980Holder;
extern "C" void details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_4(ListI8_00222980Holder* holder);

struct ListI8_00222980Holder {
    int* alloc;
    ListI8_00222980Node* node;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ListI8_00222980Holder()
    {
        if (node) {
            details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_4(this);
            ListI8_00222980Node* p = node;
            if (p) {
                AllocGuard guard;
                cMemMan_Deallocate(0, p, D_0049CD60, 0x64);
            }
        }
    }
};

#define DEFINE_LIST_INSERT_BEFORE8(name)                                       \
    extern "C" int name(ListI8_00222980Node** result, ListI8_00222980* list,                  \
                        ListI8_00222980Node** pos, const I8_00222980Val* value)                  \
    {                                                                         \
        ListI8_00222980Node* n;                                                       \
        int* alloc = &list->alloc;                                            \
        ListI8_00222980Flag flag;                                                  \
        {                                                                     \
            AllocGuard guard;                                                 \
            n = (ListI8_00222980Node*)cMemMan_Allocate(0, 16, "allocator.hh", 0x5C);            \
        }                                                                     \
        ListI8_00222980Holder h;                                                     \
        h.alloc = alloc;                                                      \
        h.node = n;                                                           \
        I8_00222980Val* v = &h.node->value;                                              \
        if (v)                                                                \
            *v = *value;                                                      \
        ListI8_00222980Node* p;                                                       \
        ListI8_00222980Node* m = h.node;                                              \
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

#endif /* LIB_00222980 */
DEFINE_LIST_INSERT_BEFORE8(std_list_deleter_cSafePtr_cGOBJ_insert)
